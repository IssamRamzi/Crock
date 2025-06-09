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
    Texture2D(const char* path, TextureType type);
    ~Texture2D();

    TextureType type;
    GLuint texture;
private:
    char* path;
    unsigned char* bytes;
    int height, width, numColCh;

public:
    void bind(GLenum unit = GL_TEXTURE0);
    void unbind();

};



#endif //TEXTURE_H
