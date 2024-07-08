#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car
{
private:
    std::string m_id {""};
    float m_price{0.0f};
    unsigned int m_seatCount {0};
    
public:
    float InsuranceAmount();
    
    Car() = delete;
    Car(const Car&)= delete;
    Car& operator=(const Car&) = delete;
    Car(Car&&)=delete;
    Car& operator = (Car&&) = delete;
    ~Car() = default;

    std::string id() const { return m_id; }

    float price() const { return m_price; }

    
    Car(std::string id, float price,unsigned int seatcount) : m_id{id}, m_price{price} , m_seatCount{seatcount}{}

    unsigned int seatCount() const { return m_seatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
