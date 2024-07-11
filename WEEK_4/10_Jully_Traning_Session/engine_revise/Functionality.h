#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include"Engine.h"
#include<list>
#include<thread>
#include<future>
#include<functional>
#include<memory>

// std::mutex mt;

using EnginePtr = std::shared_ptr<Engine>;
using DataContainer = std::list<EnginePtr>;
using Predicate = std::function<bool(const EnginePtr&)>;

void CreateObjects(DataContainer& data);

std::optional<DataContainer> ReturnMatchingContainer(const DataContainer& data, const Predicate& fn);

bool AtleastOneObjectMeetsCondition(const DataContainer& data, const Predicate& Fn);

int AverageOfEngineCc(const DataContainer& data);

#endif // FUNCTIONALITY_H
