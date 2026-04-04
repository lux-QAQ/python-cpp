with open('src/runtime/PyObject.cpp', 'r') as f:
    text = f.read()

text = text.replace('m_shape->lookup(name)', 'm_shape->lookup(as<PyString>(name))')
text = text.replace('new Shape(nullptr, attribute->to_string(), 0)', 'new Shape(nullptr, as<PyString>(attribute), 0)')

with open('src/runtime/PyObject.cpp', 'w') as f:
    f.write(text)

with open('src/runtime/PySuper.cpp', 'r') as f:
    text = f.read()
text = text.replace('shape->lookup(name)', 'shape->lookup(as<PyString>(name))')
with open('src/runtime/PySuper.cpp', 'w') as f:
    f.write(text)

