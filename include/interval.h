#ifndef interval_h
#define interval_h

class Interval {

public:

    Interval();
    Interval(double min, double max);
    Interval(const Interval& a, const Interval& b);

    double get_min();
    double get_max();

    void set_min(double m);
    void set_max(double m);

    double clamp(double x);
    double size();
    Interval expand(double d);


private:

    double min, max;

};



#endif