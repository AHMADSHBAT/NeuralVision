#pragma once
#include "CNeuronBase.h"



class CConv2DNeuron : public CNeuronBase
{
public:
	CConv2DNeuron(std::vector<INeuron*>&& connNeurons, std::vector<double>&& weights, unsigned int kernel);
	~CConv2DNeuron();


	inline void Compute(const std::vector<std::vector<double>>&);

protected:
    unsigned int m_kernel;
};





inline void CConv2DNeuron::Compute(const std::vector<std::vector<double>>& inputs)
{
    unsigned int input_height = inputs.size();
    unsigned int input_width = inputs[0].size();

    // Calculate output dimensions (valid convolution)
    unsigned int output_height = input_height - m_kernel + 1;
    unsigned int output_width = input_width - m_kernel + 1;
    unsigned int output_size = output_height * output_width; // 1D output size

    // Initialize 1D output array
    m_output.resize(output_size, 0.0);

    // Perform the convolution
    for (unsigned int x = 0; x < output_height; x++) {
        for (unsigned int y = 0; y < output_width; y++) {
            double sum = 0.0;
            for (unsigned int fx = 0; fx < m_kernel; fx++) {
                for (unsigned int fy = 0; fy < m_kernel; fy++) {
                    unsigned int weight_index = fx * m_kernel + fy;  // Map 2D kernel to 1D index
                    sum += inputs[x + fx][y + fy] * m_weights[weight_index];
                }
            }
            unsigned int output_index = x * output_width + y; // Map 2D output index to 1D
            m_output[output_index] = sum;
        }
    }
}