#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car
{
private:
    int m_id;
    std::string m_modelName;
    float m_price;

public:
    Car(int id, std::string name, float price);
    virtual ~Car();
    Car(const Car&)=delete;
    Car& operator=(const Car&)=delete;
    Car(Car&&)=delete;
    Car& operator=(Car&&)=delete;
    Car()=default;

    int id() const { return m_id; }

    std::string modelName() const { return m_modelName; }

    

    float price() const { return m_price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
