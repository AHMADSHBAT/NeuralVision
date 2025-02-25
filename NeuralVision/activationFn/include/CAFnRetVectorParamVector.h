#pragma once
#include "IActivationFnProto.h"
#include <vector>
#include <memory>
#include <functional>


class CAFnRetVectorParamVector : public IActivationFnProto
{

public:
    CAFnRetVectorParamVector();
    virtual ~CAFnRetVectorParamVector();

    std::function<std::vector<double>(const std::vector<double>&)> getActivationFn();

protected:
    std::unique_ptr<std::function<std::vector<double>(const std::vector<double>&)>> m_activationFn;
};

