#include "CAFnRetVectorParamVector.h"
#include <functional>


CAFnRetVectorParamVector::CAFnRetVectorParamVector()
    : m_activationFn(nullptr)
{
}


CAFnRetVectorParamVector::~CAFnRetVectorParamVector()
{
}

std::function<std::vector<double>(const std::vector<double>&)> CAFnRetVectorParamVector::getActivationFn()
{
    return *m_activationFn.get();
}

