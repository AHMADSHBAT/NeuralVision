#pragma once

#include "ILayer.h"
#include <string>

class CNeuralLayer : public ILayer
{
public:
    CNeuralLayer(unsigned int, std::string&&);
    virtual ~CNeuralLayer();

};

