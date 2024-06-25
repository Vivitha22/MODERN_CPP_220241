#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H


#include "EvCar.h"
#include "ICECar.h"
#include "Car.h"
#include<vector>

using container= std::vector<Car*>;

void createObjects(container& c);
void ShowDetails(container& c,int id);
void Deallocate(container& c);

#endif // FUNCTIONALITY_H
