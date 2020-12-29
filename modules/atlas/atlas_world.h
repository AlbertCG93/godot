#ifndef ATLAS_WORLD_H
#define ATLAS_WORLD_H

#include "modules/atlas/atlas_cell.h"

#include "core/array.h"
#include "core/object.h"

#include <vector>

class Atlas_World : public Object {
    GDCLASS(Atlas_World, Object);

public:
    Atlas_World();
    ~Atlas_World();

    void initialize(uint16_t x, uint16_t y);

    uint16_t get_size_x();
    uint16_t get_size_y();

    Atlas_Cell* get_cell(uint16_t i, uint16_t j);
    Atlas_Cell* get_cell(uint32_t hash);

    uint8_t get_cell_height(uint16_t i, uint16_t j);

protected:
    std::vector<std::vector<Atlas_Cell>>* world;

    static void _bind_methods();

    friend class Atlas_WorldGenerator;
};

#endif