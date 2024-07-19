#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "engine_id: " << rhs.engine_id
           << " engine_cc: " << rhs.engine_cc
           << " engine_torque: " << rhs.engine_torque
           << " engine_horsepower: " << rhs.engine_horsepower
           << " engine_type: " << (int)rhs.engine_type;
        return os;
    }
    