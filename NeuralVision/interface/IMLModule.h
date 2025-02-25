#pragma once
#include <vector>
#include <memory>

class ILayer;
class IActivation;

class IMLModule
{
public:
    IMLModule() = delete;
    IMLModule(std::initializer_list<ILayer>);
    virtual ~IMLModule();
    virtual bool Train() = 0;
    virtual bool Predict() = 0;
    virtual double GetTotalOutput() = 0;
protected:
    std::vector<std::unique_ptr<ILayer>> m_layers;
};