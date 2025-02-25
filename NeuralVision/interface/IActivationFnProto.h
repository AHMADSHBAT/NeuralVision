#pragma once
#include <memory>
#include <functional>
#include <vector>



class IActivationFnProto
{
public:
    IActivationFnProto();
    virtual ~IActivationFnProto();
    virtual void SetActivationFn(std::function<double(double, double)> activationFn);
    virtual void SetActivationFn(std::function<double(double)> activationFn);
    virtual void SetActivationFn(std::function<std::vector<double>(const std::vector<double>&)> activationFn);
};

