#include <functional>

class INeuron
{
public:
    virtual ~INeuron(); // Pure virtual destructor
    INeuron();
    virtual void SetInput(double input) = 0;
    virtual double GetInput() = 0;
    virtual void SetOutput(double output) = 0;
    virtual double GetOutput() = 0;
    virtual void SetWeight(double weight) = 0;
    virtual double GetWeight() = 0;
    virtual void SetBias(double bias) = 0;
    virtual double GetBias() = 0;
    virtual void SetLearningRate(double learningRate) = 0;
    virtual double GetLearningRate() = 0;
    virtual void SetActivationFunction(std::function<double(double)> activationFunction) = 0;
    virtual std::function<double(double)> GetActivationFunction() = 0;
    virtual void SetDerivativeActivationFunction(std::function<double(double)> derivativeActivationFunction) = 0;
    virtual std::function<double(double)> GetDerivativeActivationFunction() = 0;
    virtual void SetError(double error) = 0;
    virtual double GetError() = 0;
    virtual void SetDelta(double delta) = 0;
    virtual double GetDelta() = 0;
    virtual void SetSum(double sum) = 0;
    virtual double GetSum() = 0;
    virtual void SetBiasWeight(double biasWeight) = 0;
    virtual double GetBiasWeight() = 0;
    virtual void SetBiasDelta(double biasDelta) = 0;
    virtual double GetBiasDelta() = 0;
    virtual void SetBiasError(double biasError) = 0;
    virtual double GetBiasError() = 0;
    virtual void SetBiasOutput(double biasOutput) = 0;
    virtual double GetBiasOutput() = 0;
    virtual void SetBiasSum(double biasSum) = 0;
    virtual double GetBiasSum() = 0;
    virtual void SetBiasActivationFunction(std::function<double(double)> biasActivationFunction) = 0;
    virtual std::function<double(double)> GetBiasActivationFunction() = 0;
    virtual void SetBiasDerivativeActivationFunction(std::function<double(double)> biasDerivativeActivationFunction) = 0;
    virtual std::function<double(double)> GetBiasDerivativeActivationFunction() = 0;
    virtual void SetBiasLearningRate(double biasLearningRate) = 0;
    virtual double GetBiasLearningRate() = 0;
};
