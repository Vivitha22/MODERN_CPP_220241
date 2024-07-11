#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car
{
private:
    std::string m_id;
    float m_price;
    unsigned short m_seat_count;
public:
     Car()=delete;
    Car(const Car&)= delete;
    Car& operator=(const Car&)= delete;
    Car(Car&&)=delete;
    Car& operator=(Car&&)=delete;
    Car(std::string carid, float carPrice, unsigned short seatCount);
    ~Car() =default;

    float InsuranceAmount();

    std::string id() const { return m_id; }

    float price() const { return m_price; }

    unsigned short seatCount() const { return m_seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) ;
};

#endif // CAR_H
