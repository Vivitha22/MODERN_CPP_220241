#include "Car.h"
#include "ICECar.h"
#include "EvCar.h"
#include<vector>
#include "Functionality.h"

int main(){
    std::vector<Car*> c;
    createObjects(c);
    ShowDetails(c,101);
    Deallocate(c);
}