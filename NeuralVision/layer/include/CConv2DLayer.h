#pragma once
#include "CActivationFn.h"
#include "CLayerBase.h"


class INeuron;

class CConv2DLayer : public CLayerBase
{
public:
	CConv2DLayer(std::vector<INeuron*>&& vecNeurons);
	CConv2DLayer(const std::vector<INeuron*>& vecNeurons);
	CConv2DLayer(unsigned int neuronNum, unsigned int kernel, std::vector<std::vector<double>>&& filters);

	virtual ~CConv2DLayer();

	void Forward(const std::vector<std::vector<double>>&);
protected:
	unsigned int m_kernel;

};