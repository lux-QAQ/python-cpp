import re
with open('src/runtime/PyObject.cpp', 'r') as f:
    text = f.read()

# 1. remove visitor
text = re.sub(r'\s*if \(m_attributes\) \{ visitor\.visit\(\*m_attributes\); \}', '', text)

# 2. replace dict usages
old_getattr = r'''\s*if \(m_attributes\) \{
\s*const auto &dict = m_attributes->map\(\);
\s*if \(auto it = dict\.find\(name\); it != dict\.end\(\)\) \{ return PyObject::from\(it->second\); \}
\s*// FIXME: we should abort here if PyDict returns an exception that is not an
\s*// AttributeError
\s*\}'''
new_getattr = '''
        if (m_shape) {
                if (auto offset = m_shape->lookup(name->to_string())) { return PyObject::from(m_slots[*offset]); }
        }'''
text = re.sub(old_getattr, new_getattr, text)

old_getattr2 = r'''\s*if \(m_attributes\) \{
\s*const auto &dict = m_attributes->map\(\);
\s*if \(auto it = dict\.find\(name\); it != dict\.end\(\)\) \{ return PyObject::from\(it->second\); \}
\s*\}'''
text = re.sub(old_getattr2, new_getattr, text)

# 3. set attribute
old_setattr = r'''\s*// \[核心优化\]：延迟分配 m_attributes
\s*if \(!m_attributes\) \{
\s*auto dict_res = PyDict::create\(\);
\s*if \(dict_res\.is_err\(\)\) return Err\(dict_res\.unwrap_err\(\)\);
\s*m_attributes = dict_res\.unwrap\(\);
\s*\}

\s*return m_attributes->__setitem__\(attribute, value\);'''

new_setattr = '''
        if (!m_shape) {
                m_shape = new Shape(nullptr, attribute->to_string(), 0);
                m_slots.push_back(value);
                return Ok(std::monostate{});
        }
        if (auto offset = m_shape->lookup(attribute->to_string())) {
                m_slots[*offset] = value;
                return Ok(std::monostate{});
        }
        m_shape = m_shape->transition(attribute->to_string());
        m_slots.push_back(value);
        return Ok(std::monostate{});'''
text = re.sub(old_setattr, new_setattr, text)

# 4. del attribute
old_delattr = r'''\s*if \(!m_attributes\) \{
\s*if \(descriptor_\.has_value\(\) && descriptor_->is_ok\(\)\) \{
\s*return Err\(attribute_error\(
\s*"'\{\}' object attribute '\{\}' is read-only", type\(\)->name\(\), attribute->to_string\(\)\)\);
\s*\} else \{
\s*return Err\(attribute_error\(
\s*"'\{\}' object has no attribute '\{\}'", type\(\)->name\(\), attribute->to_string\(\)\)\);
\s*\}
\s*\}

\s*m_attributes->remove\(attribute\);'''

new_delattr = '''
        // TODO: support delattr in shape
        return Err(attribute_error("can't delete attribute"));'''
text = re.sub(old_delattr, new_delattr, text)

# Include Shape header if not present
if '#include "shape/Shape.hpp"' not in text:
    text = '#include "shape/Shape.hpp"\n' + text

with open('src/runtime/PyObject.cpp', 'w') as f:
    f.write(text)

