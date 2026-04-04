import re

with open('src/runtime/shape/Shape.hpp', 'r') as f:
    text = f.read()

text = text.replace('size_t slot_count() const { return m_parent ? m_offset + 1 : 0; }', 'size_t slot_count() const { return m_offset + 1; }')

with open('src/runtime/shape/Shape.hpp', 'w') as f:
    f.write(text)

