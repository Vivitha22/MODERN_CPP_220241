#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "IdNotFoundException.h"
#include<stdexcept>

void createObjects(Engine **e);
void AverageHorsePower(Engine **e, int size);
void FindTorqueById(Engine **e, int size, int id);
void FindHorsepowerForMinTorqueEngine(Engine **e, int size);

#endif // FUNCTIONALITIES_H
