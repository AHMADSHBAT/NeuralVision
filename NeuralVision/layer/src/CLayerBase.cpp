#include "CLayerBase.h"
#include "CActivationFn.h"
#include "CNeuronBase.h"

CLayerBase::CLayerBase(unsigned int n, FnType fn)
{
    m_neurons.reserve(n); // Reserve memory to avoid multiple allocations
    for (unsigned int i = 0; i < n; i++)
    {
        m_neurons.emplace_back(std::move(CNeuronBase(n, fn)));
    }
}

CLayerBase::~CLayerBase()
{
}
