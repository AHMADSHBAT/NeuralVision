#include "CNeuronBase.h"
#include "CActivationFn.h"
#include <stdexcept>
#include "CLogger.h"

CNeuronBase::CNeuronBase(std::vector<INeuron*>& connNeurons, std::vector<std::vector<double>>& weights, FnType fn)
	:m_input(0), m_output(0), m_weights(weights), m_bias(0), m_learningRate(0), m_fnType(fn)
{
	LOG(INFO, "CNeuronBase constructor called.");
	if (connNeurons.size() != weights.size()) {
		throw std::invalid_argument("connNeurons and weights must have the same size");
	}

	for (size_t i = 0; i < connNeurons.size(); ++i) {
		m_NConnMap[connNeurons[i]] = weights[i];
	}
}

CNeuronBase::CNeuronBase(std::vector<INeuron*>&& connNeurons, std::vector<std::vector<double>>&& weights, FnType fn)
	:m_input(0), m_output(std::move(std::vector<std::vector<double>>{})), m_weights(weights), m_bias(0), m_learningRate(0), m_fnType(fn)
{
	LOG(INFO, "CNeuronBase constructor called.");
	if (connNeurons.size() != weights.size()) {
		throw std::invalid_argument("connNeurons and weights must have the same size");
	}

	for (size_t i = 0; i < connNeurons.size(); ++i) {
		m_NConnMap[connNeurons[i]] = weights[i];
	}
}

CNeuronBase::CNeuronBase(CNeuronBase&&) noexcept
{
}

CNeuronBase::CNeuronBase(CNeuronBase&)
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

