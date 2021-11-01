#pragma once
#include "car.h"

class Person{
private:
    string name;
    string email;
    Car* car;

public:
    Person(string name, string email, Car* car=nullptr): name{name},email{email},car{car}{};
    string getName() const{return name;}
    string getEmail(){return email;}
    void setEmail(string email){email=email;};
    bool hasAvailableSeats()const;
    friend ostream& operator<<(ostream& os, const Person& person);
    
};