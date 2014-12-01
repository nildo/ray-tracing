#include <cstdlib>
#include <fstream>
#include <iostream>
#include "ambient.h"
#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << endl;
    if (argc < 3) {
        cout << "Input and Output files needed" << endl;
        return 1;
    }
    int imgWidth = 800;
    int imgHeight = 600;
    if (argc == 5) {
        imgWidth = atoi(argv[3]);
        imgHeight = atoi(argv[4]);
    }
    cout << "width = " << imgWidth << " height = " << imgHeight << endl;
    Image image = Image(imgWidth, imgHeight);
    // Input and output files
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(argv[1]);
    outputFile.open(argv[2]);
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
