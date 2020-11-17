#ifndef ATLAS_WORLD_H
#define ATLAS_WORLD_H

#include "core/reference.h"

#include <vector>

class Atlas_World : public Reference {
    GDCLASS(Atlas_World, Reference);

public:
    Atlas_World();
    ~Atlas_World();

    void initialize(int x, int y);

    int get_size_x();
    int get_size_y();

    void set_value(int i, int j, uint8_t value);
    uint8_t get_value(int i, int j);

protected:
    std::vector<std::vector<uint8_t>> representation;

    static void _bind_methods();
};

#endif