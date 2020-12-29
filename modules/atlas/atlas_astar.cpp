#include "modules/atlas/atlas_astar.h"

#include "modules/atlas/atlas_cell.h"

#include <map>
#include <utility>

Atlas_AStar::Atlas_AStar(Atlas_World* world)
    : world(world) {

}

Atlas_AStar::~Atlas_AStar() {
    for (auto map_element : points) {
        delete map_element.second;
    }
}

Array Atlas_AStar::solve(uint16_t origin_x, uint16_t origin_y, uint16_t destination_x, uint16_t destination_y) {
    uint32_t origin_hash = Atlas_Cell::calculate_hash(origin_x, origin_y);
    uint32_t destination_hash = Atlas_Cell::calculate_hash(destination_x, destination_y);

	uint32_t dh_top = (uint32_t)(destination_x << 16);

    Point destination (destination_x, destination_y, world->get_cell_height(destination_x, destination_y));

    Point* origin = new Point(origin_x, origin_y, world->get_cell_height(origin_x, origin_y));
    
    origin->status = Point::Status::OPEN;

    origin->g_score = 0.0;
    origin->f_score = origin->h_score(&destination);

    points[origin_hash] = origin;
    scores.insert(origin);

    while (!scores.empty()) {
        Point* point = *(scores.begin());

        if (point->hash == destination_hash) {
            Array path;

            Point* iterator = point;
            while (iterator->hash != origin_hash) {
                path.push_front(iterator->hash);

                iterator = iterator->previous_point;
            }

            path.push_front(iterator->hash);

            return path;
        }

        if (point->status == Point::Status::CLOSED) {
            scores.erase(point);

            continue;
        }

        point->status = Point::Status::CLOSED;

        Atlas_Cell* cell = world->get_cell(point->hash);

        for (uint32_t neighbor_hash : cell->get_neighbors()) {
            Atlas_Cell* neighbor_cell = world->get_cell(neighbor_hash);
            
            if (points.find(neighbor_hash) != points.end()) {
                Point* neighbor_point = points[neighbor_hash];

                real_t g_score = point->g_score + 1.0;
                if (g_score < neighbor_point->g_score) {
                    neighbor_point->previous_point = point;
                }

                continue;
            }

            Point* neighbor_point = new Point(neighbor_cell->x, neighbor_cell->y, neighbor_cell->height);

            neighbor_point->previous_point = point;

            neighbor_point->status = Point::Status::OPEN;

            neighbor_point->g_score = point->g_score + 1.0;
            neighbor_point->f_score = neighbor_point->g_score + neighbor_point->h_score(&destination);

            points[neighbor_hash] = neighbor_point;
            scores.insert(neighbor_point);
        }
    }

    return Array();
}
