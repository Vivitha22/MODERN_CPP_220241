#include "Bike.h"

Bike::Bike(std::string id, float price):m_id{id},m_price{price}
{
}

float Bike::InsuranceAmount()
{
    // std::cout<<"The insurance amount is :"<<m_bike_price * 0.01f<<"\n";
    return m_price *  0.1f;
}

std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
        os << "m_bike_id: " << rhs.m_id
           << " m_bike_price: " << rhs.m_price;
        return os;
    }