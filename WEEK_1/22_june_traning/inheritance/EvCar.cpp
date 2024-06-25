#include "EvCar.h"

EvCar::EvCar(int id, std::string name, float price ,float capacity, unsigned int range) :Car(id,name,price) , evCarBatteryCapacity{capacity}, evCarRatedRange{range}
{

}

EvCar::~EvCar()
{
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
        os << static_cast<const Car &>(rhs)<<"\t"
           << " evCarBatteryCapacity: " << rhs.evCarBatteryCapacity<<"\t"
           << " evCarRatedRange: " << rhs.evCarRatedRange <<"\t";
        return os;
    }