#include "Functionalities.h"


int main() {
    // SmartDevice* devices[3];
    std::list<SmartDevice*> devices;

    CreateObjects(devices);


    FindIthIndexValue( [](const SmartDevice* d){ return d->id() == "101" || d->id() == "102" || d->id() == "103";},devices);

    FilterDevies( [](const SmartDevice* s){return s->price() > 0.0f ;} , devices);

    auto fn =[](const SmartDevice* s){return s->deviceTechnology() == Technology::BLUETOOTH ;};

    FilterDevies(fn, devices);
//
    // Deallocate(devices); 
    Deallocate(devices);
}