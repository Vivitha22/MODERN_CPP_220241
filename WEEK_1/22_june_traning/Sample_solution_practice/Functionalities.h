#include "Engine.h"
#include<vector>
#include "IdNotFoundException.h"
#include"NoValidPointerFound.h"

void createObjects(std::vector<Engine*> &e);
int AverageHorsePower(const std::vector<Engine*> &e);
float FindTorquebyId(std::vector<Engine*> &e, unsigned int id);
int FindThehorsepowerForMinTorqueEngine(std::vector<Engine*> &e);
