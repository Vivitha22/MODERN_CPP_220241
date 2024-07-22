#include "Functionalities.h"

int main(){
    std::vector<BankAccount*> accounts;

    CreateObjects(accounts);
    CountVISACards(accounts);
    ShowDetails(accounts,7654534468);
    DeallocateMemory(accounts);
}