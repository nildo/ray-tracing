#ifndef AMBIENT_H
#define AMBIENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include "camera.h"
#include "light.h"
#include "pigment.h"
#include "finishing.h"
#include "object.h"
#include "image.h"

using namespace std;

class Ambient {
public:
    Camera camera;
    Light ambientLight;
    Light *lights;
    Pigment *pigments;
    Finishing *finishings;
    vector<Object*> objects;
    int lightsSize;
    int pigmentsSize;
    int finishingsSize;

    void createCamera(istringstream& in);
    void createLights(istringstream& in);
    void createPigments(istringstream& in);
    void createFinishings(istringstream& in);
    void createObjects(istringstream& in);
    void createImage(Image& image);
};

#endif