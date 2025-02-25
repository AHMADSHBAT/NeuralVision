#include "CNeuralLayer.h"
#include "CActivationFn.h"


CNeuralLayer::CNeuralLayer(unsigned int neuronNum, std::string&& fnName) : ILayer(neuronNum, CActivationFn(std::move(fnName)))
{
}


CNeuralLayer::~CNeuralLayer()
{
}
