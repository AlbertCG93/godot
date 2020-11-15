#ifndef WORLD_H
#define WORLD_H

#include "core/reference.h"

#include <vector>

class World : public Reference {
    GDCLASS(World, Reference);

public:
    World();
    World(int x, int y);
    ~World();

    void set_value(int i, int j, uint8_t value);
    uint8_t get_value(int i, int j);

protected:
    std::vector<std::vector<uint8_t>> representation;

    static void _bind_methods();
};

#endif