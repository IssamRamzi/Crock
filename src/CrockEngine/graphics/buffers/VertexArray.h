//
// Created by issbe on 12/05/2025.
//

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

#include "Buffer.h"

class VertexArray {
private:
    GLuint                  m_arrayID;

    std::vector<Buffer*>    m_buffers;

public:
    VertexArray();
    ~VertexArray();

    void                    AddBuffer(Buffer* buffer, GLuint index, GLint componentsCount, GLint stride, const void* offset);
    void                    Bind();
    void                    Unbind();
};



#endif //VERTEXBUFFER_H
