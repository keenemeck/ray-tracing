#ifndef rand_h
#define rand_h

#include "vec3.h"

#include <random>

class Vector;

double random_double();
double random_double(double min, double max);

Vector randVec();
Vector randVec(double min, double max);

Vector random_unit_vector();
Vector random_unit_normal_face(Vector& normal);

#endif