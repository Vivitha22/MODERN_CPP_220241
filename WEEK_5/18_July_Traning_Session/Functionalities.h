#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include"memory"
#include <functional>
#include <future>
#include <unordered_map>
#include <unordered_set>
#include<algorithm>
#include <vector>
#include <list>
#include <queue>
#include<numeric>

using VehiclePtr = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<VehiclePtr>;
using ListContainer = std::list<Vehicle>;
using Predicate = std::function<bool(const VehiclePtr&)>;


using HashingFun = std::function<bool(const VehiclePtr&)>;
using Eqfun = std::function<bool(const VehiclePtr&, const VehiclePtr&)>;
extern HashingFun hash_fn;
extern Eqfun eq_fn;
extern Eqfun fn;

using PriorityQueue= std::priority_queue<VehiclePtr,DataContainer,decltype(fn)>;



    
using unorderSet = std::unordered_set<VehiclePtr, decltype(hash_fn),decltype(eq_fn)>;
// using 

void CreateObjects(DataContainer& data);

std::optional< PriorityQueue >HighestVehiclePrice(const DataContainer& data);

std::optional<unorderSet> ReturnMatchingVehicle(const DataContainer& data);

std::optional<unsigned int> CountOfVehicleObjects(const DataContainer& data,MultimediaType mtype);

std::optional<DataContainer> ReturnInstance(const DataContainer& data,const Predicate& fn);

std::optional<bool> CheckAllVechilesPrice(const DataContainer& data);

void AverageCalculation(const DataContainer& data);

std::optional<DataContainer> ReturnLastNItems(const DataContainer& data);


#endif // FUNCTIONALITIES_H
