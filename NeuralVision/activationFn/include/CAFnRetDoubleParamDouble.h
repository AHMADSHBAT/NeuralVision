#pragma once
#include "IActivationFnProto.h"
#include <memory>
#include <functional>


class CAFnRetDoubleParamDouble : public IActivationFnProto
{
public:
    CAFnRetDoubleParamDouble();
    virtual ~CAFnRetDoubleParamDouble();

    std::function<double(double)> getActivationFn();
    void SetActivationFn(std::function<double(double)> activationFn);

protected:
    std::unique_ptr<std::function<double(double)>> m_activationFn;
};

