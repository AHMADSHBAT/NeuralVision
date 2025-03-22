#include "CLayerBase2.h"
#include "CLogger.h"


CLayerBase2::CLayerBase2(std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>&& vec, FnType fn)
    : m_fn(fn), m_neurons(std::move(vec))  // Explicitly move
{
    LOG(INFO, "Move Constructor called.");
}

CLayerBase2::CLayerBase2(const std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>& vec, FnType fn)
    : m_fn(fn), m_neurons(vec)  // Copy explicitly
{
    LOG(INFO, "Copy Constructor called.");
}