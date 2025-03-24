#include <iostream>
#include "CVModule.h"
#include "CConv2DLayer.h"
#include "CImage2RawConv.h"
#include "CLogger.h"
int main()
{

	CImage2RawConv image("img.png");
	std::vector<float> vec = image.getRawData();
	LOG(INFO, "value at index: %d is: %d", image.getWidth(), image.getHeight());

	for (size_t i = 0; i < vec.size(); i++)
	{
		//LOG(INFO, "value at index: %d is: %f",i, vec[i]);
	}
	//INeuron* n1l1 = new CNeuronBase(VecDouble{ 1.0 }, FnType::RELU);
	//INeuron* n2l1 = new CNeuronBase(VecDouble{ 1.0 }, FnType::RELU);
	//INeuron* n3l1 = new CNeuronBase(VecDouble{ 1.0 }, FnType::RELU);


	//INeuron* n1l2 = new CNeuronBase(std::vector<INeuron*>{ n1l1, n2l1, n3l1 }, { 0.001, 0.001, 0.001 }, FnType::RELU);
	//INeuron* n2l2 = new CNeuronBase(std::vector<INeuron*>{ n1l1, n2l1, n3l1 }, { 0.001, 0.001, 0.001 }, FnType::RELU);
	//INeuron* n3l2 = new CNeuronBase(std::vector<INeuron*>{ n1l1, n2l1, n3l1 }, { 0.001, 0.001, 0.001 }, FnType::RELU);


	//std::vector<INeuron*> neurons =
	//{
	//	n1l1,
	//	n2l1,
	//	n3l1
	//};

	//std::vector<INeuron*> neurons1 =
	//{
	//	n1l2,
	//	n2l2,
	//	n3l2
	//};

	//CLayerBase* layer1 = new CConv2DLayer(neurons);
	//CLayerBase* layer2 = new CConv2DLayer(neurons1);
	//CVModule model({ *layer1, *layer2 });
	std::cin.get();
	return 0;
}