#pragma once
#include "CActivationFn.h"
#include "CLayerBase.h"



class CConv2D : public CLayerBase
{
public:
    CConv2D(unsigned int, FnType);
    virtual ~CConv2D();
};

