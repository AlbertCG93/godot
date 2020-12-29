#ifndef ATLAS_CELL_H
#define ATLAS_CELL_H

#include <vector>

namespace Atlas_Cell_Constants {
    extern const short CELL_ADJACENCY_SIZE;
    
    extern const short CELL_ADJACENCY_X[];
    extern const short CELL_ADJACENCY_Y[];
};

class Atlas_Cell {

public:
    Atlas_Cell(uint16_t x, uint16_t y);
    Atlas_Cell(uint16_t x, uint16_t y, uint8_t height);
    ~Atlas_Cell();

    void set_height(uint8_t value);
    uint8_t get_height();

    std::vector<uint32_t>& get_neighbors();

    static inline uint32_t calculate_hash(uint16_t x, uint16_t y) {
        return (((uint32_t) x << 16) | (uint32_t) y);
    }

protected:
    uint16_t x;
    uint16_t y;

    uint8_t height;

    std::vector<uint32_t> neighbors;

    friend class Atlas_AStar;
};

#endif