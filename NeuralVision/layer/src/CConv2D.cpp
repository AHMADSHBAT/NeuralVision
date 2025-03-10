#include "CConv2D.h"
#include "CLogger.h"

CConv2D::CConv2D(unsigned int n, FnType fn) : CLayerBase(n, fn)
{
	LOG(INFO, "Constructor called.");
}

CConv2D::~CConv2D()
{
    LOG(INFO, "Destructor called.");
}
