#pragma once
#include "INeuron.h"
#include <functional>

class CNeuron : public INeuron
{
public:
    CNeuron(unsigned int, std::function<double(double)>);
    virtual ~CNeuron();

    virtual void SetInput(double input);
    virtual double GetInput();
    virtual void SetOutput(double output);
    virtual double GetOutput();
    virtual void SetWeight(double weight);
    virtual double GetWeight();
    virtual void SetBias(double bias);
    virtual double GetBias();
    virtual void SetLearningRate(double learningRate);
    virtual double GetLearningRate();
    virtual void SetActivationFunction(std::function<double(double)> activationFunction);
    virtual std::function<double(double)> GetActivationFunction();
    virtual void SetDerivativeActivationFunction(std::function<double(double)> derivativeActivationFunction);
    virtual std::function<double(double)> GetDerivativeActivationFunction();
    virtual void SetError(double error);
    virtual double GetError();
    virtual void SetDelta(double delta);
    virtual double GetDelta();
    virtual void SetSum(double sum);
    virtual double GetSum();
    virtual void SetBiasWeight(double biasWeight);
    virtual double GetBiasWeight();
    virtual void SetBiasDelta(double biasDelta);
    virtual double GetBiasDelta();
    virtual void SetBiasError(double biasError);
    virtual double GetBiasError();
    virtual void SetBiasOutput(double biasOutput);
    virtual double GetBiasOutput();
    virtual void SetBiasSum(double biasSum);
    virtual double GetBiasSum();
    virtual void SetBiasActivationFunction(std::function<double(double)> biasActivationFunction);
    virtual std::function<double(double)> GetBiasActivationFunction();
    virtual void SetBiasDerivativeActivationFunction(std::function<double(double)> biasDerivativeActivationFunction);
    virtual std::function<double(double)> GetBiasDerivativeActivationFunction();
    virtual void SetBiasLearningRate(double biasLearningRate);
    virtual double GetBiasLearningRate();

protected:
    double m_input;
    double m_output;
    double m_weight;
    double m_bias;
    double m_learningRate;
    double m_error;
    double m_delta;
    double m_sum;
    double m_biasWeight;
    double m_biasDelta;
    double m_biasOutput;
    double m_biasSum;
    double m_biasLearningRate;
    double m_biasError;
    std::function<double(double)> m_biasActivationFunction;
    std::function<double(double)> m_biasDerivativeActivationFunction;
    std::function<double(double)> m_activationFunction;
    std::function<double(double)> m_derivativeActivationFunction;
};
