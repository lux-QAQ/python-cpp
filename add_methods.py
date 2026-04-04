with open('src/runtime/PyObject.cpp', 'r') as f:
    text = f.read()

methods = """
PyResult<std::monostate> PyObject::__setattribute__(PyObject *attribute, PyObject *value)
{
        if (!as<PyString>(attribute)) {
                return Err(type_error("attribute name must be string, not '{}'", attribute->type()->to_string()));
        }

        if (as<PyType>(this)) { PyType::inc_global_version(); }

        auto descriptor_ = type()->lookup(attribute);

        if (descriptor_.has_value() && descriptor_->is_ok()) {
                auto *descriptor = descriptor_->unwrap();
                const auto &descriptor_set = descriptor->type()->underlying_type().__set__;
                if (descriptor_set.has_value()) {
                        return call_slot(*descriptor_set, "", descriptor, this, value);
                }
        }

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
        return Ok(std::monostate{});
}

PyResult<std::monostate> PyObject::__delattribute__(PyObject *attribute)
{
        if (!as<PyString>(attribute)) {
                return Err(type_error("attribute name must be string, not '{}'", attribute->type()->to_string()));
        }
        
        auto descriptor_ = type()->lookup(attribute);

        if (descriptor_.has_value() && descriptor_->is_ok()) {
                auto *descriptor = descriptor_->unwrap();
                const auto &descriptor_delete = descriptor->type()->underlying_type().__delete__;
                if (descriptor_delete.has_value()) {
                        return call_slot(*descriptor_delete, "", descriptor, this);
                }
        }

        return Err(attribute_error("can't delete attribute"));
}
"""

text = text.replace('PyResult<int64_t> PyObject::__hash__() const', methods + '\nPyResult<int64_t> PyObject::__hash__() const')

with open('src/runtime/PyObject.cpp', 'w') as f:
    f.write(text)

