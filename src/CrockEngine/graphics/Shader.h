//
// Created by issbe on 11/05/2025.
//

#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>

class Shader {
private:
    GLuint _shader;

    const char *_vertexPath, *_fragmentPath;

public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void enableShader();
    void disableShader();
    GLuint getShader();
};



#endif //SHADER_H
