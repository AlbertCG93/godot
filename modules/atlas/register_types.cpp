#include "register_types.h"

#include "core/class_db.h"

#include "atlas_world.h"
#include "atlas_world_generator.h"

void register_atlas_types() {
    ClassDB::register_class<Atlas_World>();
    ClassDB::register_class<Atlas_WorldGenerator>();
}

void unregister_atlas_types() {

}