#pragma once
#include "INeuron.h"
#include "CActivationFn.h"
#include <functional>

using VecDouble = std::vector<double>;
using VecINeuronPtr = std::vector<INeuron*>;

class CNeuronBase : public INeuron
{
public:
	CNeuronBase(std::vector<INeuron*>& connNeurons, std::vector<double>& weights, FnType fn);
	CNeuronBase(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, FnType fn);
	CNeuronBase(std::vector<double>& weights, FnType fn);
	CNeuronBase(std::vector<double>&& weights, FnType fn);
	//CNeuronBase(CNeuronBase&&) noexcept;
	//CNeuronBase(CNeuronBase&);
	virtual ~CNeuronBase();


	virtual FnType getFnType();
	//virtual void SetInput(double input);
	//virtual double GetInput();
	//virtual void SetOutput(double output);
	//virtual double GetOutput();
	//virtual void SetWeight(double weight);
	//virtual double GetWeight();
	//virtual void SetBias(double bias);
	//virtual double GetBias();
	//virtual void SetLearningRate(double learningRate);
	//virtual bool SetNeuronConn();

protected:
	std::unordered_map<INeuron*, double> m_NConnMap;
	double m_input;
	double m_output;
	std::vector<double> m_weight;
	double m_bias;
	double m_learningRate;
	FnType m_fnType;
};
