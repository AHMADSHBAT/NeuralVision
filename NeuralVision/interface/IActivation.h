#pragma once
#include <functional>
#include <memory>

enum EFn
{
    LINEAR = 0U,
    SIGMOID = 1U,
    TANH = 2U,
    RELU = 3U,
    LEAKY_RELU = 4U,
    SOFTMAX = 5U,
    ELU = 6U,
    SELU = 7U,
    SWISH = 8U,
    MISH = 9U,
    GELU = 10U,
};


class IActivation
{
public:

    IActivation();
    virtual ~IActivation();

protected:
    std::shared_ptr<std::function<double(double)>> m_activation;


};

