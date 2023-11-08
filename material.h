#ifndef material_h
#define material_h

#include "color.h"

class Material {

public:

    Material();
    Material(Color albedo);
    Material(Color albedo, bool reflective);


private:

    Color albedo;
    bool reflective;


};

#endif