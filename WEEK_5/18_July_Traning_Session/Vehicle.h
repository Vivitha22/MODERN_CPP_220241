#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include "EngineType.h"
#include "FuelType.h"
#include "MultimediaType.h"
#include "VehicleStandard.h"
#include "VehicleType.h"

class Vehicle
{
private:
    VehicleType m_vehicle_type {VehicleType::COMMERCIAL};
    VehicleStandard m_vehicle_standard {VehicleStandard::BS4};
    FuelType m_vehicle_fuel_type{FuelType::OTHER}; 
    EngineType m_engine_type{EngineType::NA};
    MultimediaType  m_vehicle_multimedia_type{MultimediaType::ANALOG};
    float m_vehicle_price {0.0f};


public:
    Vehicle(const Vehicle&)=delete;
    Vehicle& operator=(const Vehicle&)=delete;
    Vehicle(Vehicle&&)= delete;
    Vehicle& operator=(Vehicle&&)= delete;
    Vehicle() =delete;
    Vehicle(VehicleType vtype, VehicleStandard standard, FuelType ftype, EngineType etype, MultimediaType mtype, float price);
    ~Vehicle() =default;

    VehicleType vehicleType() const { return m_vehicle_type; }

    VehicleStandard vehicleStandard() const { return m_vehicle_standard; }

    FuelType vehicleFuelType() const { return m_vehicle_fuel_type; }

    EngineType engineType() const { return m_engine_type; }

    MultimediaType vehicleMultimediaType() const { return m_vehicle_multimedia_type; }

    float vehiclePrice() const { return m_vehicle_price; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

    
    float CalculateRegistrationCose();
    
};

#endif // VEHICLE_H
