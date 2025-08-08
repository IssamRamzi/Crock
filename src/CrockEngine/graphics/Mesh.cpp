#include "Mesh.h"

std::vector<Vertex> Vertex::GenVertexList(float *vertices, int nbVertices){
    std::vector<Vertex> result(nbVertices);
    
    for (int i = 0; i < nbVertices; ++i) {
        int offset = i * 5;
        result[i].position = glm::vec3(
            vertices[offset + 0],
            vertices[offset + 1],
            vertices[offset + 2]
        );
        result[i].texCoord = glm::vec2(
            vertices[offset + 3],
            vertices[offset + 4]
        );
    }
    return result;
}

Mesh::~Mesh(){
    delete VAO;
    delete VBO;
    delete EBO;
}


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint>indices, std::vector<Texture> textures) : m_vertices(vertices), m_textures(textures), 
m_indices(indices) {
    Setup();
}

void Mesh::Render(Shader shader){
    for(int i =0; i < m_textures.size(); i++){
        // shader.setUniform
        m_textures[i].Bind(i); 
    }

    VAO->Bind();
    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);
    VAO->Unbind();

    glActiveTexture(GL_TEXTURE0);
}

void Mesh::Setup(){
    // VAO
    VAO = new VertexArray();    

    // VBO
    GLfloat* vertexData = reinterpret_cast<GLfloat*>(&m_vertices[0]);
    GLsizei floatCount = (m_vertices.size() * sizeof(Vertex)) / sizeof(GLfloat);
    GLuint componentCount = sizeof(Vertex) / sizeof(GLfloat);
    VBO = new Buffer(vertexData, floatCount, componentCount);

    VAO->AddBuffer(VBO, 0, 3, 5 * sizeof(float), 0); // position
	VAO->AddBuffer(VBO, 1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float))); // tex coords
    // EBO
    GLuint* indicesData = reinterpret_cast<GLuint*>(&m_indices[0]);
    EBO = new IndexBuffer(indicesData, m_indices.size());
}