#ifndef COLOR_CONTAINER
#define COLOR_CONTAINER

#include <vector>
#include <iostream>

using namespace std;

struct ColorType {
    int r;
    int g;
    int b;
    int a;
};

class ColorContainer {

public:
	ColorContainer();

	virtual ~ColorContainer();

	vector<ColorType> getColorVec();

    vector<ColorType> sortRed(vector<ColorType>);
    vector<ColorType> sortGreen();
    vector<ColorType> sortBlue();
    vector<ColorType> sortAlpha();

private:
    vector<ColorType> myColors;

    int width;
};

#endif
