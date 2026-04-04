with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    text = f.read()

# Only replace the first occurrence (line 59)
text = text.replace('shape->lookup(name)', 'shape->lookup(py::PyString::intern(name))', 1)

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.write(text)

