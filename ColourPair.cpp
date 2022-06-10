#include "TelCoColorCoderLogic.hpp"
using namespace TelCoColorCoder;

    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    MajorColor ColorPair::getMajor() {return majorColor;}
    MinorColor ColorPair::getMinor() {return minorColor;}
    std::string ColorPair::ToString() {
         std::string colorPairStr = MajorColorNames[majorColor];
         colorPairStr += " ";
         colorPairStr += MinorColorNames[minorColor];
         return colorPairStr;
    }

    ColorPair::ColorPair(MajorColor major, MinorColor minor): m_majorColor(major),m_minorColor(minor);
    {}

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
