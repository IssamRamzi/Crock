//
// Created by issbe on 12/05/2025.
//

#include "Buffer.h"

Buffer::Buffer(GLfloat *data, GLsizei count, GLuint countComponents) : m_countComponents(countComponents) {
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}
void Buffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

