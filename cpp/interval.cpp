#include <iostream>

#include "interval.h"

Interval::Interval() : min(-INFINITY), max(INFINITY) {}
Interval::Interval(double _min, double _max) : min(_min), max(_max) {}

double Interval::get_min() { return min; }
double Interval::get_max() { return max; }

double Interval::clamp(double x) { 

    if (x < min) return min;
    if (x > max) return max;
    
    return x;

}