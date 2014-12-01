#ifndef AMBIENT_H
#define AMBIENT_H

#include <iostream>
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
    Object *objects;

    void createCamera(istream& file);
    void createLights(istream& file);
    void createPigments(istream& file);
    void createFinishings(istream& file);
    void createObjects(istream& file);
    void createImage(Image& image);
};

#endif