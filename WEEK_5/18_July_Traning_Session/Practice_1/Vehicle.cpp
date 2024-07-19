#include "Vehicle.h"

Vehicle::Vehicle(VehicleType vtype, VehicleStandard standard, FuelType ftype, EngineType etype, MultimediaType mtype, float price): m_vehicle_type{vtype}, m_vehicle_standard{standard}, m_vehicle_fuel_type{ftype},m_engine_type{etype},m_vehicle_multimedia_type{mtype}, m_vehicle_price{price}
{
}

float Vehicle::CalculateRegistrationCose() const
{
    float ans{0.0f};
    if(m_vehicle_fuel_type == FuelType::ICE){
        ans = m_vehicle_price * 0.10f;
    }
    else if( m_vehicle_fuel_type == FuelType::ALTERNATE_FUEL){
        ans = m_vehicle_price * 0.10f;
    }
    else{
        ans = m_vehicle_price * 0.20f;
    }
    return ans;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
        os << "m_vehicle_type: " << (int)rhs.m_vehicle_type
           << " m_vehicle_standard: " << (int)rhs.m_vehicle_standard
           << " m_vehicle_fuel_type: " <<(int) rhs.m_vehicle_fuel_type
           << " m_engine_type: " << (int)rhs.m_engine_type
           << " m_vehicle_multimedia_type: " << (int)rhs.m_vehicle_multimedia_type
           << " m_vehicle_price: " << rhs.m_vehicle_price;
        return os;
    }
