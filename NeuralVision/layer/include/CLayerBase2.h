#pragma once
#include <vector>
#include <utility>
#include <memory>
class INeuron;
enum class FnType;

class CLayerBase2
{
public:

	CLayerBase2(std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>&& vec, FnType fn);
	CLayerBase2(const std::vector<std::pair<std::shared_ptr<INeuron>, std::vector<std::shared_ptr<INeuron>>>>& vec, FnType fn);

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

