#include "meetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title)
    : Graph_lib::Window(xy,w,h,title),
    quitBtn{Point{x_max()-btnW-pad,pad},btnW,btnH,"Quit", cb_quit},
    personNewBtn{Point{x_max()-btnW-pad,pad*4},btnW,btnH,"addPerson", cb_new_person},
    personEmail{Point{fieldPad, pad},fieldW, btnH, "Email"},
    personName{Point{fieldPad, pad*4},fieldW, btnH, "name"}
{
    attach(quitBtn);
    attach(personNewBtn);
    attach(personName);
    attach(personEmail);
}

void MeetingWindow::cb_quit(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::addPerson(){
    string name= personName.get_string();
    string email=personEmail.get_string();
    people.push_back(new Person{name,email});
    if(!name.size() ||!email.size()){
        return;
    }

    personEmail.clear_value();
    personName.clear_value();
}
void MeetingWindow::cb_new_person(Address, Address pw)
{
	reference_to<MeetingWindow>(pw).addPerson();
}