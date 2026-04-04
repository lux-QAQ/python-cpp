import re
with open('src/runtime/PyModule.hpp', 'r') as f:
    text = f.read()

# Remove duplicate declarations
text = re.sub(r'\tPyResult<std::monostate> __setattribute__\(PyObject \*attribute, PyObject \*value\);\n', '', text)
text = re.sub(r'\tPyResult<std::monostate> __delattribute__\(PyObject \*attribute\);\n', '', text)

# Add them back exactly once
decl = 'PyResult<PyObject *> __getattribute__(PyObject *attribute) const;'
new_decl = decl + '\n\tPyResult<std::monostate> __setattribute__(PyObject *attribute, PyObject *value);\n\tPyResult<std::monostate> __delattribute__(PyObject *attribute);'
text = text.replace(decl, new_decl)

with open('src/runtime/PyModule.hpp', 'w') as f:
    f.write(text)

