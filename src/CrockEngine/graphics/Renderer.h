//
// Created by issbe on 12/05/2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "Shader.h"
#include "buffers/Buffer.h"


class Renderer {
private:
    Buffer vao;
    Buffer vbo;

    Shader shader;
    Matrix4<float> projection;




public:
};



#endif //RENDERER_H
