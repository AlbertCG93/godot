#include "modules/atlas/atlas_world.h"

Atlas_World::Atlas_World() {

}

Atlas_World::~Atlas_World() {

}

void Atlas_World::initialize(int x, int y) {
    representation = std::vector<std::vector<uint8_t>>(x, std::vector<uint8_t>(y));
}

int Atlas_World::get_size_x() {
    return representation.size();
}

int Atlas_World::get_size_y() {
    return representation[0].size();
}

void Atlas_World::set_value(int i, int j, uint8_t value) {
    representation[i][j] = value;
}

uint8_t Atlas_World::get_value(int i, int j) {
    return representation[i][j];
}

void Atlas_World::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "x", "y"), &Atlas_World::initialize);
    ClassDB::bind_method(D_METHOD("get_size_x"), &Atlas_World::get_size_x);
    ClassDB::bind_method(D_METHOD("get_size_y"), &Atlas_World::get_size_y);
    ClassDB::bind_method(D_METHOD("set_value", "i", "j", "value"), &Atlas_World::set_value);
    ClassDB::bind_method(D_METHOD("get_value", "i", "j"), &Atlas_World::get_value);
}