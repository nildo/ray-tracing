#include <fstream>
#include <iostream>
#include "ambient.h"
#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {
    int imgWidth = 800;
    int imgHeight = 600;
    Image image = Image(imgWidth, imgHeight);
    // Input and output files
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("test1.in");
    outputFile.open("my-test1.ppm");
    // Creating ambient
    Ambient ambient;
    ambient.createCamera(inputFile);
    ambient.createLights(inputFile);
    ambient.createPigments(inputFile);
    ambient.createFinishings(inputFile);
    ambient.createObjects(inputFile);
    // Calculate the color for each pixel
    ambient.createImage(image);
    //Print the image.
    image.print(outputFile);
    inputFile.close();
    outputFile.close();
    return 0;
}
