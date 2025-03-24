#pragma once
#include <functional>
#include "INeuron.h"
#include "CActivationFn.h"

using VecDouble = std::vector<double>;
using VecINeuronPtr = std::vector<INeuron*>;

class CNeuronBase : public INeuron
{
public:
	CNeuronBase(std::vector<INeuron*>& connNeurons, std::vector<double>& weights, FnType fn);
	CNeuronBase(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, FnType fn);
	CNeuronBase(CNeuronBase&&) noexcept;
	CNeuronBase(CNeuronBase&);
	virtual ~CNeuronBase();


	virtual FnType getFnType();
	inline const std::vector<double>& GetWeight() const;
protected:
	std::unordered_map<INeuron*, std::vector<double>> m_NConnMap;
	std::vector<double> m_weights;
	std::vector<double> m_output;
	std::vector<double> m_input;
	double m_bias;
	double m_learningRate;
	FnType m_fnType;
};



inline const std::vector<double>& CNeuronBase::GetWeight() const
{
	return m_weights;
}
