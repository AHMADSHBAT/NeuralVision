#include "CVModule.h"
#include "CLayerBase.h"
#include	"CLogger.h"
CVModule::CVModule(const std::initializer_list<CLayerBase>& layers) : CModuleBase(layers)
{
	LOG(INFO, "Constructor called.");

}


CVModule::~CVModule()
{
	LOG(INFO, "Destructor called.");

}


