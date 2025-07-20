//
// Created by issbe on 12/05/2025.
//

#include "VertexArray.h"


VertexArray::VertexArray(){
    glGenVertexArrays(1, &m_arrayID);
}

VertexArray::~VertexArray(){
    
}

void VertexArray::AddBuffer(Buffer *buffer, GLuint index, GLint componentsCount, GLint stride, const void* offset){
    Bind();
    buffer->Bind();

    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, componentsCount, GL_FLOAT, GL_FALSE, stride, offset);
    m_buffers.emplace_back(buffer);

    buffer->Unbind();
    Unbind();
}

void VertexArray::Bind(){
    glBindVertexArray(m_arrayID);
}

void VertexArray::Unbind(){
    glBindVertexArray(0);
}