#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id <<"\t"
           << " m_modelName: " << rhs.m_modelName<<"\t"
           << " m_price: " << rhs.m_price<<"\t";
        return os;
    }

Car::Car(int id, std::string name, float price) :m_id{id}, m_modelName{name} , m_price{price}
{
}

Car::~Car()
{
    std::cout<<"The object with car id : "<< m_id <<" is deleted\n";
}
