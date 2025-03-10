#include "CActivationFn.h"
#include <stdexcept>
#include <vector>
#include <memory>

CActivationFn::CActivationFn(FnType fn)
{
	switch (fn)
	{
	case FnType::LINEAR:
		m_activationMapDD[(unsigned int)fn] = Linear;
		break;
	case FnType::SIGMOID:
		m_activationMapDD[(unsigned int)fn] = Sigmoid;
		break;
	case FnType::TANH:
		m_activationMapDD[(unsigned int)fn] = Tanh;
		break;
	case FnType::RELU:
		m_activationMapDD[(unsigned int)fn] = Relu;
		break;
	case FnType::LEAKY_RELU:
		m_activationMapDD2[(unsigned int)fn] = LeakyRelu;
		break;
	case FnType::SOFTMAX:
		m_activationMapVD[(unsigned int)fn] = Softmax;
		break;
	case FnType::ELU:
		m_activationMapDD2[(unsigned int)fn] = Elu;
		break;
	case FnType::SELU:
		m_activationMapDD[(unsigned int)fn] = Selu;
		break;
	case FnType::SWISH:
		m_activationMapDD[(unsigned int)fn] = Swish;
		break;
	case FnType::MISH:
		m_activationMapDD[(unsigned int)fn] = Mish;
		break;
	case FnType::GELU:
		m_activationMapDD[(unsigned int)fn] = Gelu;
		break;
	default:
		throw std::invalid_argument("Invalid activation function type");
	}
}


CActivationFn::~CActivationFn()
{
}
double CActivationFn::Linear(double x) {
	return x;
}

double CActivationFn::Sigmoid(double x) {
	return 1.0 / (1.0 + std::exp(-x));
}

double CActivationFn::Tanh(double x) {
	return std::tanh(x);
}

double CActivationFn::Relu(double x) {
	return (x > 0) ? x : 0;
}

double CActivationFn::LeakyRelu(double x, double alpha) {
	return (x > 0) ? x : alpha * x;
}

std::vector<double> CActivationFn::Softmax(const std::vector<double>& inputs) {
	std::vector<double> output(inputs.size());
	double maxInput = *std::max_element(inputs.begin(), inputs.end());
	double sum = 0.0;

	for (double x : inputs) {
		sum += std::exp(x - maxInput);
	}

	for (size_t i = 0; i < inputs.size(); i++) {
		output[i] = std::exp(inputs[i] - maxInput) / sum;
	}

	return output;
}

double CActivationFn::Elu(double x, double alpha) {
	return (x >= 0) ? x : alpha * (std::exp(x) - 1);
}

double CActivationFn::Selu(double x) {
	constexpr double lambda = 1.0507;
	constexpr double alpha = 1.67326;
	return lambda * ((x >= 0) ? x : alpha * (std::exp(x) - 1));
}

double CActivationFn::Swish(double x) {
	return x / (1.0 + std::exp(-x));
}

double CActivationFn::Mish(double x) {
	return x * std::tanh(std::log1p(std::exp(x)));
}

double CActivationFn::Gelu(double x) {
	return 0.5 * x * (1.0 + std::tanh(std::sqrt(2.0 / M_PI) * (x + 0.044715 * std::pow(x, 3))));
}
