#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include<vector>
#include "NoValidPointerFound.h"
#include "IdNotFoundException.h"
#include<stdexcept>

void createObjects(std::vector<Engine*>& e);
int AverageHorsePower(const std::vector<Engine*>& e);
float FindTorqueById(const std::vector<Engine*>& e, unsigned int id);
int FindHorsepowerForMinTorqueEngine(const std::vector<Engine*>& e);
void Deallocate(std::vector<Engine*>& e);

#endif // FUNCTIONALITIES_H
