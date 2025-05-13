//
// Created by issbe on 11/05/2025.
//

#include "../utils/FileUtils.h"
#include "Shader.h"
#include <iostream>

Shader::Shader(const char *vertexPath, const char *fragmentPath) : _vertexPath(vertexPath), _fragmentPath(fragmentPath) {
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
    _shaderID = program;
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


Shader::~Shader() {
    glDeleteProgram(_shaderID);
}

void Shader::enableShader() {
    glUseProgram(_shaderID);
}

void Shader::disableShader() {
    glUseProgram(0);
}

GLuint Shader::getShaderID() {
    return _shaderID;
}


GLint Shader::getUniformLoc(const GLchar *name) {
    return glGetUniformLocation(_shaderID, name);
}

void Shader::setUniformMat4(const GLchar *name, Matrix4<float> mat) {
    glUniformMatrix4fv(glGetUniformLocation(_shaderID, name), 1, GL_FALSE, mat.data);
}

void Shader::setUniform1f(const GLchar* name, float val){
    glUniform1f(getUniformLoc(name), val);
}

void Shader::setUniform2f(const GLchar* name, Vec2<float> vec){
    glUniform2f(glGetUniformLocation(_shaderID, name), vec.x, vec.y);
}

void Shader::setUniform3f(const GLchar* name, Vec3<float> vec){
    glUniform3f(getUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::setUniform4f(const GLchar* name, Vec4<float> vec){
    glUniform4f(getUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}

void Shader::setUniform1i(const GLchar* name, int val){
    glUniform1i(getUniformLoc(name), val);
}

void Shader::setUniform2i(const GLchar* name, Vec2<int> vec){
    glUniform2i(getUniformLoc(name), vec.x, vec.y);
}

void Shader::setUniform3i(const GLchar* name, Vec3<int> vec){
    glUniform3i(getUniformLoc(name), vec.x, vec.y, vec.z);
}

void Shader::setUniform4i(const GLchar* name, Vec4<int> vec){
    glUniform4i(getUniformLoc(name), vec.x, vec.y, vec.z, vec.w);
}

