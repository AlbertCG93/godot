#ifndef WORLD_GENERATOR_H
#define WORLD_GENERATOR_H

#include "core/reference.h"

#include "modules/atlas/world.h"

class WorldGenerator : public Reference {
    GDCLASS(WorldGenerator, Reference);

public:
    WorldGenerator();
    ~WorldGenerator();

    Ref<World> generate_world(int x, int y, int h);

protected:
    static void _bind_methods();
};

#endif