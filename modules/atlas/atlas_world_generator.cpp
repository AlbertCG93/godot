#include "modules/atlas/atlas_world_generator.h"

#include "modules/atlas/atlas_astar.h"

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

Atlas_World* Atlas_WorldGenerator::generate_world(uint16_t x, uint16_t y, uint8_t h) {
    world->initialize(x, y);

    OpenSimplexNoise noise_generator;

    double seed = OS::get_singleton()->get_unix_time();
    noise_generator.set_seed((int) seed);

    noise_generator.set_octaves(octaves);
    noise_generator.set_period(period * (float) x);
    noise_generator.set_persistence(persistence);
    noise_generator.set_lacunarity(lacunarity);

    std::vector<std::vector<Atlas_Cell>>* world_data = world->world;
    for (uint16_t i = 0; i < x; ++i) {
        world_data->push_back(std::vector<Atlas_Cell>());

        for (uint16_t j = 0; j < y; ++j) {
            float value = noise_generator.get_noise_2d(i, j);
            value = h * 0.5 * (1.0 + value);

            (*world_data)[i].push_back(Atlas_Cell(i, j, (uint8_t) value));
        }
    }

	//OS::get_singleton()->print("dubby dop");

    generate_graph();

	return world;
}

void Atlas_WorldGenerator::generate_graph() {
    uint16_t size_x = world->get_size_x();
    uint16_t size_y = world->get_size_y();

    for (uint16_t i = 0; i < size_x; ++i) {
        for (uint16_t j = 0; j < size_y; ++j) {
            Atlas_Cell* cell = world->get_cell(i, j);
            
            for (uint16_t k = 0; k < Atlas_Cell_Constants::CELL_ADJACENCY_SIZE; ++k) {
                uint16_t ii = i + Atlas_Cell_Constants::CELL_ADJACENCY_X[k];
                uint16_t jj = j + Atlas_Cell_Constants::CELL_ADJACENCY_Y[k];

                if ((ii < 0) || (ii > size_x - 1)) {
                    continue;
                }

                if ((jj < 0) || (jj > size_y - 1)) {
                    continue;
                }

                Atlas_Cell* neighbor = world->get_cell(ii, jj);
                if (abs(cell->get_height() - neighbor->get_height()) > 1.0 ) {
					continue;
                }

				cell->get_neighbors().push_back(Atlas_Cell::calculate_hash(ii, jj));
            }
        }
    }
}

Array Atlas_WorldGenerator::calculate_path(uint16_t origin_x, uint16_t origin_y, uint16_t destination_x, uint16_t destination_y) {
    Atlas_AStar a_star (world);

    return a_star.solve(origin_x, origin_y, destination_x, destination_y);
}

void Atlas_WorldGenerator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "octaves", "period", "persistence", "lacunarity"), &Atlas_WorldGenerator::initialize);
    ClassDB::bind_method(D_METHOD("generate_world", "x", "y", "h"), &Atlas_WorldGenerator::generate_world);
    ClassDB::bind_method(D_METHOD("calculate_path", "origin_x", "origin_y", "destination_x", "destination_y"), &Atlas_WorldGenerator::calculate_path);
}
