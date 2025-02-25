#pragma once
#include "IActivation.h"
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>

class CAFnRetDoubleParamDouble;
class CAFnRetVectorParamVector;
class IActivationFnProto;


class CActivationFn : public IActivation
{
public:
    CActivationFn(std::string&&);
    virtual ~CActivationFn();

    IActivationFnProto* GetActivationFn() const;


private:
    std::unordered_map<std::string, std::function<double(double)>> activationMap;

private:
    static double Linear(double x);
    static double Sigmoid(double x);
    static double Tanh(double x);
    static double Relu(double x);
    static double LeakyRelu(double x, double alpha = 0.01);
    static std::vector<double> Softmax(const std::vector<double>& inputs);
    static double Elu(double x, double alpha = 1.0);
    static double Selu(double x);
    static double Swish(double x);
    static double Mish(double x);
    static double Gelu(double x);
};

