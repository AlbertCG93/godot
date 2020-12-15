#ifndef ATLAS_CELL_H
#define ATLAS_CELL_H

#include "core/array.h"
#include "core/object.h"
#include "core/vector.h"

class Atlas_Cell : public Object {
    GDCLASS(Atlas_Cell, Object);

public:
    static const short CELL_ADJACENCY_SIZE;
    
    static const short CELL_ADJACENCY_X[];
    static const short CELL_ADJACENCY_Y[];

    Atlas_Cell();
    ~Atlas_Cell();

    Atlas_Cell(const Atlas_Cell& cell);

    void set_height(uint8_t value);
    uint8_t get_height();

    Vector<Atlas_Cell*> get_neighbors();

protected:
    uint8_t height = 0;

    Vector<Atlas_Cell*> neighbors;

    static void _bind_methods();
};

#endif