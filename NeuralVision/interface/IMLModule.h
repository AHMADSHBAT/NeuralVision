#pragma once
#include <vector>
#include <memory>

class ILayer;
class IActivation;

class IMLModule
{
public:
    IMLModule();
    virtual ~IMLModule();
    virtual bool Dense(unsigned int, IActivation&) = 0;
    virtual bool Conv2D(unsigned int, unsigned int, IActivation&) = 0;
    virtual bool MaxPooling2D(unsigned int, unsigned int) = 0;
    virtual bool LSTM(unsigned int, IActivation&) = 0;
    virtual bool Dropout(unsigned int, float) = 0;
    virtual bool GRU(unsigned int, IActivation&) = 0;

protected:
    std::vector<std::unique_ptr<ILayer>> m_layers;
};

