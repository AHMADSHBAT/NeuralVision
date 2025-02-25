#include "CConv2D.h"


CConv2D::CConv2D(unsigned int n, std::string&& name) : CNeuralLayer(n, std::move(name))
{
}

CConv2D::~CConv2D()
{
}
