/*
    1) create car and Operations
    2) FindAverageCostOfVehicles :print the average price of all vehicle in our database
    3) ReturnMatchingInstance : return the firts vehicle whose id matches with the id parameter received
    4) Deallocate : release heap allocations if any!
    5) DisplayInsuranceAmount : show output of InsuranceAmount function for each instance.
    6)FindSeatCountForGivenId : Fetches vehicle based on ID and returns corresponding seat_count;
*/

#ifndef OPERATION_H
#define OPERATION_H

#include<variant>
#include<optional>
#include<unordered_map>
#include<iostream>
#include<future>
#include<list>
#include"Car.h"
#include"Bike.h"
#include<memory>
#include<thread>

#include<mutex>

using CarPtr = std::shared_ptr<Car>;
using BikePtr= std::shared_ptr<Bike>;
using VrType = std::variant<CarPtr,BikePtr>;
using DataContainer = std::unordered_map<std::string,VrType>;
using ThreadContainer = std::list<std::thread>;


void CreateCarsAndBikes(DataContainer& data);
/*
FindAverageCost : use visit function to do this.  Both car and bike have a m_price attribute.
We can use their getter funciton to calculate total
*/
void FindAverageCost(const DataContainer& data,std::string id);

/*
    ReturnMatchingInstance : Variant whose ID matches with the id passed
*/

std::optional<VrType> ReturnMatchingInstance(const DataContainer& data,std::string id);


void DisplayInsuranceAmount(const DataContainer& data);
/*
scenario 1 : id found, matches with a car, seat count returned 
scenario 2 : id found, matches with a bike ---> nullopt
scenario 3 : id not found : nullopt (print a message before return)
*/
std::optional<unsigned int>FindSeatCountForGivenId(const DataContainer& data,std::string id);
/*
MapThreads : attachs a thread to a functinality
*/
void MapThreads(ThreadContainer& threads, const DataContainer& data);
/*
Jointhreads: Blocking main for respective functions executing in threads
*/
void JoinThreads(ThreadContainer& threads);



#endif // OPERATION_H