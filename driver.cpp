#include <iostream>

using std::cout;

void ppm() {

    const int rows = 256;
    const int cols = 256;

    cout << "P3\n" << cols << ' ' << rows << '\n' << 255 << '\n';

    for (int i = 0; i < rows; i++) {
        std::clog << rows - i << " rows remaining.\n";
        for (int j = 0; j < cols; j++) {
            cout << i << ' ' << j << ' ' << i << ' ';
        }
        cout << '\n';
    }

    std::clog << "Done.\n";

}


int main() {

    ppm();
    
    return 0;
    
}