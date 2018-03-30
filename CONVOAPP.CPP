#include <iostream.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
void sp(int down,int left);

//message class start
  // Sample implementation code

  /* void main() {
     clrscr();
     message msg1;
     msg1.inputMessage();
     msg1.output();
     getch();
  } */


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
     cout << "Input user id of reciever: " <<endl;
     cin.getline(to,30);
     cout << "Input title of message : " << endl;
     cin.getline(title,30);
     cout << "Input message : " << endl;
     cin.getline(msg,200,'.');
     cout << "Send ? ... (Y/N) ";
     cin >> ch;
    if(ch == 'Y' || ch == 'y') {
	msg_status = 1;
	cout << "Message send.";
     } else {
	goto input;
     }
     cout << endl;
   }

//message end

//Sample implementation for user class
/*
void main()
{
	User x;
	x.create();
	x.login();
	x.logout();
	cout<<x.time();
	getch();
} */
//ui designing function
 void sp(int down, int left) {
   for(int i =0;i<down;i++) {
    cout << "\n";
   }
   for(int l =0;l<left;l++) {
    cout << " ";
   }
 }
//chatroom start
class chatroom {
//participants
   char pp[10][10];
   int max;
  public:
  int ppsize ;
  chatroom() {
    ppsize = 0;
    max =20;
  }
  //custom max users
  chatroom(int i) {
     max =i;
  }
   void create();
//print participants
   void printpp();
};

void chatroom :: create() {
   clrscr();
   char ch;
   char name[30];
   char p_input[30];
//intializing p_input  and pp size
   strcpy(p_input,"empty");
   cout << endl << "Create new chatroom ? (Y/N): ";
   cin >>ch;
   if(ch == 'Y' || ch == 'y') {
      cout << endl << "Enter name of chatroom: ";
      gets(name);
   //cap on max users is 100 by defulat
      cout << "Enter end to terminate." << endl;
    int index;
    for(ppsize =1,index =0;ppsize<=max;ppsize++,index++) {
       cout << endl << "Input participant " << ppsize << ":" ;
       gets(p_input);
       if(strcmp(p_input,"end") == 0 || strcmp(p_input,"END") == 0) {
	 break;
       }else{
	strcpy(pp[index],p_input);
       }
    }//end of forloop
   } // end of Y/N if statement
}; //endof create function;

void chatroom :: printpp() {
  cout << endl << "Participants are:" ;
  cout << endl;
  for(int i =0;i<ppsize-1;i++) {
    puts(pp[i]);
  }
}
//chatroom end

//Users start
  class user {
	char username[30];
	char pw[30];
	char about[100];
	float activity;
   public:
	float start,mins,end,seconds;
     //default constuctor
       void uname(char input[30]);
       user() {
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
	 sp(1,2);
	 cout << "Registration: ";
	 sp(3,2);
	 cout<<"Enter user name: ";
	 sp(0,3);
	 cin>>username;
	 sp(0,2);
	 cout<<"Enter password: ";
	 sp(0,3);
	 cin>>pw;
	 sp(0,2);
	 fstream db;
	 db.open("users.txt",ios::out|ios::app);
	 if(!db) {
	  clrscr();
	  cout << endl << "Error \n";
	  cout << "Cannot open database of users.";
	 }
	 db << username << " " << pw << " " << activity <<"."<< "\n";
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

};


//return username
       void user :: uname(char input[30]) {
	  for(int i =0;i<30;i++) {
	   input[i] = username[i];
	  }
       }
//User end


 //homescreen functionilty start
   void newUser() {
    user newUser;
    clrscr();
    newUser.create();
   }

 //homescreen end


 void main() {
   clrscr();
   int user_ch;
  //Homescreen
    homescreen:
    sp(1,0);
    cout << "LAN Messenger:";
    sp(3,3);
    cout << "1.New User" ;
    sp(1,3);
    cout << "2.Existing user";
    sp(1,3);
    cout << "3.Settings";
    sp(2,3);
    cout << "Input path no. ";
    cin >> user_ch;
    if(user_ch == 1) {
     newUser();
    } else {
     clrscr();
     cout << "Invalid choice" << endl;
     cout << "Restart app";
    }

   getch();
 }

