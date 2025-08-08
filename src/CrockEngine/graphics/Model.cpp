#include "Model.h"


Model::Model(){

}

Model::~Model(){
    
}


void Model::Init(){

}

void Model::Render(Shader shader){
    for(auto& mesh : m_meshes){
        mesh.Render(shader);
    }
}
