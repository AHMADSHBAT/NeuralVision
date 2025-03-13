#include "CNeuronBase.h"
#include "CActivationFn.h"
#include <stdexcept>

CNeuronBase::CNeuronBase(std::vector<INeuron*>& connNeurons, std::vector<double>& weights, FnType fn)
	:m_input(0), m_output(0), m_weight(weights), m_bias(0), m_learningRate(0), m_fnType(fn)
{
	if (connNeurons.size() != weights.size()) {
		throw std::invalid_argument("connNeurons and weights must have the same size");
	}

	for (size_t i = 0; i < connNeurons.size(); ++i) {
		m_NConnMap[connNeurons[i]] = weights[i];
	}
}

CNeuronBase::CNeuronBase(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, FnType fn)
	:m_input(0), m_output(0), m_weight(weights), m_bias(0), m_learningRate(0), m_fnType(fn)
{
	if (connNeurons.size() != weights.size()) {
		throw std::invalid_argument("connNeurons and weights must have the same size");
	}

	for (size_t i = 0; i < connNeurons.size(); ++i) {
		m_NConnMap[connNeurons[i]] = weights[i];
	}
}


CNeuronBase::CNeuronBase(std::vector<double>& weights, FnType fn)
	:m_input(0), m_output(0), m_weight(weights), m_bias(0), m_learningRate(0), m_fnType(fn)
{
}

CNeuronBase::CNeuronBase(std::vector<double>&& weights, FnType fn)
	:m_input(0), m_output(0), m_weight(std::move(weights)), m_bias(0), m_learningRate(0), m_fnType(fn)
{
}

//CNeuronBase::CNeuronBase(CNeuronBase&& other) noexcept
//	:m_input(other.GetInput()), m_output(0), m_weight(0), m_bias(0), m_learningRate(0), m_fnType(std::move(other.getFnType()))
//{
//}
//
//CNeuronBase::CNeuronBase(CNeuronBase& other)
//	:m_input(other.GetInput()), m_output(0), m_weight(0), m_bias(0), m_learningRate(0), m_fnType(other.getFnType())
//{
//}


CNeuronBase::~CNeuronBase()
{
}

FnType CNeuronBase::getFnType()
{
	return m_fnType;
}

//
//void CNeuronBase::SetInput(double input)
//{
//	m_input = input;
//}
//
//double CNeuronBase::GetInput()
//{
//	return m_input;
//}
//
//void CNeuronBase::SetOutput(double output)
//{
//	m_output = output;
//}
//
//double CNeuronBase::GetOutput()
//{
//	return m_output;
//}
//
//void CNeuronBase::SetWeight(double weight)
//{
//	m_weight = weight;
//}
//
//double CNeuronBase::GetWeight()
//{
//	return m_weight;
//}
//
//void CNeuronBase::SetBias(double bias)
//{
//	m_bias = bias;
//}
//
//double CNeuronBase::GetBias()
//{
//	return m_bias;
//}
//
//void CNeuronBase::SetLearningRate(double learningRate)
//{
//	m_learningRate = learningRate;
//}
//
//bool CNeuronBase::SetNeuronConn()
//{
//	return false;
//}
