#ifndef NOVALIDPOINTERFOUND_H
#define NOVALIDPOINTERFOUND_H

#include<stdexcept>

class NoValidPointerFound :public std::exception
{
private:
    std::string m_str;

public:
    NoValidPointerFound(std::string str) :m_str{str} {
        this->m_str=str;
    };
    NoValidPointerFound()=delete;
    NoValidPointerFound(const NoValidPointerFound& other)=default;
    NoValidPointerFound& operator=(const NoValidPointerFound& other)=delete;
    NoValidPointerFound(NoValidPointerFound& other)=delete;
    NoValidPointerFound operator=(NoValidPointerFound&& other)=delete;
    
    
    ~NoValidPointerFound()= default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return m_str.c_str();
    }
    
};

#endif // NOVALIDPOINTERFOUND_H
