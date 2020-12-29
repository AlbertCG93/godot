#ifndef ATLAS_ASTAR_H
#define ATLAS_ASTAR_H

#include "modules/atlas/atlas_cell.h"
#include "modules/atlas/atlas_world.h"

#include "core/array.h"

#include <map>
#include <set>
#include <vector>


class Atlas_AStar {

public:
    struct Point {

        enum Status { UNKNOWN, OPEN, CLOSED };

        Point(uint16_t x, uint16_t y, uint8_t z) 
            : Point(Atlas_Cell::calculate_hash(x, y), x, y, z) {

        }

        Point(uint32_t hash, uint16_t x, uint16_t y, uint8_t z)
            : hash(hash), x(x), y(y), z(z) {
            status = Status::UNKNOWN;
        }

        Point* previous_point;

        uint32_t hash;

		uint16_t x;
		uint16_t y;
		uint8_t z;

        Status status;

		real_t f_score;
        real_t g_score;

        inline real_t h_score(Point* destination_point) {
            real_t dx = (real_t) (destination_point->x - x);
            real_t dy = (real_t) (destination_point->y - y);
            real_t dz = (real_t) (destination_point->z - z);

            return sqrt(dx*dx + dy*dy + dz*dz);
        }
	};

    struct Point_Comparator {
        inline bool operator()(const Point* a, const Point* b) const {
            if (a->f_score < b->f_score) {
                return true;
            } else if (a->f_score > b->f_score) {
                return false;
            } else {
                return (a->g_score > b->g_score);
            }
        }
    };

    Atlas_AStar(Atlas_World* world);
    ~Atlas_AStar();

    Array solve(uint16_t origin_x, uint16_t origin_y, uint16_t destination_x, uint16_t destination_y);

protected:
    Atlas_World* world;

    std::map<uint32_t, Point*> points;
    std::set<Point*, Point_Comparator> scores;
};

#endif