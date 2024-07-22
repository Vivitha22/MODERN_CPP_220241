#include "Functionalities.h"
#include "AccountNotFoundException.h"
#include <stdexcept>

// #include "BankAccount.h"

void CreateObjects(container &accounts)
{
    // b[0] = new BankAccount(908819191, "XYZ", 8990.0f, BankAccountType::SAVINGS, DebitCard(111, "19/12", 111122223333444, DebitCardType::MASTERCARD));
    accounts.emplace_back(new BankAccount(9088191, "XYZ", 8990.0f, BankAccountType::SAVINGS, new DebitCard(111, "19/12", 111122223333444, DebitCardType::MASTERCARD)));

}


/*
    A function to find and display the details of debitcard for account whose number is provided as parameter
*/


void DisplayCardDetails(const container &accounts, long number){
    
    bool flag = false;
    for(const BankAccount* b: accounts) {
        if ( b->accountNumber() == number   ) {
            flag = true;
            std::cout << *(b->attachedCard()) << "\n";
            
            // break;
        }
    }

    if (!flag){
        throw AccountNotFoundException("Invalid number\n");
    }
}

/*
    Find and display the count of DebitCard with type = VISA
*/


void CountVISACards(container &accounts){
    unsigned int count {0};
    for(const BankAccount *b: accounts) {

        /*
            if i position account fetches debitcard and then checks type of debit
            card and it is VISA, increase count by 1
        */
        if (b->attachedCard()->cardType() == DebitCardType::VISA){
            count++;
        }
    }
    std::cout << "Count is: " << count << "\n";
}

void DeallocateMemory(container &accounts)
{
    for(BankAccount* b : accounts){
        delete b;
    }
}
