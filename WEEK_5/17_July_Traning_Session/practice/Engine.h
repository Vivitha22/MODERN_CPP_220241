#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string engine_id{""};
    float engine_cc{0.0f};
    float engine_torque {0.0f};
    int engine_horsepower {0};
    EngineType engine_type{EngineType::HYBRID};

public:
    Engine() = default;
    Engine(const Engine&)= delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&)=delete;
    Engine& operator = (Engine&&) = delete;
    ~Engine() = default;
    Engine(std::string id, float cc, float torque, int horsepower, EngineType type): engine_id{id}, engine_torque{torque}, engine_cc{cc},engine_horsepower{horsepower}, engine_type{type} {}

    std::string engineId() const { return engine_id; }

    float engineCc() const { return engine_cc; }

    float engineTorque() const { return engine_torque; }

    int engineHorsepower() const { return engine_horsepower; }

    EngineType engineType() const { return engine_type; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
    
};

#endif // ENGINE_H