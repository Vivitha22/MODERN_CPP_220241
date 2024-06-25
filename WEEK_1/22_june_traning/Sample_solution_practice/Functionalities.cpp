#include "Functionalities.h"


void createObjects(std::vector<Engine *> &e)
{
    e.emplace_back(new Engine(101,123,456.2f));
    e.emplace_back(new Engine(102,456,123.5f));
    e.emplace_back(new Engine(103,789,45.2f));
}

int AverageHorsePower(const std::vector<Engine *> &e)
{
    float total {0};
    std::size_t validPointer {0};
    for(const Engine* v:e){
        if(v){
            total+=v->horsepower();
            validPointer++;
        }
    }
    if(validPointer==0){
        throw NoValidPointerFound("No valid pointer found \n");
    }
    return total/validPointer;
}

float FindTorquebyId(std::vector<Engine *> &e, unsigned int id)
{
    // bool noIdFound {false};
    for(const Engine * v:e){
        if(v){
            if(v->id() == id){
                // noIdFound =true;
                return v->torque();
            }
        }
    }
    throw IdNotFoundException("id not found\n");
    // return 0.0f;
}

int FindThehorsepowerForMinTorqueEngine(std::vector<Engine *> &e)
{
    int indexOfMinofTorque {0};
    int validPointer {0};
    float currentMinTorque {e[0]->torque()};
    int k{0};
    for(const Engine* v:e){
        if(v){
            validPointer = 1;
            if(currentMinTorque > v->torque()){
                currentMinTorque = v->torque();
                indexOfMinofTorque = k;
            }
        }
        k++;
    }
    if(validPointer==0){
        throw NoValidPointerFound("No valid pinter in the engines\n");
    }
    else{
        return e[indexOfMinofTorque]->horsepower();
    }
    return 0;
}
