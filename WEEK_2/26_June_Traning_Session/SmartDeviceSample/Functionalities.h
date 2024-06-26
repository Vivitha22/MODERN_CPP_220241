#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SmartDevice.h"
#include<functional>

using Predicate = std::function<bool(const SmartDevice*)>;

void CreateObjects(SmartDevice** devices, unsigned int size);

void Deallocate(const SmartDevice** devices, const unsigned int size);

void FindIthIndexValue(const SmartDevice* device, unsigned int idx);

void FindMaxGSTDeviceId(const SmartDevice** devices, unsigned int idx);


/*
    filter smart devices and display details of devices passing the filter criteria 

    criteria is provided bu the user

    example : show details of all devices whose with proce over 6000.0f
*/

void FilterDevies(Predicate fn, const SmartDevice** devices, const unsigned int size);

//in tech terms a fun take single value as input and return true or false{bool return function} those functions are called PREDICATE
/*

                                                [  10.21  | 9.21  | 11.22 ]
                                                ^
                                                |
    [d101 |Mobile  | 9000.0f    |BLUETOOTH   |0x100H]
    24      24           4           4         8
*/



#endif // FUNCTIONALITIES_H
