#pragma once
#include "IMLModule.h"
#include <vector>
#include "CModuleBase.h"
#include "CActivationFn.h"
#include "CLayerBase.h"


class CVModule : public CModuleBase
{
public:
    CVModule(const std::initializer_list<CLayerBase>& layers);
    ~CVModule();

};

