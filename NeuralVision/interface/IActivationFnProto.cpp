#include "IActivationFnProto.h"
#include <functional>
#include <vector>


IActivationFnProto::IActivationFnProto()
{
}

IActivationFnProto::~IActivationFnProto()
{
}

void IActivationFnProto::SetActivationFn(std::function<double(double, double)> activationFn)
{
}

void IActivationFnProto::SetActivationFn(std::function<double(double)> activationFn)
{
}

void IActivationFnProto::SetActivationFn(std::function<std::vector<double>(const std::vector<double>&)> activationFn)
{
}



