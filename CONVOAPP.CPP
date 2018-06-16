#include <iostream.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<ctype.h>
//start:Public function prototypes and global current user variables
void sp(int down,int left);
class user;
class chatroom;
class db;
void main();
void userControlPanel(char *uname);
char current_user[30];   //current user
char chatrooms[500][30]; //All chatrooms collected from file
int chatroom_count =0; //no_of chats;
char chatroom[30]; //current chatroom;
//end:Public function prototypes and global

//start: global functions
//ui designing function
 void sp(int down, int left) {
   for(int i =0;i<down;i++) {
    cout << "\n";
   }
   for(int l =0;l<left;l++) {
    cout << " ";
   }
 }
//end: global functions


/*start: Message class definition
  //Sample implementation code
     void main() {
       clrscr();
       message msg1;
       msg1.inputMessage();
       msg1.output();
       getch();
      }
   //Status: Fully working and operational
*/

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
      cout<< endl <<endl;
      cout << "Message from ";
      puts(from) ;  cout << "to ";
      puts(to) ;    cout << endl << "Title: ";
      puts(title);  cout << endl;
      puts(msg);    cout << endl;
      cout << endl;
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
     cout << "Input message(Enter . to terminate : " << endl;
     cin.getline(msg,200,'.');
     cout << "Send ? ... (Y/N) ";
     cin >> ch;
    if(ch == 'Y' || ch == 'y') {
	msg_status = 1;
	cout << "Message send.";
     } else {
       // goto input;
     }
     cout << endl;
   }

//end: Message class definition

//1.

//start: User class definition

//Users start
  class user {
	char username[30];
	char pw[30];
	char about[100];
	float activity;
	float start,mins,end,seconds;
   public:
     //default constuctor
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

   //Create new user
       void create()  {
	 sp(1,2);
	 cout << "Registration: ";
	 cin.ignore();
	 sp(3,2);
	 cout<<"Enter user name: ";
	 cin.getline(username,30);
	 cin.ignore(0,'\n');
	 sp(1,2);
	 cout<<"Enter password: ";
	 cin.getline(pw,30);
	 sp(1,2);
	 cout << "About yourself [100 wrds max] :  " ;
	 sp(1,2);
	 cout << "(Terminate with .)" ;
	 sp(1,0);
	 cin.getline(about,100,'.');
       }
   //Print out user details
      void printUserData() {
	cout << username << endl;
	cout << pw << endl;
	cout << about << endl;
      }



	//stop and log time on user logout
	  void logout() {
	    end=time(0);
	    seconds=difftime(end,start);
	    mins=seconds/60;
	}

	//write user data to users.txt
	void writeUserData(user obj) {
	   //obj must be intialized with values at this point
	 ofstream db("users.txt",ios::app|ios::binary);
	 db.write((char*)&obj,sizeof(obj));
	 db.close();
	 sp(0,2);
	 cout<<"Registeration complete!!";
	}

	//intialises a temp variable with username value
	void  uname(char input[30]) {
	  for(int i =0;i<30;i++) {
	   input[i] = username[i];
	  }
	}

       //initialises a temp variable with pwd value
	void  pwd(char input[30]) {
	  for(int i =0;i<30;i++) {
	   input[i] = pw[i];
	  }
	}


   //read All User from db
      void readUserFromDb() {
       user ts[100];
       ifstream db;
       db.open("users.txt",ios::in|ios::binary);
       clrscr();
       db.seekg(0);
       int i =0; //user object array counter
       cout << "The Users Databbase: " << endl;
       while(!db.eof()) {
	db.read((char*)&ts[i],sizeof(ts[i]));
	ts[i].printUserData();
	cout << endl;
	i++;
	getch();
       } // end of while
      }  //end of read db function

   //search user database for user
     void searchUser(char* login_name,char* login_code) {
	user ts[100];
       ifstream db;
       db.open("users.txt",ios::in|ios::binary);
       clrscr();
       db.seekg(0);
       int i =0; //user object array counter
       int flag = 0;
       char uname[30];
       char pwd[30];
       sp(2,0);
       while(!db.eof()) {
	db.read((char*)&ts[i],sizeof(ts[i]));
	ts[i].uname(uname);
	ts[i].pwd(pwd);
	//comparing credentails
	if(!strcmp(uname,login_name)) {
	 if(!strcmp(pwd,login_code)) {
	   clrscr();
	   flag=1;
	   userControlPanel(uname);
	   getch();
	   break;
	 } else {
	   clrscr();
	   cout << "User identified with Wrong password";
	   getch();
	   main();
	 }
	} else {
	  continue; // user does not match , check next record
	}
	i++;
       }  //end of while
       if(!flag) {
	clrscr();
	cout << "No such user exists .";
	getch();
	main();
       }
     }    //end of fucntion searchUser
};
//end: User class definition

//2.

//start:Chatroom class definition
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
  //prototypes
   void create(char *creator);
   void printpp();   //print participants

   //inline functions

   //intialises a temp variable with name value
      void name(char input[30]) {
	for(int i =0;i<30;i++) {
	  input[i] = name[i];
	 }
      }
} newChatroom,tc[100] ;

void chatroom :: create(char *creator) {
   clrscr();
   char ch;
   char name[30];
   char p_input[30];
   strcpy(pp[0],creator);
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
    for(ppsize =1,index =1;ppsize<=max;ppsize++,index++) {
       cout << endl << "Input participant " << ppsize << ":" ;
       gets(p_input);
       if(strcmp(p_input,"end") == 0 || strcmp(p_input,"END") == 0) {
	 break;
       }else{
	strcpy(pp[index],p_input);
       }
    }//end of forloop
   } else {
     userControlPanel(creator);
   }
}; //endof create function;

void chatroom :: printpp() {
  cout << endl << "Participants are:" ;
  cout << endl;
  for(int i =0;i<ppsize-1;i++) {
    puts(pp[i]);
  }
}



//end: Chatroom class defintion


//start: Homescreen functions

//User Registration
   void newUser() {
    user newUser;
    clrscr();
    newUser.create();
    newUser.writeUserData(newUser);
    getch();
    main();
   }

//to handle existing users
void existingUser() {
    //login screen
    clrscr();
    char login_name[30];
    char login_pwd[30];
    sp(1,2);
     cout << "Login: ";
     cin.ignore();
     sp(3,2);
     cout<<"Enter user name: ";
     cin.getline(login_name,30);
     cin.ignore(0,'\n');
     sp(1,2);
     cout<<"Enter password: ";
     cin.getline(login_pwd,30);
     sp(1,2);
     user temp_loginuser;
     temp_loginuser.searchUser(login_name,login_pwd);
   } ;

 //User Menu Screen
     void userControlPanel(char *uname) {
      int ch ;
      strcpy(current_user,uname);
      sp(1,1);
      cout << "Welcome back, " << uname;
      sp(3,3);
      cout << "1.Create Chatroom" ;
      sp(2,3);
      cout << "2.Join Chatroom";
      sp(2,3);
      cout << "3.Back ";
      sp(3,3);
      cout << "Input ch number: " ;
      cin >> ch;
      if(ch == 1 ) {
 //:start chatroom database handling (inserting records)
       newChatroom.create(uname);
       ofstream db("chatrooms.txt",ios::app|ios::binary);
       db.write((char*)&newChatroom,sizeof(newChatroom));
       db.close();
       sp(2,0);
       cout<<"Chatroom registered";
       getch();
       clrscr();
       userControlPanel(uname);
  //:end chatroom database handling  (inserting records)
      } else if(ch == 2) {
   //:start chatroom database handling (searching records)
       char login_chatname[30];
       sp(2,0);
       cout << "Enter name of chatroom" ;
   //:end chatroom database handling (searching records)
      } else if(ch == 3) {
	main(); //back to homescreen
      }else {
       clrscr();
       cout << "invalid option" ;
       getch();
       clrscr();
       userControlPanel(uname);
      }
     };

//end: Homescreen functions

void main() {
  clrscr();
   int user_ch;
  //Homescreen
    sp(1,0);
    cout << "LAN Messenger:";
    sp(3,3);
    cout << "1.New User" ;
    sp(1,3);
    cout << "2.Existing user";
    sp(1,3);
    cout << "3.Settings";
    sp(1,3);
    cout << "4.Exit";
    sp(2,3);
    cout << "Input path no. ";
    cin >> user_ch;
    if(user_ch == 1) {
   //User Regstration path
       newUser();
    }else if(user_ch == 2) {
       existingUser();
    }else if(user_ch == 3) {
   //Admin Backend path
      clrscr();
      cout << "Welcome to admin settings:" << endl;
      cout << "Input pwd : ";
      char pwd[10];
      gets(pwd);
      if(!strcmp(pwd,"admin") || !strcmp(pwd,"ADMIN")){
       clrscr();
       user admin;
       admin.readUserFromDb();
      } else {
	cout << "Wrong password";
      }
    } else if(user_ch == 4) {
      abort();
    }else {
      clrscr();
      cout << "Invalid choice" << endl;
      getch();
      clrscr();
      main();
    }

   getch();
}