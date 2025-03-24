#include "CConv2DNeuron.h"
#include <stdexcept>


CConv2DNeuron::CConv2DNeuron(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, unsigned int kernel)
	:CNeuronBase(std::move(connNeurons), std::move(weights), FnType::MAX_NO_FN_TYPE), m_kernel(kernel)
{
    // Ensure filter size is correct
    //if (m_kernel * m_kernel != m_weights.size()) {
    //    throw std::runtime_error("Invalid filter size for 1D weights array");
    //}

}

CConv2DNeuron::~CConv2DNeuron()
{
}

