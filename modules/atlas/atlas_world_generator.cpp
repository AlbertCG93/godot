#include "modules/atlas/atlas_world_generator.h"

#include "core/os/os.h"
#include "modules/opensimplex/open_simplex_noise.h"

Atlas_WorldGenerator::Atlas_WorldGenerator() {
    world = new Atlas_World();
}

Atlas_WorldGenerator::~Atlas_WorldGenerator() {
    delete world;
}

void Atlas_WorldGenerator::initialize(int octaves, float period, float persistence, float lacunarity) {
    this->octaves = octaves;
    this->period = period;
    this->persistence = persistence;
    this->lacunarity = lacunarity;
}

Atlas_World* Atlas_WorldGenerator::generate_world(int x, int y, int h) {
    world->initialize(x, y);

    OpenSimplexNoise noise_generator;

    double seed = OS::get_singleton()->get_unix_time();
    noise_generator.set_seed((int) seed);

    noise_generator.set_octaves(octaves);
    noise_generator.set_period(period * (float) x);
    noise_generator.set_persistence(persistence);
    noise_generator.set_lacunarity(lacunarity);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            float value = noise_generator.get_noise_2d(i, j);
            value = h * 0.5 * (1.0 + value);

            world->set_value(i, j, (uint8_t) value);
        }
    }

	return world;
}

void Atlas_WorldGenerator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "octaves", "period", "persistence", "lacunarity"), &Atlas_WorldGenerator::initialize);
    ClassDB::bind_method(D_METHOD("generate_world", "x", "y", "h"), &Atlas_WorldGenerator::generate_world);
}
