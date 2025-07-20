//
// Created by issbe on 09/06/2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "stb_image/stb_image.h"


enum TextureType {
    TEXTURE_PNG,
    TEXTURE_JPG
};


class Texture2D {
public:
    Texture2D(const char* m_path);
    ~Texture2D();

    TextureType     m_type;
    GLuint          m_texture;
private:
    char*           m_path;
    unsigned char*  m_bytes;
    int             m_height, m_width, m_numColCh;

public:
    void            Bind(GLenum unit = GL_TEXTURE0);
    void            Unbind();

};



#endif //TEXTURE_H
