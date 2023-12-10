#include "objects.h"

objectList::objectList() {
    bbox = new aabb();
}

aabb* objectList::get_bbox() { return bbox; }
std::vector<Sphere> objectList::get_spheres() { return spheres; }


void objectList::add(Sphere object) {

    spheres.push_back(object);
    bbox = new aabb(*bbox, *object.get_bbox());

}