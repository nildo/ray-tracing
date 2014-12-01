#include "image.h"

using namespace std;

Image::Image(int width, int height) {
    this->width = width;
    this->height = height;
    this->pixels = new Pixel*[width];
    for (int i = 0; i < width; i++) {
        this->pixels[i] = new Pixel[height];
    }
}

Image::Image(int width, int height, Color color) {
    this->width = width;
    this->height = height;
    this->pixels = new Pixel*[width];
    for (int i = 0; i < width; i++) {
        this->pixels[i] = new Pixel[height];
        for (int j = 0; j < height; j++) {
            this->pixels[i][j].color = color;
        }
    }
}

Image::~Image() {
    for (int i = 0; i < width; i++) {
        delete pixels[i];
    }
    delete pixels;
}

void Image::print(ostream& file) {
    file << "P3" << endl;
    file << width << ' ' << height << endl;
    file << "255" << endl;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Pixel pixel = pixels[i][j];
            file << pixel.color << ' ';
        }
        file << endl;
    }
}
