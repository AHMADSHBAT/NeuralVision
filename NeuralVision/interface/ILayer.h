#pragma once
#include <vector>
#include <memory>


class INeuron;


class ILayer
{
public:
    ILayer(unsigned int);
    virtual ~ILayer();


protected:
    std::vector<std::unique_ptr<INeuron>> m_neurons;

};
