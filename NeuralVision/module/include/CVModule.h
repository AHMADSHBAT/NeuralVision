#pragma once
#include "IMLModule.h"
class CVModule : public IMLModule
{
public:
    CVModule(std::initializer_list<ILayer> layers);
    ~CVModule();

};

