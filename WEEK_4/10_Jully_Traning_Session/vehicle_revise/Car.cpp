#include "Car.h"

Car::Car(std::string carid, float carPrice, unsigned short seatCount):m_id{carid}, m_price{carPrice}, m_seat_count{seatCount}
{
}

float Car::InsuranceAmount()
{
    // std::cout<<
    return 0.2f * m_price;
    // return 0.0f;
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " m_seat_count: " << rhs.m_seat_count;
        return os;
    }