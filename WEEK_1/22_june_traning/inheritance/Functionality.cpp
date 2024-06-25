#include "Functionality.h"

void createObjects(container &c)
{
    c.emplace_back(new ICECar(101,"Vivi",202.3f,123,FuelType::PETROL));
    c.emplace_back(new ICECar(102,"Pavan", 45.5f,456,FuelType::DIESEL));

    c.emplace_back(new EvCar(103,"Vigi", 4520.2f,789.0f,12));
    c.emplace_back(new EvCar(104,"Prabhu", 7412.9f,852.2f,45));
    // new ICECar("ic101", "Dizire", 900.0f, FuelType::PETROL,42);
}



void ShowDetails(container& c, int id)
{

    for( Car* cars:c){
        if(cars->id() == id){
            std::cout<<cars->id() <<"\t"<<cars->price()<<"\t"<<cars->modelName();

            ICECar* temp=dynamic_cast<ICECar*>(cars);

            if(temp)
            {
                std::cout<<temp->getIceCarFuelCapacity()<< "\t" << (int)temp->getIceCarFuelType();
            }

            EvCar* temp2=dynamic_cast<EvCar*>(cars);

            if(temp2){
                std::cout<<temp2->getEvCarBatteryCapacity()<<"\t"<<temp2->getEvCarRatedRange();
            }
        }
    }
    std::cerr<<"ID not Found\n";
}


void Deallocate(container &c)
{
    for(const Car* v:c){
        delete v;
    }
}
