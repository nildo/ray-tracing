#include <iostream>
#include "geometry.h"

using namespace std;

int main(int argc, char *argv[]) {
    Vector v1 = Vector(1,2,3);
    Vector v2 = Vector(4,5,6);
    Vector v3 = v1 + v2;
    cout << v1 << " + " << v2 << " = " << v3 << endl;
    return 0;
}
