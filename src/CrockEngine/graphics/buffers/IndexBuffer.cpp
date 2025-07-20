//
// Created by issbe on 12/05/2025.
//

#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(GLuint *data, GLuint count) : m_count(count) {
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}
void IndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}