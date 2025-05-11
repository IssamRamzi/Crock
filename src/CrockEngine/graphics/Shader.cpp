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
    _shader = program;
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


Shader::~Shader() {
    glDeleteProgram(_shader);
}

void Shader::enableShader() {
    glUseProgram(_shader);
}

void Shader::disableShader() {
    glUseProgram(0);
}

GLuint Shader::getShader() {
    return _shader;
}