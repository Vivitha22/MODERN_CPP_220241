#include "Engine.h"

Engine::Engine(std::string id, EngineType type, float cc, float torque, int horsepower):m_id{id}, m_type{type},m_engine_cc{cc}, m_engine_torque{torque},m_engine_horsepower{horsepower}
{

}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_type: " << (int)rhs.m_type
           << " m_engine_cc: " << rhs.m_engine_cc
           << " m_engine_torque: " << rhs.m_engine_torque
           << " m_engine_horsepower: " << rhs.m_engine_horsepower;
        return os;
    }