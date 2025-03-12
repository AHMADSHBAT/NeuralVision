#include <iostream>
#include "CVModule.h"
#include "CConv2D.h"


int main()
{
	std::vector<INeuron*> neurons =
	{
		new CNeuronBase(nullptr, 0.001, FnType::RELU),
		new CNeuronBase(nullptr, 0.001, FnType::RELU),
		new CNeuronBase(nullptr, 0.001, FnType::RELU)
	};

	std::vector<INeuron*> neurons1 =
	{
		new CNeuronBase(nullptr, 0.001, FnType::RELU),
		new CNeuronBase(nullptr, 0.001, FnType::RELU),
		new CNeuronBase(nullptr, 0.001, FnType::RELU)
	};

	CLayerBase* layer1 = new CConv2D(neurons);
	CLayerBase* layer2 = new CConv2D(neurons1);
	CVModule model({*layer1, *layer2});
	return 0;
}