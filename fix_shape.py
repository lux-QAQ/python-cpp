import re

with open('src/runtime/shape/Shape.hpp', 'r') as f:
    text = f.read()

text = text.replace('while (current && current->m_parent) {', 'while (current) {')

with open('src/runtime/shape/Shape.hpp', 'w') as f:
    f.write(text)

