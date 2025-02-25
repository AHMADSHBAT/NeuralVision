#pragma once
#include <vector>
#include <memory>


class IActivation;
class INeuron;


class ILayer
{
public:
    ILayer(unsigned int, const IActivation&);
    virtual ~ILayer();


protected:
    std::vector<std::unique_ptr<INeuron>> m_neurons;

};
