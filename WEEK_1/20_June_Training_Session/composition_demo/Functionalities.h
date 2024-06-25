#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "BankAccount.h"
using Container = std::vector<BankAccount*>;

void CreateObjects(Container& accounts);

void CountVISACards(Container& accounts);

void ShowDetails( const Container& accounts, const long number);

void DeallocateMemory(Container& accounts);

#endif // FUNCTIONALITIES_H
