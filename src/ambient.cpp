#include <iostream>
#include <sstream>
#include <string>

#include "ambient.h"

using namespace std;

void Ambient::createCamera(istringstream& in) {
    float x, y, z, opening;
    in >> x >> y >> z;
    Point origin = Point(x, y, z);
    in >> x >> y >> z;
    Point target = Point(x, y, z);
    in >> x >> y >> z;
    Point up = Point(x, y, z);
    in >> opening;
    camera.origin = origin;
    camera.target = target;
    camera.up = up;
    camera.opening = opening;
    // Debug
    cout << camera.origin << endl;
    cout << camera.target << endl;
    cout << camera.up << endl;
    cout << camera.opening << endl;
}

void Ambient::createLights(istringstream& in) {
    int n;
    in >> n;
    lights = new Light[n];
    lightsSize = n;
    for (int i = 0; i < n; i++) {
        float x, y, z, r, g, b, ac, ad, as;
        in >> x >> y >> z >> r >> g >> b >> ac >> ad >> as;
        Point location = Point(x, y, z);
        Color color = Color(r, g, b);
        LightType type = (i == 0) ? AMBIENT : SOURCE;
        Light light = Light(type, location, color, ac, ad, as);
        lights[i] = light;
    }
    for (int i = 0; i < lightsSize; i++) {
        cout << lights[i];
    }
}

void Ambient::createPigments(istringstream& in) {
    int n;
    in >> n;
    pigments = new Pigments[n];
    pigmentsSize = n;
    for (int i = 0; i < n; i++) {
        string type;
        in >> type;
        if (type == "solid") {
            float r, g, b;
            in >> r >> g >> b;
            Color color = Color(r, g, b);
            Pigment pigment = Pigment(color);
            pigments[i] = pigment;
        }
        if (type == "checker") {
            float r, g, b, lenght;
            in >> r >> g >> b;
            Color color1 = Color(r, g, b);
            in >> r >> g >> b;
            Color color2 = Color(r, g, b);
            in >> lenght;
            Pigment pigment = Pigment(color1, color2, lenght);
        }
        if (type == "textmap") {
            string fileName;
            in >> fileName;
            float x, y, z, w;
            in >> x >> y >> z >> w;
            
        }
    }
}

void Ambient::createFinishings(istringstream& in) {

}

void Ambient::createObjects(istringstream& in) {

}

void Ambient::createImage(Image& image) {

}
