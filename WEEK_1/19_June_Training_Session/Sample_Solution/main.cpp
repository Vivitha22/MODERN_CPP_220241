// #include "Engine.h"
#include<iostream>

#include"Functionalities.h"

int main(){
    std::vector<Engine*> e;
    createObjects(e);

    try{
        std::cout<<AverageHorsePower(e)<<"\n";
    }
    catch(NoValidPointerFound& ex){
        std::cerr<<ex.what()<<"\n";
    }
    try{
        std::cout<<FindTorqueById(e,103)<<"\n";
    }
    catch(IdNotFoundException& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(NoValidPointerFound& ex){
        std::cerr<<ex.what()<<"\n";
    }

    try{
        std::cout<<FindHorsepowerForMinTorqueEngine(e)<<"\n";
    }
    catch(IdNotFoundException& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(NoValidPointerFound& ex){
        std::cerr<<ex.what()<<"\n";
    }
    Deallocate(e);
}

