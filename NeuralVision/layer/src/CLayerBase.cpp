#include "CLayerBase.h"
#include "CActivationFn.h"
#include "CNeuronBase.h"
#include	"CLogger.h"

CLayerBase::CLayerBase(unsigned int n, FnType fn)
{
    LOG(INFO, "Constructor called.");

    m_neurons.reserve(n); // Reserve memory to avoid multiple allocations
    for (unsigned int i = 0; i < n; i++)
    {
        m_neurons.emplace_back(std::move(CNeuronBase(nullptr, 0, fn)));
    }
}

CLayerBase::CLayerBase(std::vector<CNeuronBase>&& vecNeurons)
{
    m_neurons = std::move(vecNeurons);
}

CLayerBase::~CLayerBase()
{
    LOG(INFO, "Destructor called.");
}
