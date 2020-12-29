#include "modules/atlas/atlas_world.h"


Atlas_World::Atlas_World() {

}

Atlas_World::~Atlas_World() {
    delete world;
}

void Atlas_World::initialize(uint16_t x, uint16_t y) {
    world = new std::vector<std::vector<Atlas_Cell>>();
}

uint16_t Atlas_World::get_size_x() {
    return (*world).size();
}

uint16_t Atlas_World::get_size_y() {
    return (*world)[0].size();
}

Atlas_Cell* Atlas_World::get_cell(uint16_t i, uint16_t j) {
    return &((*world)[i][j]);
}

Atlas_Cell* Atlas_World::get_cell(uint32_t hash) {
    uint16_t i = (hash >> 16) & (uint16_t) 0xFFFF;
    uint16_t j = hash & (uint16_t) 0xFFFF;

    return &((*world)[i][j]);
}

uint8_t Atlas_World::get_cell_height(uint16_t i, uint16_t j) {
    return (*world)[i][j].get_height();
}

void Atlas_World::_bind_methods() {
    ClassDB::bind_method(D_METHOD("initialize", "x", "y"), &Atlas_World::initialize);
    ClassDB::bind_method(D_METHOD("get_size_x"), &Atlas_World::get_size_x);
    ClassDB::bind_method(D_METHOD("get_size_y"), &Atlas_World::get_size_y);
    ClassDB::bind_method(D_METHOD("get_cell_height", "i", "j"), &Atlas_World::get_cell_height);
}
