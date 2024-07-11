#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include"EngineType.h"

class Engine
{
private:
    std::string m_id;
    EngineType m_type;
    float m_engine_cc;
    float m_engine_torque;
    int m_engine_horsepower;

public:
    Engine(const Engine&)=delete;
    Engine& operator=(const Engine&)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(Engine&&) = delete;

    Engine(std::string id,EngineType type,float cc, float torque, int horsepower);
    ~Engine() {}

    float engineTorque() const { return m_engine_torque; }

    float engineCc() const { return m_engine_cc; }

    EngineType type() const { return m_type; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) ;
    
};

#endif // ENGINE_H
