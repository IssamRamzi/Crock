#include "Mesh.h"

class Model{
public:
    Model();
    ~Model();

    void Render(Shader shader);
    void Init();

protected:
    std::vector<Mesh> m_meshes;
};