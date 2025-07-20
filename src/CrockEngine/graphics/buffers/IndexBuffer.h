//
// Created by issbe on 12/05/2025.
//

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include "glad/glad.h"


class IndexBuffer {
    GLuint          m_bufferID;
    GLuint          m_count;
public:
    IndexBuffer(GLuint *data, GLuint count);

    void            Bind();
    void            Unbind();
    inline GLuint   GetCount(){return m_count;}
};



#endif //INDEXBUFFER_H
