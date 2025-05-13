//
// Created by issbe on 12/05/2025.
//

#include "Buffer.h"

Buffer::Buffer(GLfloat *data, GLsizei count, GLuint countComponents) : _countComponents(countComponents) {
    glGenBuffers(1, &_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}
void Buffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}