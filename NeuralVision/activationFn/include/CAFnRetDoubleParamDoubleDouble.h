#pragma once
#include "IActivationFnProto.h"
#include <memory>
#include <functional>
class CAFnRetDoubleParamDoubleDouble : public IActivationFnProto
{
public:
    CAFnRetDoubleParamDoubleDouble();
    virtual ~CAFnRetDoubleParamDoubleDouble();

    std::function<double(double, double)> getActivationFn();
    void SetActivationFn(std::unique_ptr<std::function<double(double, double)>> activationFn);

protected:
    std::unique_ptr<std::function<double(double, double)>> m_activationFn;
};

