#pragma once
#include <functional>
#include <memory>
#include "IActivationFnProto.h"



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

    virtual IActivationFnProto* GetActivationFn() const = 0;

protected:
    std::unique_ptr<IActivationFnProto> m_activation;


};

