#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>

class IdNotFoundException : public std::exception{
    private:
        std::string m_str;
    public:
        IdNotFoundException(std::string str){
            this->m_str=str;
        }
        ~IdNotFoundException(){}

        virtual const char*
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
        {
            return m_str.c_str(); 
        }
};

#endif // IDNOTFOUNDEXCEPTION_H
