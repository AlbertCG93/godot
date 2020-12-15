#ifndef ATLAS_WORLD_GENERATOR_H
#define ATLAS_WORLD_GENERATOR_H

#include "core/reference.h"

#include "modules/atlas/atlas_world.h"

class Atlas_WorldGenerator : public Reference {
    GDCLASS(Atlas_WorldGenerator, Reference);

public:
    Atlas_WorldGenerator();
    ~Atlas_WorldGenerator();

    void initialize(int octaves, float period, float persistence, float lacunarity);

    Atlas_World* generate_world(int x, int y, int h);

protected:
    int octaves;

    float period;

    float persistence;
    float lacunarity;

    Atlas_World* world;
    
    void generate_graph();

    static void _bind_methods();
};

#endif
