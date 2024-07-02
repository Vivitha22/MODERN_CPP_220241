#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SmartDevice.h"
#include<functional>
#include<list>

// using Predicate = 
using SmartDeviceContainer = std::list<SmartDevice*>;

using Predicate = std::function<bool(const SmartDevice*)>;

void CreateObjects(SmartDeviceContainer& devices);

void Deallocate(SmartDeviceContainer& devices);

void FilterDevies(const Predicate fn, const SmartDeviceContainer& devices);

void FindIthIndexValue(const Predicate fun, const SmartDeviceContainer& devices);

void FindMaxGSTDeviceId(const SmartDeviceContainer& devices);


/*
    filter smart devices and display details of devices passing the filter criteria 

    criteria is provided bu the user

    example : show details of all devices whose with proce over 6000.0f
*/



//in tech terms a fun take single value as input and return true or false{bool return function} those functions are called PREDICATE
/*

                                                [  10.21  | 9.21  | 11.22 ]
                                                ^
                                                |
    [d101 |Mobile  | 9000.0f    |BLUETOOTH   |0x100H]
    24      24           4           4         8
*/



#endif // FUNCTIONALITIES_H
