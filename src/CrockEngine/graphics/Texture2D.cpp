//
// Created by issbe on 09/06/2025.
//

#include "Texture2D.h"
#include "../utils/Utils.h"
#include <iostream>


Texture2D::Texture2D(const char *m_path) {
    std::string m_type = Utils::getFileExt(m_path).c_str();
    if (m_type == "png")
        this->m_type = TEXTURE_PNG;
    if (m_type == "jpg")
        this->m_type = TEXTURE_JPG;

    stbi_set_flip_vertically_on_load(true);
    m_bytes = stbi_load(m_path, &m_height, &m_width, &m_numColCh, 0);
    if (m_bytes) {
        glGenTextures(1, &m_texture);

        Bind();

        // Texture Settings
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        if (this->m_type == TEXTURE_JPG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_bytes);
            glGenerateMipmap(GL_TEXTURE_2D);
        }else if (this->m_type == TEXTURE_PNG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_bytes);
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        stbi_image_free(m_bytes); // ! temp
        Unbind();

        std::cout << "Texture: " << m_path << ", loaded succesfully." << std::endl;
    }
    else {
        std::cout << "Failed loading the " << m_path << " m_texture." << std::endl;
    }


}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_texture);
}

void Texture2D::Bind(GLenum unit) {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Texture2D::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
