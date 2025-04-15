#pragma once

#include <core/Model.h>

class GLModel : public Model {
public:
    void loadMesh(const MeshData& data) override;
};