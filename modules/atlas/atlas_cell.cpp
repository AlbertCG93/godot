#include "modules/atlas/atlas_cell.h"

const short Atlas_Cell::CELL_ADJACENCY_SIZE = 9;
    
const short Atlas_Cell::CELL_ADJACENCY_X[] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};
const short Atlas_Cell::CELL_ADJACENCY_Y[] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};

Atlas_Cell::Atlas_Cell() {

}

Atlas_Cell::Atlas_Cell(const Atlas_Cell& cell) {
    height = cell.height;
    neighbors = cell.neighbors;
}

Atlas_Cell::~Atlas_Cell() {

}

void Atlas_Cell::set_height(uint8_t value) {
    height = value;
}

uint8_t Atlas_Cell::get_height() {
    return height;
}

Array Atlas_Cell::get_neighbors() {
    return neighbors;
}

void Atlas_Cell::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_height", "value"), &Atlas_Cell::set_height);
    ClassDB::bind_method(D_METHOD("get_height"), &Atlas_Cell::get_height);
    ClassDB::bind_method(D_METHOD("get_neighbors"), &Atlas_Cell::get_neighbors);
}