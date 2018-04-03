#include "ColorContainer.hpp"

#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

vector<ColorType> myColors;
int width;

ColorContainer::ColorContainer() {
    srand(time(NULL));
    // instantiate the color arrays and fill them with random values - dummy value of 100 for the window width
    width = 500;

    int i = 0;
    do {
        ColorType myColor = {static_cast<int>(rand() % 255), static_cast<int>(rand() % 255), static_cast<int>(rand() % 255), static_cast<int>(rand() % 255)};
        myColors.push_back(myColor);
        i++;
    } while (i < width);
}

ColorContainer::~ColorContainer() {}

vector<ColorType> ColorContainer::getColorVec() {
    return myColors;
}

vector<ColorType> ColorContainer::sortRed(vector<ColorType> colors) {
    int j;
    ColorType tempColor;

    for(int i = 1; i < myColors.size(); i++) {
        tempColor = myColors[i];
        j = i - 1;
        while((tempColor.r < myColors[j].r) && (j >= 0)) {
            myColors[j + 1] = myColors[j];
            j = j - 1;
        }
        myColors[j + 1] = tempColor;
    }
    return myColors;
}

vector<ColorType> ColorContainer::sortGreen() {
    int j;
    ColorType tempColor;

    for(int i = 1; i < myColors.size(); i++) {
        tempColor = myColors[i];
        j = i - 1;
        while((tempColor.g < myColors[j].g) && (j >= 0)) {
            myColors[j + 1] = myColors[j];
            j = j - 1;
        }
        myColors[j + 1] = tempColor;
    }
    return myColors;
}

vector<ColorType> ColorContainer::sortBlue() {
    int j;
    ColorType tempColor;

    for(int i = 1; i < myColors.size(); i++) {
        tempColor = myColors[i];
        j = i - 1;
        while((tempColor.b < myColors[j].b) && (j >= 0)) {
            myColors[j + 1] = myColors[j];
            j = j - 1;
        }
        myColors[j + 1] = tempColor;
    }
    return myColors;
}

vector<ColorType> ColorContainer::sortAlpha() {
    int j;
    ColorType tempColor;

    for(int i = 1; i < myColors.size(); i++) {
        tempColor = myColors[i];
        j = i - 1;
        while((tempColor.a < myColors[j].a) && (j >= 0)) {
            myColors[j + 1] = myColors[j];
            j = j - 1;
        }
        myColors[j + 1] = tempColor;
    }
    return myColors;
}
