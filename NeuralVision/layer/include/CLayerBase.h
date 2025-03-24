#pragma once
#include <vector>
#include "ILayer.h"

class CNeuronBase;
class INeuron;

class CLayerBase : public ILayer
{
public:

	CLayerBase(unsigned int, FnType);
	CLayerBase(std::vector<INeuron*>&& vecNeurons);
	CLayerBase(const std::vector<INeuron*>& vecNeurons);
	//CLayerBase(std::vector<std::pair<CNeuronBase&&,const INeuron*>&&>&&, FnType);
	virtual ~CLayerBase();


protected:
	std::vector<std::shared_ptr<INeuron>> m_neurons;
};

