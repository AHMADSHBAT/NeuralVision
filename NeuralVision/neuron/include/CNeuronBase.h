#pragma once
#include "INeuron.h"
#include "CActivationFn.h"
#include <functional>

class CNeuronBase : public INeuron
{
public:
    CNeuronBase(unsigned int, FnType);
    CNeuronBase(CNeuronBase&&) noexcept;
    CNeuronBase(CNeuronBase&);
    virtual ~CNeuronBase();


    virtual FnType getFnType();
    virtual void SetInput(double input);
    virtual double GetInput();
    virtual void SetOutput(double output);
    virtual double GetOutput();
    virtual void SetWeight(double weight);
    virtual double GetWeight();
    virtual void SetBias(double bias);
    virtual double GetBias();
    virtual void SetLearningRate(double learningRate);


protected:
    double m_input;
    double m_output;
    double m_weight;
    double m_bias;
    double m_learningRate;
    FnType m_fnType;
};
