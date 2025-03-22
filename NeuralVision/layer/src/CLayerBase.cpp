#include "CLayerBase.h"
#include "CActivationFn.h"
#include "CNeuronBase.h"
#include "CLogger.h"
#include <memory>



CLayerBase::CLayerBase(std::vector<INeuron*>&& vecNeurons)
{
    LOG(INFO, "Constructor called.");
    m_neurons.reserve(vecNeurons.size()); // Reserve memory to avoid multiple allocations
    for (auto& i : vecNeurons)
    {
        m_neurons.emplace_back(std::shared_ptr<INeuron>(i));
    }
}

CLayerBase::CLayerBase(const std::vector<INeuron*>& vecNeurons)
{
    LOG(INFO, "Constructor called.");
    m_neurons.reserve(vecNeurons.size()); // Reserve memory to avoid multiple allocations
    for (auto& i : vecNeurons)
    {
        m_neurons.emplace_back(std::shared_ptr<INeuron>(i));
    }
}

CLayerBase::~CLayerBase()
{
    LOG(INFO, "Destructor called.");
}
