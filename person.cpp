#include "person.h"

bool Person::hasAvailableSeats()const{
    if (car!=nullptr){
        return true;
    }
    else{
        return false;
    }
};

ostream& operator<<(ostream& os, const Person& Person){

	os << "Navn: " <<Person.name << ", Email: " << Person.email;
	return os;
}