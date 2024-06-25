#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>
#include "DebitCardType.h"

class DebitCard
{
private:
    short m_card_cvv{0};
    std::string m_card_expiry_date{""};
    long long m_card_number{0};
    DebitCardType m_card_type{DebitCardType::VISA};
public:
    DebitCard() = default;
    ~DebitCard() = default;
    DebitCard(const DebitCard&) = delete;
    DebitCard& operator=(const DebitCard&) = delete;
    DebitCard(DebitCard&&) = delete;
    DebitCard& operator=(DebitCard&&) = delete;
    DebitCard(short cvv, std::string expiryDate, long long cardNumber, DebitCardType cardType);

    DebitCardType cardType() const { return m_card_type; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);

    
};

#endif // DEBITCARD_H
