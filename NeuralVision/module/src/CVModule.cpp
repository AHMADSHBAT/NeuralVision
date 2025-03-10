#include "CVModule.h"
#include "CLayerBase.h"

CVModule::CVModule(std::vector<CLayerBase>& layers) : CModuleBase(layers)
{
}


CVModule::CVModule(std::vector<CLayerBase>&& layers) : CModuleBase(std::move(layers))
{
}


CVModule::~CVModule()
{
}


