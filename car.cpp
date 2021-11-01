#include "car.h"

void Car::reserveFreeSeats(){
    freeSeats--;
}

bool Car::hasFreeSeats() const{
    if(freeSeats>0){
        return true;
    }
    else
    {
        return false;
    }
     
}