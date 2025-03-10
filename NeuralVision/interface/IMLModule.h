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
    virtual bool Train() = 0;
    virtual bool Predict() = 0;
    virtual double GetTotalOutput() = 0;

};