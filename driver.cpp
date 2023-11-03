#include <iostream>

#include "vec3.h"


void ppm() {

    const int rows = 256;
    const int cols = 256;

    std::cout << "P3\n" << cols << ' ' << rows << '\n' << 255 << '\n';

    for (int i = 0; i < rows; i++) {
        std::clog << rows - i << " rows remaining.\n";
        for (int j = 0; j < cols; j++) {
            std::cout << i << ' ' << j << ' ' << i << ' ';
        }
        std::cout << '\n';
    }

    std::clog << "Done.\n";

}


int main() {

    ppm();

    Vector vec(1, 2, 3);

    vec.set_i(4);

    std::clog << vec.get_i() << vec.get_j() << vec.get_k();
    
    return 0;
    
}