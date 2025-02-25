#include "IMLModule.h"


IMLModule::IMLModule(std::initializer_list<ILayer> LayerList)
{
    m_layers.reserve(LayerList.size());
    for (auto& layer : LayerList)
    {
        m_layers.emplace_back(std::make_unique<ILayer>(std::move(layer)));
    }
}

IMLModule::~IMLModule()
{
}
