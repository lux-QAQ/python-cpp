with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    text = f.read()

text = text.replace('py::PyObject *name_obj)\n{', 'py::PyObject *name_obj)\n{')
text = text.replace('shape->lookup(name)', 'shape->lookup(static_cast<py::PyString*>(name_obj))')

# In rt_getattr, name is const char*
text = text.replace('shape->lookup(static_cast<py::PyString*>(name_obj))', 'shape->lookup(py::PyString::intern(name))', 1)

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.write(text)

