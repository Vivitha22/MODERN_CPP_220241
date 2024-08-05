
#include "Functionalities.h"

// void CreateObjects(SmartDevice** devices, unsigned int size){

//     float* values1 = new float[3];

//     values1[0] = 10.21f; values1[1] = 9.21f; values1[2] = 11.22f;

//     float* values2 = new float[3];

//     values2[0] = 10.21f; values2[1] = 9.21f; values2[2] = 11.22f;

//     float* values3 = new float[3];

//     values3[0] = 10.21f; values3[1] = 9.21f; values3[2] = 11.22f;

//     devices[0] = new SmartDevice("101", "Mobile", 9000.0f, Technology::BLUETOOTH, values1);
//     devices[1] = new SmartDevice("102", "Tablet", 19000.0f, Technology::BLUETOOTH_WIFI, values2);
//     devices[2] = new SmartDevice("103", "SmartBand", 2000.0f, Technology::BLUETOOTH, values3);
// }

void CreateObjects(SmartDeviceContainer &devices)
{
    float* values1 = new float[3];

    values1[0] = 10.21f; values1[1] = 9.21f; values1[2] = 11.22f;

    float* values2 = new float[3];

    values2[0] = 10.21f; values2[1] = 9.21f; values2[2] = 11.22f;

    float* values3 = new float[3];

    values3[0] = 10.21f; values3[1] = 9.21f; values3[2] = 11.22f;

    devices.emplace_back(new SmartDevice("101", "Mobile", 9000.0f, Technology::BLUETOOTH, values1));
    devices.emplace_back(new SmartDevice("102", "Tablet", 19000.0f, Technology::BLUETOOTH_WIFI, values2));
    devices.emplace_back(new SmartDevice("103", "SmartBand", 2000.0f, Technology::BLUETOOTH, values3));
}

void Deallocate(SmartDeviceContainer &devices)
{
     for(const SmartDevice* d:devices){
        delete d;
    }
}



void FindIthIndexValue(const Predicate fun, const SmartDeviceContainer& devices)
{
     
    for(const SmartDevice* d:devices){
        if(fun(d)){
            std::cout<<*d<<"\n";
        }
    }

    
}

void FindMaxGSTDeviceId(const SmartDeviceContainer &devices)
{
    std::string output_id {""};
    float max {0.0f};
    // float output = devices->;
    unsigned int k{0};
    int index{0};
    for(const SmartDevice* d:devices){
        max = d->CalculateGstCost();
        break;
    }
    for(const SmartDevice* d:devices){
        if(max < d->CalculateGstCost()){
            max = d->CalculateGstCost();
            output_id = d->id();
        }
        // index = k;
        k++;
    }
    std::cout<<output_id<<"\n";

}

void FilterDevies(const Predicate fn, const SmartDeviceContainer& devices)
{
    bool atleastOneMatchingDeviceFound = false;

    for(const SmartDevice* d:devices){
        if(fn(d)){
            std::cout<<*d<<"\n";
            atleastOneMatchingDeviceFound = true;
        }
       
    }
    if(!atleastOneMatchingDeviceFound){
        std::cout<<"No matcing instance found\n";
    }

}
