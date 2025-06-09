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
    GLuint _arrayID;

    std::vector<Buffer*> _buffers;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(Buffer* buffer, GLuint index, GLint componentsCount, GLint stride, const void* offset);
    void bind();
    void unbind();
};



#endif //VERTEXBUFFER_H
