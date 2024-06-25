#include "Functionalities.h"


void createObjects(Engine **e)
{
    e[0]=new Engine(101,123,123.2f);
    e[1]=new Engine(102,456,456.5f);
    e[2]=new Engine(103,789,789.8f);

}

void AverageHorsePower(Engine **e, int size)
{
    if(size == 0){
        throw std::invalid_argument("Size can't be zero\n");
        return;
    }
    float total = 0;
    int c=0;
    for(int i=0;i<size;i++){
        if(e[i]) {
        total = total + e[i]->horsepower();
        c++;
        }
    }
    int v=total/c;
    std::cout << "The average is : " << v << "\n";
}

void FindTorqueById(Engine ** e, int size, int id)
{
    if(size == 0){
        throw std::invalid_argument("Size can't be zero\n");
        return;
    }
     for(int i=0;i<size;i++){
        if(e[i]->id()==id){
            std::cout<< "THe torque is : " << e[i]->torque()<<"\n";
        }
    }
    throw IdNotFoundException("Id not fount\n");
}

void FindHorsepowerForMinTorqueEngine(Engine **e, int size)
{
    if(size == 0){
        throw std::invalid_argument("Size can't be zero\n");
        return;
    }
    int index=0;
    int min= e[0]->torque();
    for(int i=0;i<size;i++){
        if(min< e[i]->torque()){
            min = e[i]->torque();
            index = i;
        }
    }
    std::cout<<"Horsepower for min torque "<<e[index]->horsepower() << "\n";
}

/*
    think about inputs to a function 
    THINK ABOUT 1 sure shot way of completing the function and getting a valid output

    NOW, START THINKING OF ALL POSSIBLE WAYS, FUNCTIONS MAY NOT BE COMPLETED BASED ONT INPUTS PROVIDED AND SYSTEM SITUATIONS!
*/