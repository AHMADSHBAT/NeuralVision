#include "CNeuron.h"

CNeuron::CNeuron(unsigned int input, std::function<double(double)> activationFn)
    : m_input(input), m_output(0.0), m_weight(0.0), m_bias(0.0), m_learningRate(0.0),
    m_activationFunction(activationFn), m_derivativeActivationFunction(nullptr),
    m_error(0.0), m_delta(0.0), m_sum(0.0),
    m_biasWeight(0.0), m_biasDelta(0.0), m_biasError(0.0), m_biasOutput(0.0), m_biasSum(0.0),
    m_biasActivationFunction(nullptr), m_biasDerivativeActivationFunction(nullptr), m_biasLearningRate(0.0)
{
}

CNeuron::~CNeuron()
{
}

void CNeuron::SetInput(double input)
{
    m_input = input;
}

double CNeuron::GetInput()
{
    return m_input;
}

void CNeuron::SetOutput(double output)
{
    m_output = output;
}

double CNeuron::GetOutput()
{
    return m_output;
}

void CNeuron::SetWeight(double weight)
{
    m_weight = weight;
}

double CNeuron::GetWeight()
{
    return m_weight;
}

void CNeuron::SetBias(double bias)
{
    m_bias = bias;
}

double CNeuron::GetBias()
{
    return m_bias;
}

void CNeuron::SetLearningRate(double learningRate)
{
    m_learningRate = learningRate;
}

double CNeuron::GetLearningRate()
{
    return m_learningRate;
}

void CNeuron::SetActivationFunction(std::function<double(double)> activationFunction)
{
    m_activationFunction = activationFunction;
}

std::function<double(double)> CNeuron::GetActivationFunction()
{
    return m_activationFunction;
}

void CNeuron::SetDerivativeActivationFunction(std::function<double(double)> derivativeActivationFunction)
{
    m_derivativeActivationFunction = derivativeActivationFunction;
}

std::function<double(double)> CNeuron::GetDerivativeActivationFunction()
{
    return m_derivativeActivationFunction;
}

void CNeuron::SetError(double error)
{
    m_error = error;
}

double CNeuron::GetError()
{
    return m_error;
}

void CNeuron::SetDelta(double delta)
{
    m_delta = delta;
}

double CNeuron::GetDelta()
{
    return m_delta;
}

void CNeuron::SetSum(double sum)
{
    m_sum = sum;
}

double CNeuron::GetSum()
{
    return m_sum;
}

void CNeuron::SetBiasWeight(double biasWeight)
{
    m_biasWeight = biasWeight;
}

double CNeuron::GetBiasWeight()
{
    return m_biasWeight;
}

void CNeuron::SetBiasDelta(double biasDelta)
{
    m_biasDelta = biasDelta;
}

double CNeuron::GetBiasDelta()
{
    return m_biasDelta;
}

void CNeuron::SetBiasError(double biasError)
{
    m_biasError = biasError;
}

double CNeuron::GetBiasError()
{
    return m_biasError;
}

void CNeuron::SetBiasOutput(double biasOutput)
{
    m_biasOutput = biasOutput;
}

double CNeuron::GetBiasOutput()
{
    return m_biasOutput;
}

void CNeuron::SetBiasSum(double biasSum)
{
    m_biasSum = biasSum;
}

double CNeuron::GetBiasSum()
{
    return m_biasSum;
}

void CNeuron::SetBiasActivationFunction(std::function<double(double)> biasActivationFunction)
{
    m_biasActivationFunction = biasActivationFunction;
}

std::function<double(double)> CNeuron::GetBiasActivationFunction()
{
    return m_biasActivationFunction;
}

void CNeuron::SetBiasDerivativeActivationFunction(std::function<double(double)> biasDerivativeActivationFunction)
{
    m_biasDerivativeActivationFunction = biasDerivativeActivationFunction;
}

std::function<double(double)> CNeuron::GetBiasDerivativeActivationFunction()
{
    return m_biasDerivativeActivationFunction;
}

void CNeuron::SetBiasLearningRate(double biasLearningRate)
{
    m_biasLearningRate = biasLearningRate;
}

double CNeuron::GetBiasLearningRate()
{
    return m_biasLearningRate;
}
