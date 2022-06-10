#include <iostream>
#include "CoderTestingScript.hpp"
using namespace TelCoColorCoder;

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    TelCoColorCoder::PrintColourPairManual();
    
    return 0;
}
