#include "BankAccount.h"

std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
        os << "m_accountNumber: " << rhs.m_accountNumber <<"\n"
           << " m_accountHolderName: " << rhs.m_accountHolderName <<"\n"
           << " m_accountBalance: " << rhs.m_accountBalance <<"\n"
           << " m_accountType: " << rhs.m_accountType <<"\n"
           << " m_attached_card: " << *rhs.m_attached_card; //show value
        return os;
}

BankAccount::BankAccount(long number, std::string name, float balance, BankAccountType accountType, DebitCard* card):m_accountNumber{number}, m_accountHolderName{name}, m_accountBalance{balance}, m_accountType{accountType}, m_attached_card{card} {
    
}

BankAccount::~BankAccount(){
    delete m_attached_card; //immediately delete debit card
    std::cout << "Bank account: " << m_accountNumber << " is deleted\n";
}
