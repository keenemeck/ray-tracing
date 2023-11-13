#include "rand.h"

double random_double() {

    static std::uniform_real_distribution<double> dist(0, 1);
    static std::mt19937 gen;
    return dist(gen);

}

double random_double(double min, double max) {

    double range = max - min;
    if (min < 0) min = -min;

    return random_double() * range - min;

}

Vector randVec() { return Vector(random_double(), random_double(), random_double()); }
Vector randVec(double min, double max) { return Vector(random_double(min, max), random_double(min, max), random_double(min, max)); }


Vector random_unit_vector() {

    Vector current = randVec(-1.0, 1.0);

    while (sqrt(current.dot(current)) > 1) {
        current = randVec(-1.0, 1.0);
    }

    return current.unit();

}

Vector random_unit_normal_face(Vector& normal) {

    Vector unit = random_unit_vector();

    return unit.dot(normal) > 0 ? unit : -unit;

}