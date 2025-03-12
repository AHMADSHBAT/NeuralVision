#pragma once
#include "CActivationFn.h"
#include "CLayerBase.h"


class INeuron;

class CConv2D : public CLayerBase
{
public:
	CConv2D(unsigned int, FnType);
	CConv2D(std::vector<INeuron*>&& vecNeurons);
	CConv2D(const std::vector<INeuron*>& vecNeurons);

	virtual ~CConv2D();
};

