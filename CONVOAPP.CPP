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
  class User {
	char username[30];
	char pw[30];
	char about[100];
	float activity;
   public:
	float start,mins,end,seconds;
     //default constuctor
       User() {
	strcpy(username,"empty");
	strcpy(pw,"empty");
	strcpy(about,"empty");
	activity = 0;
      }

     //start timer on login
       void timestart() {
	 start= time(0);
       }
     //Register user
       void create()  {
	 cout<<"Enter user name: "<<endl;
	 cin>>username;
	 cout<<"Enter password: "<<endl;
	 cin>>pw;
	 cout<<"Registeration complete!!";
       }
   //Login
	void login() {
		char chkuser[30];
		char chkpass[30];
		cout << endl << "Login: " << endl;
		cout<<" Enter username: ";
		cin >>chkuser;    cout<<endl;
		cout<<"Enter password: ";
		cin>>chkpass;
		if (!(strcmp(username,chkuser)) && !(strcmp(pw,chkpass))) {
		  clrscr();
		  cout<<"Welcome "<<chkuser<<endl;
		  timestart();
		  //Subject to change
		} else {
		  cout<<"User does not exist.";
		}
	}


	//stop and log time on user logout
	  void logout() {
	    end=time(0);
	    seconds=difftime(end,start);
	    mins=seconds/60;
	}

}; //User end

//Main driver function
void main()
{
	User x;
	x.create();
	x.login();
	//x.logout();
       //	cout<<x.time();
	getch();
}



//Users end
