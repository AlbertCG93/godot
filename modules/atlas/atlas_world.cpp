#include "modules/atlas/atlas_world.h"

Atlas_World::Atlas_World() {

}

Atlas_World::~Atlas_World() {

}

void Atlas_World::initialize(int x, int y) {
    world = std::vector<std::vector<Atlas_Cell>>(x, std::vector<Atlas_Cell>(y));
}

int Atlas_World::get_size_x() {
    return world.size();
}

int Atlas_World::get_size_y() {
    return world[0].size();
}

Atlas_Cell* Atlas_World::get_cell(int i, int j) {
    return &world[i][j];
}

void Atlas_World::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "x", "y"), &Atlas_World::initialize);
    ClassDB::bind_method(D_METHOD("get_size_x"), &Atlas_World::get_size_x);
    ClassDB::bind_method(D_METHOD("get_size_y"), &Atlas_World::get_size_y);
    ClassDB::bind_method(D_METHOD("get_cell", "i", "j"), &Atlas_World::get_cell);
}