#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "employee.h"
#include "project.h"
#include <vector>

using container = std::vector<employee*>;
using Container = std::vector<project*>;

// void c

void createObeject(container& e, Container& p);
void deallocate(container& e, Container& p);

#endif // FUNCTIONALITY_H
