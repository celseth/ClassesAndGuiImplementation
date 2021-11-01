#pragma once
#include "std_lib_facilities.h"
#include "GUI.h" 
#include "Window.h"
#include "person.h"
#include "meeting.h"
using namespace Graph_lib;




class MeetingWindow : public Graph_lib::Window {
private:
	static constexpr int btnW = 100; 
	static constexpr int btnH = 30;
	static constexpr int pad = 20;
	static constexpr int fieldPad = 50;
	static constexpr int fieldW = 200;
	static constexpr int fieldH = 20;

    Button quitBtn;
    static void cb_quit(Address, Address pw);
    In_box personName;
    In_box personEmail;
    Vector_ref<Person> people;

    Button personNewBtn;
    static void cb_new_person(Address, Address pw);
    void addPerson();


    

public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    void showPeople(){for(auto element : people){
        cout << *element << endl;
    }}

};