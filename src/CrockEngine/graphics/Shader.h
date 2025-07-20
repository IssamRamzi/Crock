//
// Created by issbe on 11/05/2025.
//

#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>
#include "../../CrockMath/CrockMath.h"
#include "glm/glm.hpp"

class Shader {
private:
    GLuint      m_shaderID;
    const char  *m_vertexPath, *m_fragmentPath;

public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void        EnableShader();
    void        DisableShader();
    GLuint      GetShaderID();
    GLint       GetUniformLoc(const GLchar *name);


    void        SetUniform1f(const GLchar* name, float val);
    void        SetUniform2f(const GLchar* name, Vec2<float> vec);
    void        SetUniform3f(const GLchar* name, Vec3<float> vec);
    void        SetUniform4f(const GLchar* name, Vec4<float> vec);
    void        SetUniform1i(const GLchar* name, int val);
    void        SetUniform2i(const GLchar* name, Vec2<int> vec);
    void        SetUniform3i(const GLchar* name, Vec3<int> vec);
    void        SetUniform4i(const GLchar* name, Vec4<int> vec);

    void        SetUniformMat4(const GLchar *name, Matrix4<float> mat);
    void        SetUniformMat4GLM(const GLchar *name, glm::mat4 mat);
};



#endif //SHADER_H
