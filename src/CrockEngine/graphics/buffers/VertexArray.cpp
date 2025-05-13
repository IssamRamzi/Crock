//
// Created by issbe on 12/05/2025.
//

#include "VertexArray.h"


VertexArray::VertexArray(){
    glGenVertexArrays(1, &_arrayID);
}

VertexArray::~VertexArray(){
    for(int i =0; i < _buffers.size(); i++){
        delete _buffers[i];
    }
}

void VertexArray::addBuffer(Buffer *buffer, GLuint index){
    bind();
    buffer->bind();

    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getCountComponent(), GL_FLOAT, GL_FALSE, 0, 0);
    _buffers.emplace_back(buffer);

    buffer->unbind();
    unbind();
}

void VertexArray::bind(){
    glBindVertexArray(_arrayID);
}

void VertexArray::unbind(){
    glBindVertexArray(0);
}