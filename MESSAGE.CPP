#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

//general blueprint for messages
 class message {
   char title[30];
   char from[30];
   char to[30];
   char msg[200];
  public:
  int msg_status;
  static int msg_count;
  /* msg status of 1 indicates no error
    msg status of 0 indicates a error */
//prototypes
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
//constructor2
   message(char t[30],char f[30],char too[30],char m[200]) {
    msg_status = 1;
    msg_count++;
    checkInput(t,30);
    checkInput(f,30);
    checkInput(to,30);
    checkInput(msg,200);
    //checks for error
     if(msg_status == 0) {
      cout <<  "Go to input screen";
       //instead of this cout the input function goes here
      } else{
       strcpy(title,t);
       strcpy(from,f);
       strcpy(to,too);
       strcpy(msg,m);
      }
    }

 }; //end of message class

 int message :: msg_count = 0;

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
      cout.write(from,30) ;  cout << endl;
      cout.write(to,30) ;    cout << endl;
      cout.write(title,30);  cout << endl;
      cout.write(msg,200);    cout << endl;
   }
//Input message
   void inputMessage() {
    char title[30];
    char from[30];
    char to[30];
    char msg[200];
    char ch;
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
       message convo_msg(title,from,to,msg);
       convo_msg.output();
     } else {
       inputMessage();
     }
     cout << endl;
   }

  void main() {
    clrscr();
    inputMessage();
    getch();
  }