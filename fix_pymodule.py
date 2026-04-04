import re

with open('src/runtime/PyModule.cpp', 'r') as f:
    text = f.read()

# Replace __getattribute__ in PyModule
old_get = '''PyResult<PyObject *> PyModule::__getattribute__(PyObject *attribute) const
{
        auto attr = PyObject::__getattribute__(attribute);
        if (attr.is_ok() || attr.unwrap_err()->type() != AttributeError::class_type()) { return attr; }'''

new_get = '''PyResult<PyObject *> PyModule::__getattribute__(PyObject *attribute) const
{
        if (m_dict) {
                auto it = m_dict->map().find(RtValue::from_ptr(attribute));
                if (it != m_dict->map().end()) {
                        return PyObject::from(it->second);
                }
        }
        
        auto attr = PyObject::__getattribute__(attribute);
        if (attr.is_ok() || attr.unwrap_err()->type() != AttributeError::class_type()) { return attr; }'''

text = text.replace(old_get, new_get)

# Add __setattribute__ and __delattribute__
additional_methods = '''
PyResult<std::monostate> PyModule::__setattribute__(PyObject *attribute, PyObject *value)
{
        if (!as<PyString>(attribute)) {
                return Err(type_error("attribute name must be string"));
        }
        if (m_dict) {
                m_dict->insert(RtValue::from_ptr(attribute), value);
                // invalidate cache
                m_dict_version = s_global_version.fetch_add(1, std::memory_order_relaxed);
                if (auto *s = as<PyString>(attribute)) m_key_versions.bump(s->value());
        }
        return Ok(std::monostate{});
}

PyResult<std::monostate> PyModule::__delattribute__(PyObject *attribute)
{
        if (!as<PyString>(attribute)) {
                return Err(type_error("attribute name must be string"));
        }
        if (m_dict) {
                if (auto it = m_dict->map().find(RtValue::from_ptr(attribute)); it != m_dict->map().end()) {
                        m_dict->map().erase(it);
                        m_dict_version = s_global_version.fetch_add(1, std::memory_order_relaxed);
                        if (auto *s = as<PyString>(attribute)) m_key_versions.bump(s->value());
                        return Ok(std::monostate{});
                }
        }
        return Err(attribute_error("can't delete attribute"));
}
'''
if "PyModule::__setattribute__" not in text:
    text = text.replace('std::function<std::unique_ptr<TypePrototype>()> PyModule::type_factory()', additional_methods + '\nstd::function<std::unique_ptr<TypePrototype>()> PyModule::type_factory()')

with open('src/runtime/PyModule.cpp', 'w') as f:
    f.write(text)

