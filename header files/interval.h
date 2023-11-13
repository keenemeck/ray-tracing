#ifndef interval_h
#define interval_h

class Interval {

public:

    Interval();
    Interval(double min, double max);

    double get_min();
    double get_max();

    double clamp(double x);


private:

    double min, max;

};



#endif