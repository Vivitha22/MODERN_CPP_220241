#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>

class Engine
{
private:
    int m_id {0};
    int m_horsepower {0};
    float m_torque {0.0f};
public:
    Engine(int id,int power, float torque);
    Engine()=delete;
    Engine(const Engine&)=delete;
    Engine& operator=(const Engine&)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(Engine&&)=delete;
    ~Engine();

    int id() const { return m_id; }

    int horsepower() const { return m_horsepower; }

    float torque() const { return m_torque; }

};

#endif // ENGINE_H
