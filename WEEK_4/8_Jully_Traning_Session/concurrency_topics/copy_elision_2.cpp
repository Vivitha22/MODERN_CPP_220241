/*
    elision: no t do something, not perorm something, ingore/ avoid something

    Gurateed copy Elision : cpp17
    This will give you the guranty that copy is not allowed, it is done by the compiler automatically
    it is an optimization feature


*/

#include <iostream>
class Data
{
private:
    int m_value {0};
public:
    Data() = default;

    Data(const Data&)= delete;
    Data(Data&&)=delete;
    Data& operator=(const Data&)=delete;
    Data& operator=(Data&&)=delete;
    ~Data() = default;
    explicit Data(int val): m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

    
};

Data magic(){
    return Data{100}; 
}

int main(){
    Data d1 = magic(); //-->this is called initialization
    //d1 object is intialized by the return value of magic function  -->it is like emplace
}

// Here magic to main