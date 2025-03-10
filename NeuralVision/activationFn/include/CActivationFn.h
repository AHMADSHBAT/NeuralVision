#pragma once
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using CAFnRetDoubleParamDouble = std::function<double(double)>;
using CAFnRetVectorParamVector = std::function<std::vector<double>(const std::vector<double>&)>;
using CAFnRetDoubleParamDouble2 = std::function<double(double, double)>;


enum class FnType
{
	LINEAR = 0U,
	SIGMOID = 1U,
	TANH = 2U,
	RELU = 3U,
	LEAKY_RELU = 4U,
	SOFTMAX = 5U,
	ELU = 6U,
	SELU = 7U,
	SWISH = 8U,
	MISH = 9U,
	GELU = 10U,
	MAX = 11U
};


class CActivationFn
{
public:
	CActivationFn(FnType);
	virtual ~CActivationFn();


private:
	std::unordered_map<std::string, std::function<double(double)>> activationMap;

private:
	static double Linear(double x);
	static double Sigmoid(double x);
	static double Tanh(double x);
	static double Relu(double x);
	static double LeakyRelu(double x, double alpha = 0.01);
	static std::vector<double> Softmax(const std::vector<double>& inputs);
	static double Elu(double x, double alpha = 1.0);
	static double Selu(double x);
	static double Swish(double x);
	static double Mish(double x);
	static double Gelu(double x);

protected:
	std::unordered_map<unsigned int, std::function<double(double)>> m_activationMapDD;
	std::unordered_map<unsigned int, std::function<std::vector<double>(const std::vector<double>&)>> m_activationMapVD;
	std::unordered_map<unsigned int, std::function<double(double, double)>> m_activationMapDD2;
};

