#include "BankAccount.h"

std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
    os << "m_accountNumber: " << rhs.m_accountNumber
       << " m_accountHolderName: " << rhs.m_accountHolderName
       << " m_accountBalance: " << rhs.m_accountBalance
       << " m_accountType: " << rhs.m_accountType
       << " m_attached_card: " << *rhs.m_attached_card; //show value
    return os;
}

BankAccount::BankAccount(long number, std::string name, float balance, BankAccountType accountType, DebitCard* card) : m_accountBalance{balance},m_accountNumber {number},m_accountHolderName{name}, m_accountType{accountType}, m_attached_card{card}
{
}

BankAccount::~BankAccount()
{
    delete m_attached_card; //this will delete the debit card immediately
    std::cout << "Bank Account : " << m_accountNumber << " is deleted\n"; 
}
