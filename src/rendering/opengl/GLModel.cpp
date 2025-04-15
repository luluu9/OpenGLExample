#include "GLModel.h"
#include <GL/glew.h>
#include <iostream>

void GLModel::loadMesh(const MeshData& data) {
    Model::loadMesh(data);
  
    std::cout << "GLModel: Loaded mesh with " << data.vertices.size() 
              << " vertices and " << data.indices.size() << " indices." << std::endl;
}