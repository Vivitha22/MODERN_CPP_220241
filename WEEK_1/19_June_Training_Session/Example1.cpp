#include<iostream>
#include <vector>


enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_STAR,

};

class Car
{
private:
    unsigned int m_id {0};
    float m_price {0.0f};
    Rating m_safetyRating {Rating::_NO_STAR};

public:
    Car(unsigned int id, float price):m_id{id}, m_price {price} {

    }
    // Car(unsigned int id, float price, Rating rating):m_id{id}, m_price {price}, m_safetyRating {rating}{
        
    // }
    //FEATURE 8
    Car(unsigned int id, float price, Rating rating):Car(id, price){
        m_safetyRating = rating;
    }
    Car(unsigned int id, float price): Car(id,price){
        m_price = price;
    }
    
    ~Car() = default;

    Car() = delete;
    //option 1
    Car(const Car&) = delete;
    Car &operator =(const Car&) = delete;
    Car& operator = (Car&&)=delete;
    // Car();
};


int main(){
    /*this is creating the object and in line 50 we are coping it to the vector
        Car c1(101,100.0f,Rating::_4_STAR);
        Car c2(102, 1002.0f,Rating::_3_STAR);

        option 2 : copying the c2,c1 to vector CAR
        std::vector<Car> cars {c1,c2};
    */

   //option 3
    std::vector<Car> cars;
    cars.emplace_back(101,100.0f,Rating::_4_STAR);
    cars.emplace_back(102, 1002.0f,Rating::_3_STAR);

    std::cout<<"The number of elements in the vector currently : "<<cars.size()<<"\n";
    /*
        option 1 :Enable copy constructor
        option 2 : Moving cars (not applicable in this context)
        OPTION 3 : Create data inside the vector
    */



    //FEATURE 9
    // int32_t n1= 10; // 32 bit/ 4 bytes memory for integer
    // int16_t n1 = 20; //16 bit/ 2 bytes memory for integer


}

