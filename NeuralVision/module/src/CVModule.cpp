#include "CVModule.h"
#include "ILayer.h"

CVModule::CVModule(std::initializer_list<ILayer> layers) : IMLModule(layers)
{
}

CVModule::~CVModule()
{
}


