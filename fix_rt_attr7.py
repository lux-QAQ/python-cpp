with open('src/runtime/export/rt_attr.cpp', 'r') as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if 'shape->lookup' in line:
        if 'getattr_fast' in "".join(lines[:i]):
            lines[i] = '                if (auto offset = shape->lookup(name)) { return b_obj->slots()[*offset]; }\n'
        else:
            lines[i] = '                if (auto offset = shape->lookup(py::PyString::intern(name))) { return b_obj->slots()[*offset]; }\n'

with open('src/runtime/export/rt_attr.cpp', 'w') as f:
    f.writelines(lines)

