#include "../Model.h"
#include <glm/gtc/matrix_transform.hpp>


class Cube : public Model{
public:

    glm::vec3 m_position;
    glm::vec3 m_size;

    Cube(glm::vec3 pos, glm::vec3 size) : m_position(pos), m_size(size){

    }

    void Init(){
        int noVertices = 36;

        float vertices[] = {
            // position            texcoord
            -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,   1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,   1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,   1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,   0.0f, 1.0f
        };

        std::vector<GLuint> indices(noVertices);
        for (int i = 0; i < noVertices; i++) {
            indices[i] = i;
        }

        Texture tex0("wall.jpg");
        tex0.Bind(0);
        

        m_meshes.push_back(Mesh(Vertex::GenVertexList(vertices, noVertices), indices, {tex0}));
    }

    void Render(Shader shader){
        glm::mat4 model(1.0);
        model = glm::translate(model, m_position);
        model = glm::scale(model, m_size);
        model = glm::rotate(model,(float) glm::radians(-55.0) * (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.5f));
        shader.SetUniformMat4GLM("model", model);

        Model::Render(shader);
    }
};