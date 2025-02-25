#include "CAFnRetDoubleParamDouble.h"
#include <functional>
#include <memory>

CAFnRetDoubleParamDouble::CAFnRetDoubleParamDouble()
{
}

CAFnRetDoubleParamDouble::~CAFnRetDoubleParamDouble()
{
}


std::function<double(double)> CAFnRetDoubleParamDouble::getActivationFn()
{
    return *m_activationFn.get();
}

void CAFnRetDoubleParamDouble::SetActivationFn(std::function<double(double)> activationFn)
{
    m_activationFn = std::make_unique<std::function<double(double)>>(activationFn);
}
