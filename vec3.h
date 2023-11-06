#ifndef vec3_h
#define vec3_h

class Vector {

private:

    double i, j, k;

public:

    Vector();
    Vector(double i, double j, double k);

    double get_i();
    double get_j();
    double get_k();

    void set_i(double i);
    void set_j(double j);
    void set_k(double k);

    Vector operator*(int x);
    Point to_point();

};




#endif