#include "CNeuronBase.h"
#include "CActivationFn.h"

CNeuronBase::CNeuronBase(INeuron* nextConnNeuron, double weight, FnType fn)
	:m_input(0), m_output(0), m_weight(weight), m_bias(0), m_learningRate(0), m_fnType(fn)
{
	m_NConnMap[nextConnNeuron] = weight;
}

CNeuronBase::CNeuronBase(CNeuronBase&& other) noexcept
	:m_input(other.GetInput()), m_output(0), m_weight(0), m_bias(0), m_learningRate(0), m_fnType(std::move(other.getFnType()))
{
}

CNeuronBase::CNeuronBase(CNeuronBase& other)
	:m_input(other.GetInput()), m_output(0), m_weight(0), m_bias(0), m_learningRate(0), m_fnType(other.getFnType())
{
}


CNeuronBase::~CNeuronBase()
{
}

FnType CNeuronBase::getFnType()
{
	return m_fnType;
}


void CNeuronBase::SetInput(double input)
{
	m_input = input;
}

double CNeuronBase::GetInput()
{
	return m_input;
}

void CNeuronBase::SetOutput(double output)
{
	m_output = output;
}

double CNeuronBase::GetOutput()
{
	return m_output;
}

void CNeuronBase::SetWeight(double weight)
{
	m_weight = weight;
}

double CNeuronBase::GetWeight()
{
	return m_weight;
}

void CNeuronBase::SetBias(double bias)
{
	m_bias = bias;
}

double CNeuronBase::GetBias()
{
	return m_bias;
}

void CNeuronBase::SetLearningRate(double learningRate)
{
	m_learningRate = learningRate;
}

bool CNeuronBase::SetNeuronConn()
{
	return false;
}
