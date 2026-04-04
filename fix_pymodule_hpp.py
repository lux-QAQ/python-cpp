with open('src/runtime/PyModule.hpp', 'r') as f:
    text = f.read()

decl = 'PyResult<PyObject *> __getattribute__(PyObject *attribute) const;'
new_decl = decl + '\n\tPyResult<std::monostate> __setattribute__(PyObject *attribute, PyObject *value);\n\tPyResult<std::monostate> __delattribute__(PyObject *attribute);'

text = text.replace(decl, new_decl)

with open('src/runtime/PyModule.hpp', 'w') as f:
    f.write(text)

