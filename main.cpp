#include <iostream>
#include <math.h>
#include "Encryption.h"
#include "Decryption.h"
#include <string.h>


using namespace std;


int main()
{
string s1="";                 //store encrypted message

string s2="";                 //store decrypted message


string name ;
cout<<"                     sender side                    "<<endl;

cout<<"enter a name from your contact whom you want to send a message "<<endl;

cout<<"your contact list:"<<endl;

cout<<"raj"<<endl<<"shrey"<<endl<<"kashyap"<<endl<<"nishith"<<endl<<"mudit"<<endl<<endl;

getline(cin,name);                         //name of receiver selected by user

  string  message;
    cout<<"Enter your message :"<<endl;

  getline(cin,message);

int length=message.length();
for(int i=0;i<length;i++)
{
    string s = "";
    while(message[i]!= ' ')
    {
        if(i==length)
            break;
        s+=message[i];
        i++;
    }
     Encryption m1(s,name);
   s1+= m1.Encry();
    s1+=" ";
    Decryption m2(m1);
    s2+=m2.originalmessage();
    s2+=" ";
}
cout<<endl<<endl;
cout<<"encrypted message which is sent by the sender "<<endl;

cout<<s1<<endl;           //encrypted message which is sent to the receiver
cout<<endl<<endl;

cout<<"                     receiver side                    "<<endl;

cout<<"receiver get the message from encrypted message :"<<endl<<endl;

cout<<s2;                 //decrypted message which is decrypted from encrypted message

    return 0;
}
