#include "Functionalities.h"
// #include<vector>
#include<stdexcept>

#include<iostream>

int main(){
    std::vector<Engine*> e;

    createObjects(e);
    try{
        std::cout<<AverageHorsePower(e)<<"\t";
    }catch(NoValidPointerFound &ex){
        std::cerr<<ex.what()<<"\n";
    }
    try{
        std::cout<<FindTorquebyId(e, 103)<<"\t";
    }
    catch(NoValidPointerFound &ex){
        std::cerr<<ex.what()<<"\n";
    }
    try{
        std::cout<<FindThehorsepowerForMinTorqueEngine(e)<<"\t";
    }
    catch(NoValidPointerFound &ex){
        std::cerr<<ex.what()<<"\n";
    }

}