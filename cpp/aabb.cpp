#include "aabb.h"


aabb::aabb(Interval _x, Interval _y, Interval _z) : x(_x), y(_y), z(_z) {}

aabb::aabb(Point a, Point b) {

    x = Interval(std::min(a.get_x(), b.get_x()), std::max(a.get_x(), b.get_x()));
    y = Interval(std::min(a.get_y(), b.get_y()), std::max(a.get_y(), b.get_y()));
    z = Interval(std::min(a.get_z(), b.get_z()), std::max(a.get_z(), b.get_z()));

}

aabb::aabb(aabb& a, aabb& b) {
    x = Interval(a.get_x(), b.get_x());
    y = Interval(a.get_y(), b.get_y());
    z = Interval(a.get_z(), b.get_z());
}

Interval aabb::axis(int n) {

    if (!n) return x;
    if (n == 1) return y;
    return z;

}


bool aabb::hit(Ray& r, Interval& interval) {

    for (int a = 0; a < 3; a++) {

        double inverse, origin;

        if (!a) {
            inverse = 1 / r.get_direction().get_i();
            origin = r.get_origin().get_x();
        } else if (a == 1) {
            inverse = 1 / r.get_direction().get_j();
            origin = r.get_origin().get_y();
        } else {
            inverse = 1 / r.get_direction().get_k();
            origin = r.get_origin().get_z();
        }

        double t0 = (axis(a).get_min() - origin) * inverse;
        double t1 = (axis(a).get_max() - origin) * inverse;

        if (inverse < 0) std::swap(t0, t1);

        if (t0 > interval.get_min()) interval.set_min(t0);
        if (t1 < interval.get_max()) interval.set_max(t1);

        if (interval.get_max() <= interval.get_min()) return false;

    }

    return true;
}

Interval aabb::get_x() { return x; }
Interval aabb::get_y() { return y; }
Interval aabb::get_z() { return z; }