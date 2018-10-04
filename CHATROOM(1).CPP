// Prakhar.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
//using namespace std;

class user
{
public:
	char users[64];
	char pass[64];
	time_t start, end;
	double seconds;
	double mins;
	void makeuser()  //CREATING USERNAME
	{
		cout << "Enter user name: " << endl;
		cin >> users;
		cout << "Enter password: " << endl;
		cin >> pass;
		cout << " User created!! " << endl;
	}
	int checkpass() //LOGGING IN
	{
		char chkuser[64];
		char chkpass[64];
		cout << "Enter username: ";
		cin >> chkuser;
		cout << "Enter password: ";
		cin >> chkpass;
		if (!(strcmp(users, chkuser)) && !(strcmp(pass, chkpass)))
		{
			cout << "Welcome " << chkuser << endl;
			timestart();
			return 0;
		}


		cout << "Such a user does not exist";
		return 1;

	}
	void timestart()  //FOR WHEN THE USER LOGS IN
	{
		start = time(0);
		cout << "Start time" << start << endl;
	}
	void endtime()   //FOR WHEN THE USER LOGS OUT
	{
		end = time(0);
		cout << "End time" << end << endl;
		seconds = difftime(end, start);
		mins = seconds / 60;
		cout << "Min: " << mins << endl;
	}

};
int main()
{
	user x;
	x.makeuser();
	if(!x.checkpass())
	{
		x.endtime();
		cout << "Time spent" << x.mins << endl;
	}
	getch();
	return 0;
}


