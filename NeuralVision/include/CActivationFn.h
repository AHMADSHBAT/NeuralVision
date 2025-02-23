#pragma once
#include "IActivation.h"
#include <memory>
#include <functional>
#include <string>
class CActivationFn : public IActivation
{
public:
    CActivationFn(std::string&&);
    virtual ~CActivationFn();

    std::function<double(double)> GetActivationFn(std::string&&) const;

private:
    static void Linear();
    static void Sigmoid();
    static void Tanh();
    static void Relu();
    static void LeakyRelu();
    static void Softmax();
    static void Elu();
    static void Selu();
    static void Swish();
    static void Mish();
    static void Gelu();
};

