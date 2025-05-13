//
// Created by issbe on 12/05/2025.
//

#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(GLuint *data, GLuint count) : _count(count) {
    glGenBuffers(1, &_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
}
void IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}