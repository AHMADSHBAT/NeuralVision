#pragma once
#include "IMLModule.h"
#include <vector>
#include "CModuleBase.h"

class CLayerBase;


class CVModule : public CModuleBase
{
public:
    CVModule(std::vector<CLayerBase>& layers);
    CVModule(std::vector<CLayerBase>&& layers);
    ~CVModule();

};

