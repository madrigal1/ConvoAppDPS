#include <iostream.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
class user
{
	public:
	char users[30];
	char pass[30];
	time_t start,end;
	float seconds;
	float mins;
	void makeuser()  //CREATING USERNAME
	{
		cout<<"Enter user name: "<<endl;
		cin>>users;
		cout<<"Enter password: "<<endl;
		cin>>pass;
		cout<<" User created!! ";
	}
	void checkpass() //LOGGING IN
	{
		char*chkuser;
		char *chkpass;
		cout<<" Enter username: ";
		cin>>chkuser;
		cout<<"Enter password: ";
		cin>>chkpass;
		if (!(strcmp(users,chkuser)) && !(strcmp(pass,chkpass)))
		{
			cout<<"Welcome "<<chkuser<<endl;
			timestart();
			//Subject to change
		}
		else
		{	cout<<"Such a user does not exist";
			timestart();
		}
	}
	void timestart()  //FOR WHEN THE USER LOGS IN
	{
		start= time(0);
	}
	void endtime()   //FOR WHEN THE USER LOGS OUT
	{
		end=time(0);
		seconds=difftime(end,start);
		mins=seconds/60;
	}

};
void main()
{
	user x;
	x.makeuser();
	x.checkpass();
	x.endtime();
	cout<<x.mins;
	getch();
}


