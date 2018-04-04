#include "ColorContainer.hpp"

#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

vector<ColorType> myColors;
int width;

ColorContainer::ColorContainer() {
    srand(time(NULL));

    // this is how many stripes you get TODO: add a control in the ui to modify the number of stripes
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

vector<ColorType> ColorContainer::sortRed(vector<ColorType> yourColors) {
    int j;
    ColorType tempColor;

    for(int i = 1; i < yourColors.size(); i++) {
        tempColor = yourColors[i];
        j = i - 1;
        while((tempColor.r < yourColors[j].r) && (j >= 0)) {
            yourColors[j + 1] = yourColors[j];
            j = j - 1;
        }
        yourColors[j + 1] = tempColor;
    }
    return yourColors;
}

vector<ColorType> ColorContainer::sortGreen(vector<ColorType> yourColors) {
    int j;
    ColorType tempColor;

    for(int i = 1; i < yourColors.size(); i++) {
        tempColor = yourColors[i];
        j = i - 1;
        while((tempColor.g < yourColors[j].g) && (j >= 0)) {
            yourColors[j + 1] = yourColors[j];
            j = j - 1;
        }
        yourColors[j + 1] = tempColor;
    }
    return yourColors;
}

vector<ColorType> ColorContainer::sortBlue(vector<ColorType> yourColors) {
    int j;
    ColorType tempColor;

    for(int i = 1; i < yourColors.size(); i++) {
        tempColor = yourColors[i];
        j = i - 1;
        while((tempColor.b < yourColors[j].b) && (j >= 0)) {
            yourColors[j + 1] = yourColors[j];
            j = j - 1;
        }
        yourColors[j + 1] = tempColor;
    }
    return yourColors;
}

vector<ColorType> ColorContainer::sortAlpha(vector<ColorType> yourColors) {
    int j;
    ColorType tempColor;

    for(int i = 1; i < yourColors.size(); i++) {
        tempColor = yourColors[i];
        j = i - 1;
        while((tempColor.a < yourColors[j].a) && (j >= 0)) {
            yourColors[j + 1] = yourColors[j];
            j = j - 1;
        }
        yourColors[j + 1] = tempColor;
    }
    return yourColors;
}
