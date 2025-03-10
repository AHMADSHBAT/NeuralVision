#pragma once
#include "IMLModule.h"
#include <vector>
class CLayerBase;

class CModuleBase : public IMLModule
{
public:
    CModuleBase(const std::initializer_list<CLayerBase>& layers);
    ~CModuleBase();

    virtual bool Train();
    virtual bool Predict();
    virtual double GetTotalOutput();


protected:
	std::vector<CLayerBase> m_layers;
};
