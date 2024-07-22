#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "BankAccount.h"
#include "DebitCard.h"
#include<vector>
#include "AccountNotFoundException.h"

using container = std::vector<BankAccount*> ;

void CreateObjects(container &accounts);

void DisplayCardDetails(const container &accounts, long number);

void CountVISACards(container &accounts);

void DeallocateMemory(container& accounts);
#endif // FUNCTIONALITIES_H
