//
// Created by issbe on 09/06/2025.
//

#include "Texture2D.h"

#include <iostream>


Texture2D::Texture2D(const char *path, TextureType type) {
    this->type = type;
    bytes = stbi_load(path, &height, &width, &numColCh, 0);
    // stbi_set_flip_vertically_on_load(true);
    if (bytes) {
        glGenTextures(1, &texture);

        bind();

        // Texture Settings
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        if (type == TEXTURE_JPG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
            glGenerateMipmap(GL_TEXTURE_2D);
        }else if (type == TEXTURE_PNG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
            glGenerateMipmap(GL_TEXTURE_2D);
        }


        stbi_image_free(bytes); // ! temp
        unbind();

        std::cout << "Texture: " << path << ", loaded succesfully." << std::endl;
    }
    else {
        std::cout << "Failed loading the " << path << " texture." << std::endl;
    }


}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &texture);
}

void Texture2D::bind(GLenum unit) {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
