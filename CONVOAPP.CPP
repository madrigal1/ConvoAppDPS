#include <iostream.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//message class start
  // Sample implementation code

  //  void main() {
  //  clrscr();
  //  message msg1;
  //  msg1.inputMessage();
  //  msg1.output();
  //  getch();
  // }


//general blueprint for messages
 class message {
   char title[30];
   char from[30];
   char to[30];
   char msg[200];
  public:
  int msg_status;
  /* msg status of 1 indicates user confirmed success delivery of message
    msg status of 0 indicates a error */
//prototypes
    void inputMessage();
    void checkInput(char x[300],int max);
    void output();
//default constructor
   message() {
     strcpy(title,"error") ;
     strcpy(from,"error");
     strcpy(to,"error");
     strcpy(msg,"error");
     msg_status = 0;
   }
 }; //end of message class


//validator for inputs to the message objects
   void message::checkInput(char x[300],int max) {
     if(!(strlen(x) <= max)) {
      cout << "Input must be less than 30 characters";
      msg_status = 0;
      //add input function here.
    }
   }
//Output message
   void message :: output() {
      cout<< endl;
      cout << "message start" << endl;
      puts(from) ;  cout << endl;
      puts(to) ;    cout << endl;
      puts(title);  cout << endl;
      puts(msg);    cout << endl;
      cout << "message end" << endl;
   }
//Input message
   void message :: inputMessage() {
    char ch;
   input:
     strcpy(from,"CurrentUser");   //Chage crt user with the logged in user
     cout << "Input user id of reciever:" <<endl;
     cin.getline(to,30);
     cout << "Input title of message :" << endl;
     cin.getline(title,30);
     cout << "Input message : " << endl;
     cin.getline(msg,200,'.');
     cout << "Send ? ... (Y/N) ";
     cin >> ch;
    if(ch == 'Y' || ch == 'y') {
	msg_status = 1;
	cout << "Message send";
     } else {
	goto input;
     }
     cout << endl;
   }

//message end



//Users start
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



//Users end