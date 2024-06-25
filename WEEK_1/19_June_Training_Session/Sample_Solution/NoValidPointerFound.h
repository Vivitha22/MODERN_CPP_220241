#ifndef NOVALIDPOINTERFOUND_H
#define NOVALIDPOINTERFOUND_H

#include<stdexcept>

class NoValidPointerFound : public std::exception
{
private:
    std::string m_msg;
public:
    NoValidPointerFound(std::string msg) : m_msg {msg}{};
    NoValidPointerFound() = delete;
    NoValidPointerFound(const NoValidPointerFound& other)=delete;
    NoValidPointerFound(NoValidPointerFound&& other)= default;
    NoValidPointerFound& operator=(const NoValidPointerFound& other)=delete;
    NoValidPointerFound operator=(NoValidPointerFound&& other) = delete;
    ~NoValidPointerFound() = default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return m_msg.c_str();
    }
};

#endif // NOVALIDPOINTERFOUND_H
