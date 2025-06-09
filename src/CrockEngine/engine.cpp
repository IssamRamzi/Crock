
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "graphics/Shader.h"
#include "graphics/Texture2D.h"
#include "graphics/Window.hpp"
#include "graphics/buffers/VertexArray.h"
#include "graphics/buffers/Buffer.h"
#include "graphics/buffers/IndexBuffer.h"
#include "stb_image/stb_image.h"




int main(int argc, char *argv[]) {
    srand(time(NULL));

    Window window("Crock Engine", 900, 900);
    glClearColor(1,1,1,1);


    float vertices[] = {
        // Positions        // Texture Coords
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // Bottom-left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, // Top-left
         0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // Top-right
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f  // Bottom-right
    };


    GLuint elements[] = {
        0, 1, 2,
        0, 2, 3
    };

    VertexArray VAO;
    Buffer *VBO = new Buffer(vertices, 4*5, 5);
    IndexBuffer EBO(elements, 6);

    VAO.addBuffer(VBO, 0, 3, 5 * sizeof(float), (void*)0);              // position
    VAO.addBuffer(VBO, 1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float)));  // texCoord


    Shader shader("../src/CrockEngine/shaders/basic.vert", "../src/CrockEngine/shaders/basic.frag");
    const char* wallPath = "container.jpg";
    const char* smilePath = "container.jpg";
    Texture2D wallTexture("container.jpg", TEXTURE_JPG);
    Texture2D smileTexture("awesomeface.png", TEXTURE_PNG);

    while (!window.closed()) {
        glClear(GL_COLOR_BUFFER_BIT);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        shader.enableShader();
        VAO.bind();
        EBO.bind();
        smileTexture.bind();
        wallTexture.bind(GL_TEXTURE1);
        // shader.setUniform4f("ourColor", {0.7, 0.4, 0.1, 1.0});
        shader.setUniform1i("texture1", 0);
        shader.setUniform1i("texture1", 1);

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, EBO.getCount(), GL_UNSIGNED_INT, 0);
        VAO.unbind();
        EBO.unbind();
    wallTexture.unbind();
        window.update();
    }

    return 0;
}
