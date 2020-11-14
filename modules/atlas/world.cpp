#include "modules/atlas/world.h"

World::World() {

}

World::World(int x, int y) {
    representation = std::vector<std::vector<uint8_t>>(x, std::vector<uint8_t>(y));
}

World::~World() {

}

void World::set_value(int i, int j, uint8_t value) {
    representation[i][j] = value;
}

uint8_t World::get_value(int i, int j) {
    return representation[i][j];
}

void World::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_value", "i", "j", "value"), &World::set_value);
    ClassDB::bind_method(D_METHOD("get_value", "i", "j"), &World::get_value);
}