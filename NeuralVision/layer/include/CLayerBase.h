#pragma once
#include <vector>
#include "ILayer.h"

class CNeuronBase;
class INeuron;

class CLayerBase : public ILayer
{
public:
	CLayerBase();
	CLayerBase(std::vector<INeuron*>&& vecNeurons);
	CLayerBase(const std::vector<INeuron*>& vecNeurons);
	virtual ~CLayerBase();


protected:

	std::vector<std::shared_ptr<INeuron>> m_neurons;
    FnType m_fn;
};

