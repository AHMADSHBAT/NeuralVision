#include "CModuleBase.h"
#include	"CLayerBase.h"
CModuleBase::CModuleBase(std::vector<CLayerBase>&& layers)
{
    m_layers.reserve(layers.size());
    for (auto& layer : layers)
    {
        m_layers.emplace_back(std::move(layer));
    }
}

CModuleBase::CModuleBase(std::vector<CLayerBase>& layers)
{
    m_layers.reserve(layers.size());
    for (auto& layer : layers)
    {
        m_layers.emplace_back(layer);
    }
}

CModuleBase::~CModuleBase()
{
}

