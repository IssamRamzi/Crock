//
// Created by issbe on 11/05/2025.
//

#include "../utils/FileUtils.h"
#include "Shader.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const char *vertexPath, const char *fragmentPath) : m_vertexPath(vertexPath), m_fragmentPath(fragmentPath) {
    std::string v = readFile(vertexPath);
    v.push_back('\0');
    std::string f = readFile(fragmentPath);
    f.push_back('\0');
    const char* vertexCode = v.c_str();
    const char* fragmentCode = f.c_str();


    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    GLint success = 0;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
        char *infoLog = (char *)malloc(length);
        glGetShaderInfoLog(vertex, length, &length, &infoLog[0]);
        std::cout << "Failed to compile vertex shader : " <<  infoLog << std::endl;
        glDeleteShader(vertex);
        return;
    }

    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    success = 0;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
        char *infoLog = (char *)malloc(length);
        glGetShaderInfoLog(fragment, length, &length, &infoLog[0]);
        std::cout << "Failed to compile fragment shader : " <<  infoLog << std::endl;
        glDeleteShader(fragment);
        return;
    }

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glValidateProgram(program);
    m_shaderID = program;
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


Shader::~Shader() {
    glDeleteProgram(m_shaderID);
}

void Shader::EnableShader() {
    glUseProgram(m_shaderID);
}

void Shader::DisableShader() {
    glUseProgram(0);
}

GLuint Shader::GetShaderID() {
    return m_shaderID;
}

GLint Shader::GetUniformLoc(const GLchar *name) {
    return glGetUniformLocation(m_shaderID, name);
}

void Shader::SetUniformMat4(const GLchar *name, Matrix4<float> mat) {
    glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name), 1, GL_FALSE, mat.data);
}

void Shader::SetUniformMat4GLM(const GLchar *name, glm::mat4 mat) {
    glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetUniform1f(const GLchar* name, float val){
    glUniform1f(GetUniformLoc(name), val);
}

void Shader::SetUniform2f(const GLchar* name, Vec2<float> vec){
    glUniform2f(glGetUniformLocation(m_shaderID, name), vec.x, vec.y);
}

void Shader::SetUniform3f(const GLchar* name, Vec3<float> vec){
    glUniform3f(GetUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::SetUniform4f(const GLchar* name, Vec4<float> vec){
    glUniform4f(GetUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}

void Shader::SetUniform1i(const GLchar* name, int val){
    glUniform1i(GetUniformLoc(name), val);
}

void Shader::SetUniform2i(const GLchar* name, Vec2<int> vec){
    glUniform2i(GetUniformLoc(name), vec.x, vec.y);
}

void Shader::SetUniform3i(const GLchar* name, Vec3<int> vec){
    glUniform3i(GetUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::SetUniform4i(const GLchar* name, Vec4<int> vec){
    glUniform4i(GetUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}

