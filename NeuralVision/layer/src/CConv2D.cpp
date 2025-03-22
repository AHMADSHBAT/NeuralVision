#include "CConv2D.h"
#include "CLogger.h"
#include "CNeuronBase.h"


CConv2D::CConv2D(std::vector<INeuron*>&& vecNeurons) : CLayerBase(std::move(vecNeurons))
{
}

CConv2D::CConv2D(const std::vector<INeuron*>& vecNeurons) : CLayerBase(vecNeurons)
{
}

CConv2D::~CConv2D()
{
    LOG(INFO, "Destructor called.");
}
