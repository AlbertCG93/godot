#include "modules/atlas/atlas_cell.h"

const short Atlas_Cell_Constants::CELL_ADJACENCY_SIZE = 8;
    
const short Atlas_Cell_Constants::CELL_ADJACENCY_X[] = {-1, 0, +1, -1, +1, -1, 0, +1};
const short Atlas_Cell_Constants::CELL_ADJACENCY_Y[] = {-1, -1, -1, 0, 0, +1, +1, +1};

Atlas_Cell::Atlas_Cell(uint16_t x, uint16_t y)
    : x(x), y(y) {

}

Atlas_Cell::Atlas_Cell(uint16_t x, uint16_t y, uint8_t height)
    : x(x), y(y), height(height) {

}

Atlas_Cell::~Atlas_Cell() {

}

void Atlas_Cell::set_height(uint8_t value) {
    height = value;
}

uint8_t Atlas_Cell::get_height() {
    return height;
}

std::vector<uint32_t>& Atlas_Cell::get_neighbors() {
    return neighbors;
}