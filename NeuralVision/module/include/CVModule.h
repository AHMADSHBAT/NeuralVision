#pragma once
#include "IMLModule.h"
#include <vector>
#include "CModuleBase.h"
#include "CActivationFn.h"
#include "CLayerBase.h"
#include "CNeuronBase.h"

class INeuron;
class ILayer;
class IMLModule;
class CConv2DLayer;
class CLayerBase;
class CActivationFn;
class CModuleBase;
class NeuronBase;

class CVModule : public CModuleBase
{
public:
    CVModule(const std::initializer_list<CLayerBase>& layers);
    ~CVModule();

};

