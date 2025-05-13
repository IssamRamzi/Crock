//
// Created by issbe on 12/05/2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include "glad/glad.h"


class Buffer {
private:
    GLuint _bufferID;
    GLuint _countComponents;

public:
    Buffer(GLfloat *data, GLsizei count, GLuint countComponents);

    void bind();
    void unbind();
    inline GLuint getCountComponent(){return _countComponents;}
};



#endif //BUFFER_H
