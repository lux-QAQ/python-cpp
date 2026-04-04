import re

with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    text = f.read()

# Replace all
text = re.sub(r'shape->lookup\([^)]+\)', 'shape->lookup(name)', text)
text = text.replace('shape->lookup(name)', 'shape->lookup(py::PyString::intern(name))', 1)

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.write(text)

