#include "Functionalities.h"

int main() {
    // BankAccount* accounts[2];
    std::vector<BankAccount*> accounts;
    CreateObjects(accounts);
    
    /*
        write other parts of client code here

    */
    DisplayCardDetails(accounts, 9088191);
    CountVISACards(accounts);

    DeallocateMemory(accounts);
}