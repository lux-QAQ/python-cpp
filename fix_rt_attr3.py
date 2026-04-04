with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    text = f.read()

text = text.replace('shape->lookup(name)', 'shape->lookup(py::PyString::intern(name))')
text = text.replace('shape->lookup(py::PyString::intern(py::PyString::intern(name)))', 'shape->lookup(py::PyString::intern(name))')
text = text.replace('shape->lookup(py::PyString::intern(name)) { return b_obj->slots()[*offset]; }', 'shape->lookup(name) { return b_obj->slots()[*offset]; }')

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.write(text)

