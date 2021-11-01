#include "meeting.h"

Meeting::Meeting(int day,int startTime,int endTime,Campus location,string subject,const Person* leader):
day{day},startTime{startTime},endTime{endTime},location{location},subject{subject},leader{leader}{
    participants.insert(leader);
    meetings.insert(this); 
};

Meeting::~Meeting(){
    for (auto element :  meetings)
    {
        meetings.erase(element);
    }    
}

vector<string> Meeting::getParticipantList() const{
    vector<string> participants1;
    for(auto parti:participants){
        participants1.push_back(parti->getName());
    }
    return participants1;
}

ostream& operator<<(ostream& os, const Meeting& M){

	os << "Subject: " <<  M.getSubject() << endl
    << "Location: " << LocationtoString.at(M.getLocation()) << endl
    << "Starttime: " << M.getStartTime() << endl
    << "Endtime: " << M.getEndTime() << endl 
    << "Moteleder: " << M.getLeader();
    vector<string> p=M.getParticipantList();
    for (int i = 0; i < p.size(); i++)
    {
        os <<"Navn: " << p[i] << endl;
    }
    
	return os;
}
vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> potDriver;
    for (auto element:meetings){
        if(element->getLocation()==location &&element!=this && abs(element->getStartTime()-startTime)<1 && abs(element->getEndTime()-endTime)<1){
            for(auto person:element->participants){
                if(person->hasAvailableSeats()==true){
                    potDriver.push_back(person);
                }

            };
        }
        
    }
    return potDriver;
}
set<const Meeting*> Meeting::meetings;
