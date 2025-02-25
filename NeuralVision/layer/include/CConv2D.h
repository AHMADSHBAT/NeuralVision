#pragma once
#include "CNeuralLayer.h"


class CConv2D : public CNeuralLayer
{
public:
    CConv2D(unsigned int, std::string&&);
    virtual ~CConv2D();
};

