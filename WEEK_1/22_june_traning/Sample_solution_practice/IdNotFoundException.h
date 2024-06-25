#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include<stdexcept>

class IdNotFoundException : public std::exception
{
private:
    std::string m_str;
public:
    IdNotFoundException()=default;
    IdNotFoundException(const IdNotFoundException&)=default;
    IdNotFoundException operator=(const IdNotFoundException&)=delete;
    IdNotFoundException(IdNotFoundException&)=delete;
    IdNotFoundException& operator=(IdNotFoundException&&)=delete;
    IdNotFoundException(std::string msg) {
        this->m_str=msg;
    }

    ~IdNotFoundException() {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return m_str.c_str();
    }
};

#endif // IDNOTFOUNDEXCEPTION_H
