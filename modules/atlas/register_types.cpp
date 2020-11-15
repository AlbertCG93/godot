#include "register_types.h"

#include "core/class_db.h"

#include "world.h"
#include "world_generator.h"

void register_atlas_types() {
    ClassDB::register_class<World>();
    ClassDB::register_class<WorldGenerator>();
}

void unregister_atlas_types() {

}