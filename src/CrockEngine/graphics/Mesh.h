#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include "buffers/IndexBuffer.h"
#include "buffers/VertexArray.h"
#include "Texture.h"
#include "Shader.h"

struct Vertex
{

    glm::vec3 position;
    glm::vec2 texCoord;
    static std::vector<Vertex> GenVertexList(GLfloat *vertices, int nbVertices);
} ;

typedef struct Vertex Vertex;


class Mesh {
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint>indices, std::vector<Texture> textures);
    ~Mesh();

    void Render(Shader shader);

    inline std::vector<Vertex> GetVertices(){return m_vertices;}
    inline std::vector<GLuint> GetIndices(){return m_indices;}
    inline std::vector<Texture> GetTextures(){return m_textures;}

    inline VertexArray* GetVAO(){return VAO;}
    inline Buffer* GetVBO(){return VBO;}
    inline IndexBuffer* GetEBO(){return EBO;}

private:
  void Setup();

private:
  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;
  std::vector<Texture> m_textures;

  VertexArray* VAO;
  Buffer* VBO;
  IndexBuffer* EBO;  
};
