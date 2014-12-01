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
    inputFile.open("test3.in");
    outputFile.open("my-test1.ppm");
    // Creating stringstream
    string lines;
    for(string line; getline(inputFile, line);) {
        lines += line + '\n';
    }
    istringstream in(lines);
    // Creating ambient
    Ambient ambient;
    ambient.createCamera(in);
    ambient.createLights(in);
    ambient.createPigments(in);
    ambient.createFinishings(in);
    ambient.createObjects(in);
    // Calculate the color for each pixel
    ambient.createImage(image);
    //Print the image.
    image.print(outputFile);
    inputFile.close();
    outputFile.close();
    return 0;
}
