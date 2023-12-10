#include <iostream>

#include "interval.h"

Interval::Interval() : min(-INFINITY), max(INFINITY) {}
Interval::Interval(double _min, double _max) : min(_min), max(_max) {}
Interval::Interval(const Interval& a, const Interval& b) : min(std::min(a.min, b.min)), max(std::max(a.max, b.max)) {}


double Interval::get_min() { return min; }
double Interval::get_max() { return max; }

void Interval::set_min(double m) { min = m; }
void Interval::set_max(double m) { max = m; }

double Interval::clamp(double x) { 

    if (x < min) return min;
    if (x > max) return max;
    
    return x;

}

double Interval::size() { return max - min; }
Interval Interval::expand(double d) {

    double pad = d / 2;
    return Interval(min - pad, max + pad);

}