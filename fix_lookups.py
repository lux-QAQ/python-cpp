import os
import re

files = [
    'src/runtime/PySuper.cpp',
    'src/runtime/PyObject.cpp',
    'src/runtime/export/rt_attr.cpp',
    'src/runtime/export/rt_func.cpp',
    'src/runtime/export/cache/rt_method_cache.cpp'
]

for fpath in files:
    with open(fpath, 'r') as f:
        text = f.read()

    # match shape->lookup(...)
    text = text.replace('shape->lookup(name->to_string())', 'shape->lookup(name)')
    text = text.replace('m_shape->lookup(name->to_string())', 'm_shape->lookup(name)')
    text = text.replace('m_shape->lookup(attribute->to_string())', 'm_shape->lookup(as<PyString>(attribute))')
    text = text.replace('shape->lookup(attr_name->to_string())', 'shape->lookup(attr_name)')
    text = text.replace('shape->lookup(interned_name->to_string())', 'shape->lookup(interned_name)')

    # also check shape->transition
    text = text.replace('shape->transition(attribute->to_string())', 'shape->transition(as<PyString>(attribute))')
    text = text.replace('m_shape->transition(attribute->to_string())', 'm_shape->transition(as<PyString>(attribute))')
    text = text.replace('shape->transition(name->to_string())', 'shape->transition(name)')

    with open(fpath, 'w') as f:
        f.write(text)

