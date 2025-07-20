//
// Created by issbe on 12/05/2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include "glad/glad.h"


class Buffer {
private:
    GLuint          m_bufferID;
    GLuint          m_countComponents;

public:
    Buffer(GLfloat *data, GLsizei count, GLuint countComponents);

    void            Bind();
    void            Unbind();
    inline GLuint   GetCountComponent(){return m_countComponents;}
};



#endif //BUFFER_H
