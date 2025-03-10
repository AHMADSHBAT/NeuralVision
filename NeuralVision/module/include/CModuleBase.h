#pragma once
#include "IMLModule.h"
#include <vector>
class CLayerBase;

class CModuleBase : public IMLModule
{
public:
    CModuleBase(std::vector<CLayerBase>& layers);
    CModuleBase(std::vector<CLayerBase>&& layers);
    ~CModuleBase();


protected:
	std::vector<CLayerBase> m_layers;
};
