#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include<vector>
#include "NoValidPointerFound.h"
#include "IdNotFoundException.h"
#include<stdexcept>

using Container=std::vector<Engine*>;
void createObjects(Container& e);
int AverageHorsePower(const Container& e);
float FindTorqueById(const Container& e, unsigned int id);
int FindHorsepowerForMinTorqueEngine(const Container& e);

// void DeallocateMemory(Co)

#endif // FUNCTIONALITIES_H
