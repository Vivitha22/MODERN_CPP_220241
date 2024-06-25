#include "Engine.h"
#include "Functionalities.h"

int main(){
    Engine *e[3];
    createObjects(e);
    AverageHorsePower(e,3);
    try{
        FindTorqueById(e,3,101);
    }catch(std::invalid_argument& er){
        std::cerr<<er.what()<<"\n";
    }
    catch(IdNotFoundException& er){
        std::cerr<<er.what()<<"\n";
    }
    FindHorsepowerForMinTorqueEngine(e,3);

}