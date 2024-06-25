#ifndef EVCAR_H
#define EVCAR_H

#include "Car.h"
#include <ostream>


class EvCar : public Car
{
private:

    float evCarBatteryCapacity;
    unsigned int evCarRatedRange;

public:
    EvCar(int id, std::string name, float price ,float capacity, unsigned int range);
    ~EvCar();
    EvCar(const EvCar&)=delete;
    EvCar& operator=(const EvCar&)=delete;
    EvCar(EvCar&&)=delete;
    EvCar& operator=(EvCar&&)=delete;
    EvCar()=default;

    float getEvCarBatteryCapacity() const { return evCarBatteryCapacity; }

    

    unsigned int getEvCarRatedRange() const { return evCarRatedRange; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EvCar_H
