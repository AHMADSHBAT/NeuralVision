#include "CActivationFn.h"
#include <stdexcept>
#include <vector>
#include <memory>
#include "IActivation.h"
#include "IActivationFnProto.h"
#include "CAFnRetDoubleParamDouble.h"
#include "CAFnRetVectorParamVector.h"
#include "CAFnRetDoubleParamDoubleDouble.h"

CActivationFn::CActivationFn(std::string&& str)
{
    auto doubleDouble = dynamic_cast<CAFnRetDoubleParamDouble*>(m_activation.get());
    auto vectorVector = dynamic_cast<CAFnRetVectorParamVector*>(m_activation.get());
    auto doubleDoubleDouble = dynamic_cast<CAFnRetDoubleParamDoubleDouble*>(m_activation.get());

    if (doubleDouble) {
        m_activation = std::make_unique<CAFnRetDoubleParamDouble>(*doubleDouble);
    } else if (vectorVector) {
        m_activation = std::make_unique<CAFnRetVectorParamVector>(*vectorVector);
    } else {
        m_activation = std::make_unique<CAFnRetDoubleParamDoubleDouble>(*doubleDoubleDouble);
    }

    if (str == "LINEAR")
        m_activation.get()->SetActivationFn(Linear);
    else if (str == "SIGMOID")
        m_activation.get()->SetActivationFn(Sigmoid);
    else if (str == "TANH")
        m_activation.get()->SetActivationFn(Tanh);
    else if (str == "RELU")
        m_activation.get()->SetActivationFn(Relu);
    else if (str == "LEAKY_RELU")
        m_activation.get()->SetActivationFn(LeakyRelu);
    else if (str == "SOFTMAX")
        m_activation.get()->SetActivationFn(Softmax);
    else if (str == "ELU")
        m_activation.get()->SetActivationFn(Elu);
    else if (str == "SELU")
        m_activation.get()->SetActivationFn(Selu);
    else if (str == "SWISH")
        m_activation.get()->SetActivationFn(Swish);
    else if (str == "MISH")
        m_activation.get()->SetActivationFn(Mish);
    else if (str == "GELU")
        m_activation.get()->SetActivationFn(Gelu);
    else
        throw std::invalid_argument("Unknown activation function");
}


CActivationFn::~CActivationFn()
{
}

IActivationFnProto* CActivationFn::GetActivationFn() const
{
    return m_activation.get();
}

double CActivationFn::Linear(double x) {
    // Implementation here
}

double CActivationFn::Sigmoid(double x) {
    // Implementation here
}

double CActivationFn::Tanh(double x) {
    // Implementation here
}

double CActivationFn::Relu(double x) {
    // Implementation here
}

double CActivationFn::LeakyRelu(double x, double alpha) {
    // Implementation here
}

std::vector<double> CActivationFn::Softmax(const std::vector<double>& inputs) {
    // Implementation here
}

double CActivationFn::Elu(double x, double alpha) {
    // Implementation here
}

double CActivationFn::Selu(double x) {
    // Implementation here
}

double CActivationFn::Swish(double x) {
    // Implementation here
}

double CActivationFn::Mish(double x) {
    // Implementation here
}

double CActivationFn::Gelu(double x) {
    // Implementation here
}
