#include <iostream>

using std::cout;

void ppm() {

    const int rows = 256;
    const int cols = 256;

    cout << "P3\n" << cols << ' ' << rows << '\n' << 255 << '\n';

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << i << ' ' << j << ' ' << i << ' ';
        }
        cout << '\n';
    }

}


int main() {

    ppm();
    
    return 0;
    
}