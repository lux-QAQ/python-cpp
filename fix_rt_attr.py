with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    text = f.read()

text = text.replace('shape->lookup(name)', 'shape->lookup(py::PyString::intern(name))')

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.write(text)

