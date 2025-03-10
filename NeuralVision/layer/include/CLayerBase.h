#pragma once
#include <vector>
#include "ILayer.h"
#include "CNeuronBase.h"


class CLayerBase : public ILayer
{
public:

	CLayerBase(unsigned int, FnType);
	virtual ~CLayerBase();


protected:
	std::vector<CNeuronBase> m_neurons;
};

