#pragma once
#include "car.h"
#include "person.h"

enum class Campus { trondheim=0, aalesund,gjovik};

const map<Campus,string> LocationtoString{
    {Campus::trondheim, "trondheim"},
    {Campus::aalesund,"aalesund"},
    {Campus::gjovik,"gjovik"}
};

class Meeting{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static set<const Meeting*> meetings;
public:
    Meeting(int day,int startTime,int endTime,Campus location,string subject,const Person* leader);
    int getDay() const{return day;}
    int getStartTime() const {return startTime;}
    int getEndTime() const{return endTime;}
    Campus getLocation()const{return location;}
    string getSubject()const{return subject;}
    Person getLeader()const{return *leader;}
    void addParticipant(Person* person){participants.insert(person);}
    ~Meeting();
    vector<string> getParticipantList() const;
    vector<const Person*> findPotentialCoDriving();

};

ostream& operator<<(ostream& os, const Meeting& M);