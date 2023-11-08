#include "hitInfo.h"

HitInfo::HitInfo() : point({0, 0, 0}), normal({0, 0, 0}), t(INFINITY), front(false) {}

Point HitInfo::get_point() { return point; }
Vector HitInfo::get_normal() { return normal; }
double HitInfo::get_t() { return t; }
bool HitInfo::get_front() { return front; }
Material HitInfo::get_material() { return material; }

void HitInfo::set_point(Point& p) { point = p; }
void HitInfo::set_normal(Vector& n) { normal = n; }
void HitInfo::set_t(double _t) { t = _t; }
void HitInfo::set_front(bool f) { front = f; }
void HitInfo::set_material(Material& m) { material = m; }