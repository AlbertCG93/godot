#include "modules/atlas/atlas_world_generator.h"

#include "core/os/os.h"
#include "modules/opensimplex/open_simplex_noise.h"

Atlas_WorldGenerator::Atlas_WorldGenerator() {

}

Atlas_WorldGenerator::~Atlas_WorldGenerator() {

}

Ref<Atlas_World> Atlas_WorldGenerator::generate_world(int x, int y, int h) {
    Atlas_World world;
    world.initialize(x, y);

    OpenSimplexNoise noise_generator;
    double seed = OS::get_singleton()->get_unix_time();
    noise_generator.set_seed((int) seed);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            float value = noise_generator.get_noise_2d((float) i, (float) j);
            value = h * 0.5 * (1.0 + value);

            world.set_value(i, j, (uint8_t) value);
        }
    }

    return Ref<Atlas_World>(&world);
}

void Atlas_WorldGenerator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("generate_world", "x", "y", "h"), &Atlas_WorldGenerator::generate_world);
}