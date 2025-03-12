#pragma once
#include <vector>
#include "ILayer.h"
#include "CNeuronBase.h"


class CLayerBase : public ILayer
{
public:

	CLayerBase(unsigned int, FnType);
	CLayerBase(std::vector<CNeuronBase>&& vecNeurons);
	//CLayerBase(std::vector<std::pair<CNeuronBase&&,const INeuron*>&&>&&, FnType);
	virtual ~CLayerBase();


protected:
	std::vector<CNeuronBase> m_neurons;
};

