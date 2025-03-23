#include "CConv2DLayer.h"
#include "CLogger.h"
#include "CConv2DNeuron.h"


CConv2DLayer::CConv2DLayer(std::vector<INeuron*>&& vecNeurons) : CLayerBase(std::move(vecNeurons))
{
}

CConv2DLayer::CConv2DLayer(const std::vector<INeuron*>& vecNeurons) : CLayerBase(vecNeurons)
{
}

CConv2DLayer::CConv2DLayer(unsigned int neuronNum, unsigned int kernel, std::vector<std::vector<std::vector<double>>>&& filters)
    :m_kernel(kernel)
{
	m_neurons.reserve(neuronNum);
	for (unsigned int i = 0; i < neuronNum; i++)
	{
		for (unsigned int j = 0; j < filters.size(); j++)
		{
			m_neurons.emplace_back(std::make_shared<CConv2DNeuron>(std::vector<INeuron*>{}, std::move(filters[j])));
		}
	}
}

CConv2DLayer::~CConv2DLayer()
{
    LOG(INFO, "Destructor called.");
}

void CConv2DLayer::Forward(const std::vector<std::vector<double>>& imageRawData)
{
	for (auto& neuron : m_neurons)
	{
		neuron.Compute(imageRawData);
	}
}
