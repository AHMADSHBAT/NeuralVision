#include "CActivationFn.h"
#include <stdexcept>

CActivationFn::CActivationFn(std::string&& str)
{
    if (str == "LINEAR")
        m_activation = std::make_shared<std::function<double(double)>>(Linear);
    else if (str == "SIGMOID")
        m_activation = std::make_shared<std::function<double(double)>>(Sigmoid);
    else if (str == "TANH")
        m_activation = std::make_shared<std::function<double(double)>>(Tanh);
    else if (str == "RELU")
        m_activation = std::make_shared<std::function<double(double)>>(Relu);
    else if (str == "LEAKY_RELU")
        m_activation = std::make_shared<std::function<double(double)>>(LeakyRelu);
    else if (str == "SOFTMAX")
        m_activation = std::make_shared<std::function<double(double)>>(Softmax);
    else if (str == "ELU")
        m_activation = std::make_shared<std::function<double(double)>>(Elu);
    else if (str == "SELU")
        m_activation = std::make_shared<std::function<double(double)>>(Selu);
    else if (str == "SWISH")
        m_activation = std::make_shared<std::function<double(double)>>(Swish);
    else if (str == "MISH")
        m_activation = std::make_shared<std::function<double(double)>>(Mish);
    else if (str == "GELU")
        m_activation = std::make_shared<std::function<double(double)>>(Gelu);
    else
        throw std::invalid_argument("Unknown activation function");
}


CActivationFn::~CActivationFn()
{
}

std::function<double(double)> CActivationFn::GetActivationFn(std::string&&) const
{
    return *m_activation.get();
}

void CActivationFn::Linear() {
    // Implementation here
}

void CActivationFn::Sigmoid() {
    // Implementation here
}

void CActivationFn::Tanh() {
    // Implementation here
}

void CActivationFn::Relu() {
    // Implementation here
}

void CActivationFn::LeakyRelu() {
    // Implementation here
}

void CActivationFn::Softmax() {
    // Implementation here
}

void CActivationFn::Elu() {
    // Implementation here
}

void CActivationFn::Selu() {
    // Implementation here
}

void CActivationFn::Swish() {
    // Implementation here
}

void CActivationFn::Mish() {
    // Implementation here
}

void CActivationFn::Gelu() {
    // Implementation here
}
