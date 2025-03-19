#pragma once
#include <vector>
#include "ILayer.h"

class CNeuronBase;
class INeuron;

class CLayerBase : public ILayer
{
public:

	CLayerBase(std::vector<INeuron*>&& vecNeurons);
	CLayerBase(const std::vector<INeuron*>& vecNeurons);
    CLayerBase(std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>&& vec, FnType fn);
    CLayerBase(std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>& vec, FnType fn);
	virtual ~CLayerBase();


protected:
    // Define a vector to store pairs of neurons
    std::vector<
        std::pair<
        std::shared_ptr<INeuron>,         // The first element: A shared pointer to a single neuron
        std::vector<std::shared_ptr<INeuron>> // The second element: A vector of shared pointers to connected neurons
        >
    > m_neurons; // The main vector storing neuron connections

    FnType m_fn;
};

