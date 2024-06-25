#include "DebitCard.h"
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "m_card_cvv: " << rhs.m_card_cvv
       << " m_card_expiry_date: " << rhs.m_card_expiry_date
       << " m_card_number: " << rhs.m_card_number
       << " m_card_type: " << rhs.m_card_type;
    return os;
}


DebitCard::DebitCard(short cvv, std::string expiryDate, long long cardNumber, DebitCardType cardType) : m_card_cvv{cvv}, m_card_expiry_date{expiryDate}, m_card_number{cardNumber}, m_card_type{cardType}
{
    
}

