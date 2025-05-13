//
// Created by issbe on 11/05/2025.
//

#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>
#include "../../CrockMath/CrockMath.h"

class Shader {
private:
    GLuint _shaderID;

    const char *_vertexPath, *_fragmentPath;

public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void enableShader();
    void disableShader();
    GLuint getShaderID();

    GLint getUniformLoc(const GLchar *name);

    void setUniformMat4(const GLchar *name, Matrix4<float> mat);
    void setUniform1f(const GLchar* name, float val);
    void setUniform2f(const GLchar* name, Vec2<float> vec);
    void setUniform3f(const GLchar* name, Vec3<float> vec);
    void setUniform4f(const GLchar* name, Vec4<float> vec);
    void setUniform1i(const GLchar* name, int val);
    void setUniform2i(const GLchar* name, Vec2<int> vec);
    void setUniform3i(const GLchar* name, Vec3<int> vec);
    void setUniform4i(const GLchar* name, Vec4<int> vec);

};



#endif //SHADER_H
