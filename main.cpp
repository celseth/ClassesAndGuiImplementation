

#include "std_lib_facilities.h"
#include "person.h"
#include "meeting.h"
#include "meetingWindow.h"

int main()
{

	Car car1{2};
	Car car2{0};
	Person person1{"Ole", "Ole@hotmail.com",&car1};
	Person person2{"JEsper", "Jesp@live.no",&car2};
	Person Person3{"Anders","A@hotmail.com"};

	Meeting mote1{2,10,13,Campus::trondheim, "Matte", &Person3};
	mote1.addParticipant(&person1);
	mote1.addParticipant(&person2);




	int valg=2;
	while (valg!=0){
		cout << "1.person\n2.mote\n3.Gui";
		cin>>valg;
		if (valg==1){
			cout << person1 << endl << person2 << endl << Person3 << endl;
		}
		else if (valg==2)
		{
			cout << mote1 << endl;
			
		}
		else if (valg==3){
			//// GUI
			constexpr int width = 400;
			constexpr int height = 600;
			const Point top_left{(x_max() - width) / 2, (y_max() - height) / 2};
			MeetingWindow Window{top_left, width, height, "MeetingWindow"};
			gui_main();

			Window.showPeople();
		}
	}





	keep_window_open();
}

//------------------------------------------------------------------------------
