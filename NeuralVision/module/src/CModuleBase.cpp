#include "CModuleBase.h"
#include	"CLayerBase.h"
#include	"CLogger.h"

CModuleBase::CModuleBase(const std::initializer_list<CLayerBase>& layers)
{
    LOG(INFO, "Constructor called.");

    m_layers.reserve(layers.size());
    for (auto& layer : layers)
    {
        m_layers.emplace_back(std::move(layer));
    }
}


CModuleBase::~CModuleBase()
{
    LOG(INFO, "Destructor called.");

}

bool CModuleBase::Train()
{
    return false;
}


bool CModuleBase::Predict()
{
    return false;
}


double CModuleBase::GetTotalOutput()
{
    return false;
}


