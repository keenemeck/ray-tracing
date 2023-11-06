#include <iostream>

#include "vec3.h"
#include "point.h"
#include "color.h"


void ppm() {

    const int rows = 256;
    const int cols = 256;

    std::cout << "P3\n" << cols << ' ' << rows << '\n' << 255 << '\n';

    for (int i = 0; i < rows; i++) {

        std::clog << rows - i << " rows remaining.\n";

        for (int j = 0; j < cols; j++) {

            Color color(i, j, (i + j) / 2);
            std::cout << color;

        }

        std::cout << '\n';
    }

    std::clog << "Done.\n";

}


int main() {

    ppm();

    Vector vec(1, 2, 3);

    vec.set_i(4);

    Color c(0, 0, 0);

    std::clog << c;

    std::clog << vec.get_i() << vec.get_j() << vec.get_k();
    
    return 0;
    
}