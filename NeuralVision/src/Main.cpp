#include <iostream>
#include "CVModule.h"


int main()
{
    CVModule model({ CLayerBase(10, FnType::ELU) });
    return 0;
}