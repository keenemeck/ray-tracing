#ifndef objects_h
#define objects_h

#include "sphere.h"
#include "aabb.h"

#include <vector>

class objectList {

public:

    objectList();

    aabb* get_bbox();
    std::vector<Sphere> get_spheres();

    void add(Sphere object);

private:

    std::vector<Sphere> spheres;
    aabb* bbox;

};

#endif