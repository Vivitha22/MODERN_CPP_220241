#include "ICECar.h"

std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
        os << static_cast<const Car &>(rhs) <<"\t"
           << " iceCarFuelType: " << (int)rhs.iceCarFuelType <<"\t"
           << " iceCarFuelCapacity: " << rhs.iceCarFuelCapacity<<"\t";
        return os;
    }

ICECar::ICECar(int id, std::string name,  float price,int capacity, FuelType fueltype):Car(id,name,price) , iceCarFuelType{fueltype}, iceCarFuelCapacity{capacity}
{

}


ICECar::~ICECar()
{
}

