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
#include<list>
#include<iostream>

#include"Car.h"
#include"Bike.h"

#include<thread>

#include<mutex>

using VrType = std::variant<Car*,Bike*>;
using DataContainer = std::list<VrType>;
using ThreadContainer = std::list<std::thread>;


class Operation
{
private:
    static std::mutex mt;
    static DataContainer m_data;
    static ThreadContainer m_threads;
public:
    Operation() = delete;
    Operation(const Operation&)= delete;
    Operation& operator=(const Operation&) = delete;
    Operation(Operation&&)=delete;
    Operation& operator = (Operation&&) = delete;
    ~Operation() = default;

    static void CreateCarsAndBikes();
    /*
        FindAverageCost : use visit function to do this.  Both car and bike have a m_price attribute.
        We can use their getter funciton to calculate total
    */
    static void FindAverageCost();
   /*
        ReturnMatchingInstance : Variant whose ID matches with the id passed


   */
    static std::optional<VrType> ReturnMatchingInstance(std::string id);

    static void Deallocate();

    static void DisplayInsuranceAmount();
    /*
        scenario 1 : id found, matches with a car, seat count returned 
        scenario 2 : id found, matches with a bike ---> nullopt
        scenario 3 : id not found : nullopt (print a message before return)
    */

    static std::optional<unsigned int>FindSeatCountForGivenId(std::string id);

    /*
        MapThreads : attachs a thread to a functinality
    */
    static void MapThreads();
    /*
        Jointhreads: Blocking main for respective functions executing in threads
    */
    static void JoinThreads();
};



#endif // OPERATION_H
