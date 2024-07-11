#ifndef BIKE_H
#define BIKE_H

#include<iostream>

class Bike
{
private:
    std::string m_id;
    float m_price;

public:
    Bike()=delete;
    Bike(const Bike&)= delete;
    Bike& operator=(const Bike&)= delete;
    Bike(Bike&&)=delete;
    Bike& operator=(Bike&&)=delete;

    Bike(std::string id,float price);
    ~Bike()=default;

    float InsuranceAmount();

    std::string id() const { return m_id; }

    float price() const { return m_price; }

    // std::string bikeId() const { return m_bike_id; }

    // float bikePrice() const { return m_bike_price; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);

    
};

#endif // BIKE_H
