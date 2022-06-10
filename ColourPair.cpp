#include "ColourPair.hpp"
using namespace TelCoColorCoder;

    const char* TelCoColorCoder::MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* TelCoColorCoder::MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    int TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    MajorColor ColorPair::getMajor() {return majorColor;}
    MinorColor ColorPair::getMinor() {return minorColor;}
    std::string ColorPair::ToString() {
         std::string colorPairStr = MajorColorNames[majorColor];
         colorPairStr += " ";
         colorPairStr += MinorColorNames[minorColor];
         return colorPairStr;
    }

    ColorPair::ColorPair(MajorColor major, MinorColor minor): majorColor(major),minorColor(minor)
    {}

    ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
        
    void TelCoColorCoder::PrintColourPairManual() {
        std::cout<<"\n---------------------------------\n");
        int NumberofPairs = TelCoColorCoder::numberOfMajorColors*TelCoColorCoder::numberOfMinorColors
        
        for(int pairNumber=1; pairNumber<=NumberofPairs; pairNumber++)
        {
            TelCoColorCoder::ColorPair colorNames = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
            std::cout<<pairNumber<<"\t"<<colorNames.ToString()<<"\n";
        }
        std::cout<<"\n---------------------------------\n");
    }
