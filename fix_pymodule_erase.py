with open('src/runtime/PyModule.cpp', 'r') as f:
    text = f.read()

text = text.replace('m_dict->map().erase(it);', 'm_dict->remove(attribute);')

with open('src/runtime/PyModule.cpp', 'w') as f:
    f.write(text)
