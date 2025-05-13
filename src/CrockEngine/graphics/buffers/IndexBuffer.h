//
// Created by issbe on 12/05/2025.
//

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include "glad/glad.h"


class IndexBuffer {
    GLuint _bufferID;
    GLuint _count;
public:
    IndexBuffer(GLuint *data, GLuint count);

    void bind();
    void unbind();
    inline GLuint getCount(){return _count;}
};



#endif //INDEXBUFFER_H
