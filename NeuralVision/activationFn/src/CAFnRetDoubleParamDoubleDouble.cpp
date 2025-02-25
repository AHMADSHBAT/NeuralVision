#include "CAFnRetDoubleParamDoubleDouble.h"
#include "IActivationFnProto.h"
#include <functional>
#include <memory>



CAFnRetDoubleParamDoubleDouble::CAFnRetDoubleParamDoubleDouble()
    :m_activationFn(nullptr)
{
}

CAFnRetDoubleParamDoubleDouble::~CAFnRetDoubleParamDoubleDouble()
{
}

std::function<double(double, double)> CAFnRetDoubleParamDoubleDouble::getActivationFn()
{
    return *m_activationFn.get(); 
}

void CAFnRetDoubleParamDoubleDouble::SetActivationFn(std::unique_ptr<std::function<double(double, double)>> activationFn)
{
    m_activationFn = std::move(activationFn);
}

