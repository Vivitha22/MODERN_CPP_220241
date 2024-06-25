#ifndef IdNotFoundException_H
#define IdNotFoundException_H

#include<stdexcept>

class IdNotFoundException : public std::exception
{
private:
    std::string m_msg;
public:
    IdNotFoundException(std::string msg) : m_msg {msg}{};
    IdNotFoundException() = delete;
    IdNotFoundException(const IdNotFoundException& other)=default;
    IdNotFoundException(IdNotFoundException& other)= delete;
    IdNotFoundException& operator=(const IdNotFoundException& other)=delete;
    IdNotFoundException operator=(IdNotFoundException&& other) = delete;
    ~IdNotFoundException() = default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return m_msg.c_str();
    }
};

#endif // IdNotFoundException_H
