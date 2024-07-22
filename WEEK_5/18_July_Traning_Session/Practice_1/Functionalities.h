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


/*
    This function creates data for demonstratio purposes in a vector using shared pointer
*/
void CreateObjects(DataContainer& data);

/*
    Returns the highest vehicle price using the datacontainer 
*/

std::optional< PriorityQueue >HighestVehiclePrice(const DataContainer& data);

std::optional<unorderSet> ReturnMatchingVehicle(const DataContainer& data);

std::optional<unsigned int> CountOfVehicleObjects(const DataContainer& data,const MultimediaType mtype);

/*
    Returns the data container which have values that statisfies the predicate function given by the user/
*/

std::optional<DataContainer> ReturnInstance(const DataContainer& data,const Predicate& fn);

/*
    this returns a bool which checks that all the objects price is above 90k
*/

std::optional<bool> CheckAllVechilesPrice(const DataContainer& data);

/*
     this is give the average of registration cost for all the datas.
*/

void AverageCalculation(const DataContainer& data);

/*
    return a container of last N items from the datacontainer.
*/

std::optional<DataContainer> ReturnLastNItems(const DataContainer& data, const unsigned int N);


#endif // FUNCTIONALITIES_H