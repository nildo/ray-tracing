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

    cout << "Camera:" << endl;
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

    cout << "Lights:" << endl;
    for (int i = 0; i < lightsSize; i++) {
        cout << lights[i];
    }
}

void Ambient::createPigments(istringstream& in) {
    int n;
    in >> n;
    pigments = new Pigment[n];
    pigmentsSize = n;
    for (int i = 0; i < n; i++) {
        string type;
        in >> type;
        cout << type << endl;
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
            pigments[i] = pigment;
        }
        if (type == "texmap") {
            string fileName;
            in >> fileName;
            float x, y, z, w;
            in >> x >> y >> z >> w;
            in >> x >> y >> z >> w;
            // TODO: implement the texmap.
            Texmap tm;
            Pigment pigment = Pigment(tm);
            pigments[i] = pigment;
        }
    }
    cout << "Pigments:" << endl;
    for (int i = 0; i < pigmentsSize; i++) {
        cout << pigments[i] << endl;
    }
}

void Ambient::createFinishings(istringstream& in) {
    int n;
    in >> n;
    finishings = new Finishing[n];
    finishingsSize = n;
    for (int i = 0; i < n; i++) {
        float ka, kd, ks, alpha, kr, kt, ior;
        in >> ka >> kd >> ks >> alpha >> kr >> kt >> ior;
        Finishing f = Finishing(ka, kd, ks, alpha, kr, kt, ior);
        finishings[i] = f;
    }
    cout << "Finishings:" << endl;
    for (int i = 0; i < finishingsSize; i++) {
        cout << finishings[i] << endl;
    }
}

void Ambient::createObjects(istringstream& in) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        int p, f;
        in >> p >> f;
        Pigment pigment = pigments[p];
        Finishing finishing = finishings[f];
        string type;
        in >> type;
        if (type == "sphere") {
            float x, y, z, r;
            in >> x >> y >> z >> r;
            Sphere *sphere = new Sphere(pigment, finishing, x, y, z, r);
            objects.push_back(sphere);
        }
        if (type == "polyhedron") {
            Polyhedron *polyhedron = new Polyhedron(pigment, finishing);
            int m;
            in >> m;
            for (int j = 0; j < m; j++) {
                float a, b, c, d;
                in >> a >> b >> c >> d;
                Plane plane = Plane(a, b, c, d);
                polyhedron->addPlane(plane);
            }
            objects.push_back(polyhedron);
        }   
    }
    cout << "Objects:" << endl;
    for(vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it) {
        Object *obj = *it;
        if (obj->type == SPHERE) {
            cout << "sphere ";
            Sphere *i = (Sphere*) obj;
            cout << i->x << ' ' << i->y << ' ' << i->z << ' ' << i->r << endl;
        } else {
            cout << "polyhedron ";
            Polyhedron *i = (Polyhedron*) obj;
            cout << i->planes.size() << endl;
        }
    }
}

void Ambient::createImage(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            float xScreenPos = (float) i / (float) image.width;
            float yScreenPos = (float) j / (float) image.height;
            Ray ray = camera.makeRay(xScreenPos, yScreenPos);

            //cout << '[' << i << ',' << j << ']' << ' ';
            //cout << ray.origin << ' ' << ray.direction << endl;

            bool intersectedAny = false;
            Color color = lights[0].color;
            for(vector<Object*>::iterator it = objects.begin();
                    it != objects.end();
                    ++it)
            {
                Object *obj = *it;
                Point p;
                float dMin;
                if (obj->intersect(ray, p)) {
                    if (!intersectedAny) {
                        intersectedAny = true;
                        color = obj->getColor(p);
                        dMin = (p - ray.origin).length();
                    } else {
                        float d = (p - ray.origin).length();
                        if (d < dMin) {
                            color = obj->getColor(p);
                            dMin = d;
                        }
                    }
                }
            }
            image.pixels[i][j].color = color;
        }
    }
}
