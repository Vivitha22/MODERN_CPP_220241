#include "Functionalities.h"

//whatever you write in emplace back , it should be "sufficeient material 
//to make a new instrance for the container of that specitic type

//type vector of Engine pointers--> we need materials to make a new Engine*
void createObjects(std::vector<Engine *> &e)
{
    //FEATURE 5
    e.emplace_back( new Engine(101,456, 789.5f));
    e.emplace_back(new Engine(102,123, 456.0f));
    e.emplace_back(new Engine(103,789, 123.8f));
}

int AverageHorsePower(const std::vector<Engine *> &e)
{
    float total {0.0f}; //
    std::size_t valid_count {0};    
    //range based for loop (for-each loop)
    /*
        for each const Engine pointer "called engine" present in e
    */
    for(const Engine* engine: e)
    {
        if(engine){
            total+=engine->horsepower();
            valid_count++;
        }

    }

    // for(std::size_t i=0;i<e.size();i++){
    
    //     if(e[i])
    //     {
    //         total += e[i]->horsepower();
    //         valid_count++;
    //     }
    // }
    // if(valid_count!=0)
    // {
    //     return total/valid_count;
    // }
    if(valid_count == 0)
    {
        throw NoValidPointerFound("No valid pointer found all are invalid\n");
    }
    return total/valid_count;
        
}

float FindTorqueById(const std::vector<Engine *> &e,unsigned int id)
{
    bool validPointerNotFound = false;
    for(const Engine* engine:e){
        if(engine)
        {
            validPointerNotFound=true;
            if(engine->id() == id){
                return engine->torque();
            }
        }
    }
    if(!validPointerNotFound){
        throw NoValidPointerFound("Not even one valid pointer is found\n");
    }
    throw IdNotFoundException("Id not found\n");
}

int FindHorsepowerForMinTorqueEngine(const std::vector<Engine *> &e)
{
    bool validPointerNotFound{false};
    float currentMinTorque {e[0]->torque()};

    std::size_t indioOfMinTorque {0};
    std::size_t k=0;
    for(const Engine* engine : e){
        if(engine){
            validPointerNotFound = true;
            if(engine->torque() < currentMinTorque){
                currentMinTorque = engine->torque();
                indioOfMinTorque = k;
            }
        }
        k++;
    }
    if(validPointerNotFound){
        return e[indioOfMinTorque]->horsepower();
    }
    else{
        throw NoValidPointerFound("No valid pointer found\n");
    }

    // throw IdNotFoundException("Id not found\n");
}

void Deallocate(std::vector<Engine *> &e)
{
    for(const Engine* v:e){
        delete v;
    }
}
