#ifndef ATLAS_WORLD_H
#define ATLAS_WORLD_H

#include "modules/atlas/atlas_cell.h"

#include "core/object.h"

#include <vector>

class Atlas_World : public Object {
    GDCLASS(Atlas_World, Object);

public:
    Atlas_World();
    ~Atlas_World();

    void initialize(int x, int y);

    int get_size_x();
    int get_size_y();

    Atlas_Cell* get_cell(int i, int j);

protected:
    std::vector<std::vector<Atlas_Cell>> world;

    static void _bind_methods();
};

#endif