#ifndef ICECAR_H
#define ICECAR_H

#include "Car.h"
#include "FuelType.h"
#include <ostream>

class ICECar : public Car
{
private:
    FuelType iceCarFuelType;
    int iceCarFuelCapacity;

public:
    ICECar(int id, std::string name, float price ,int capacity,FuelType fueltype);
    ~ICECar();
    ICECar(const ICECar&)=delete;
    ICECar operator = (const ICECar&)=delete;
    ICECar(ICECar&&)=delete;
    ICECar operator = (ICECar&&)= delete;
    ICECar()=delete;

    FuelType getIceCarFuelType() const { return iceCarFuelType; }

    int getIceCarFuelCapacity() const { return iceCarFuelCapacity; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);

    /*
     Engine(int id,int power, float torque);
    Engine()=delete;
    Engine(const Engine&)=delete;
    Engine& operator=(const Engine&)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(Engine&&)=delete;
    ~Engine();
    */
};

#endif // ICECAR_H
