#include "CNeuronBase.h"
#include "CActivationFn.h"
#include <stdexcept>
#include "CLogger.h"



// Constructor for lvalue references
CNeuronBase::CNeuronBase(std::vector<INeuron*>& connNeurons, std::vector<double>& weights, FnType fn)
    : m_connectedNeurons(connNeurons), // Copy the lvalue
    m_weights(weights),              // Copy the lvalue
    m_input(),                       // Default initialize
    m_output(),                      // Default initialize
    m_bias(0),
    m_learningRate(0),
    m_fnType(fn) {
    LOG(INFO, "CNeuronBase constructor called.");

}

// Constructor for rvalue references
CNeuronBase::CNeuronBase(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, FnType fn)
    : m_connectedNeurons(std::move(connNeurons)), // Move the rvalue
    m_weights(std::move(weights)),             // Move the rvalue
    m_input(),                                 // Default initialize
    m_output(),                                // Default initialize
    m_bias(0),
    m_learningRate(0),
    m_fnType(fn) {
    LOG(INFO, "CNeuronBase constructor called.");
}
CNeuronBase::CNeuronBase(std::vector<double>& weights, FnType fn)
{
}

CNeuronBase::CNeuronBase(std::vector<double>&& weights, FnType fn)
    :m_input(0), m_output(0), m_weights(std::move(weights)), m_bias(0), m_learningRate(0), m_fnType(fn)
{
}


CNeuronBase::~CNeuronBase()
{
	LOG(INFO, "CNeuronBase destructor called.");
}

FnType CNeuronBase::getFnType()
{
	LOG(INFO, "CNeuronBase::getFnType called.");
	return m_fnType;
}

