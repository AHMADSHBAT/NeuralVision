#include "ILayer.h"
#include "CNeuron.h"
#include "IActivation.h"

ILayer::ILayer(unsigned int num,const IActivation& fn)
{
    m_neurons.reserve(num); // Reserve memory to avoid multiple allocations
    for (unsigned int i = 0; i < num; i++)
    {
        m_neurons.emplace_back(std::make_unique<CNeuron>(num, fn.GetActivationFn()));
    }
}


ILayer::~ILayer()
{
}
