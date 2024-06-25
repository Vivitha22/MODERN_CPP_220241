#include "Functionalities.h"
#include "AccountNotFoundException.h"
#include <stdexcept>

void CreateObjects(Container& accounts)
{
    accounts.emplace_back(new BankAccount(7654534468, "XYZ", 7567.0f, BankAccountType::SAVINGS, new DebitCard(111, "19/12", 6523243554657, DebitCardType::MASTERCARD)));//composition

}

/*
    A function to find and display the details of debitcard for account whose number is provided as parameter
*/

void ShowDetails( const Container& accounts, const long number){
    bool flag = false;
    for(BankAccount* b : accounts){
        if(b->accountNumber()==number){
            flag = true;
            std::cout << *(b->attachedCard()) << "\n";
        }
    }
    if(!flag){
        throw AccountNotFoundException("Invalid Number\n");
    }
}

/*
    Find and Display the count of DebitCard type = VISA
*/

void CountVISACards(Container& accounts){
    unsigned int count {0};
    for(BankAccount* b : accounts){
        if(b->attachedCard()->cardType()==DebitCardType::VISA){
            count++;
        }
    }
    std::cout << "The count of DebitCard type VISA is : " << count << "\n";
}

void DeallocateMemory(Container& accounts){
    for(BankAccount* b : accounts){
        delete b;
    }
}