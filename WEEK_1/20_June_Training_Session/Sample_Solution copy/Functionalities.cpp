#include "Functionalities.h"

//whatever you write in emplace back , it should be "sufficeient material 
//to make a new instrance for the container of that specitic type

//type vector of Engine pointers--> we need materials to make a new Engine*
void createObjects(Container&e)
{
    //FEATURE 5
    e.emplace_back( new Engine(101,456, 789.0f));
    e.emplace_back(new Engine(102,123, 456.0f));
    e.emplace_back(new Engine(103,789, 123.0f));
}

int AverageHorsePower(const Container&e)
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

float FindTorqueById(const Container&e,unsigned int id)
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

int FindHorsepowerForMinTorqueEngine(const Container&e)
{
    bool validPointerNotFound{false};
    float currentMinTorque (e[0]->torque());

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

    throw IdNotFoundException("Id not found\n");
}

// void createObjects( std::vector<Engine*>& e)
// {
//     e[0]=new Engine(101,123,123.2f);
//     e[1]=new Engine(102,456,456.5f);
//     e[2]=new Engine(103,789,789.8f);

// }

// void AverageHorsePower(const std::vector<Engine*>& e)
// {
//     if(size == 0){
//         throw std::invalid_argument("Size can't be zero\n");
//         return;
//     }
//     float total = 0;
//     int c=0;
//     for(int i=0;i<size;i++){
//         if(e[i]) {
//         total = total + e[i]->horsepower();
//         c++;
//         }
//     }
//     int v=total/c;
//     std::cout << "The average is : " << v << "\n";
// }

// void FindTorqueById(const std::vector<Engine*>& e)
// {
//     if(size == 0){
//         throw std::invalid_argument("Size can't be zero\n");
//         return;
//     }
//      for(int i=0;i<size;i++){
//         if(e[i]->id()==id){
//             std::cout<< "THe torque is : " << e[i]->torque()<<"\n";
//         }
//     }
//     // throw IdNotFoundException("Id not fount\n");
// }

// void FindHorsepowerForMinTorqueEngine(const std::vector<Engine*>& e)
// {
//     // if(size == 0){
//     //     throw std::invalid_argument("Size can't be zero\n");
//     //     return;
//     // }
//     int index=0;
//     int min= e[0]->torque();
//     for(int i=0;i<size;i++){
//         if(min< e[i]->torque()){
//             min = e[i]->torque();
//             index = i;
//         }
//     }
//     std::cout<<"Horsepower for min torque "<<e[index]->horsepower() << "\n";
// }

// /*
//     think about inputs to a function 
//     THINK ABOUT 1 sure shot way of completing the function and getting a valid output

//     NOW, START THINKING OF ALL POSSIBLE WAYS, FUNCTIONS MAY NOT BE COMPLETED BASED ONT INPUTS PROVIDED AND SYSTEM SITUATIONS!
// */


