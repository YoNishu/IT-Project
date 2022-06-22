#include "Encryption.h"
#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    string name;
    int publickey;//to encrypt message ,(this is different for every person,)
    node* link;

};
Encryption::Encryption(string message,string name2)
{
    // we are giving different public key to send message to different person for encrypt message
    //using linked list
    node*head;
    node* n1=new(node);
    n1->name="raj";
    n1->publickey=29;
    head=n1;
    node* n2=new(node);
    n2->name="kashyap";
    n2->publickey=37;
    n1->link=n2;
    node* n3=new(node);
    n3->name="shrey";
    n3->publickey=59;
    n2->link=n3;
   node* n4=new(node);
    n4->name="nishith";
    n4->publickey=101;
    n3->link=n4;
    node* n5=new(node);
    n5->name="mudit";
    n5->publickey=103;
    n4->link=n5;


    node*search;
    node*ptr;
    search=head;
    while(search)  //searching for public key for selected name
    {
        ptr=search;
        if(search->name==name2)
        {
            break;
        }
        search=search->link;
    }
    e=ptr->publickey;
    receiver=ptr->name;

    length=message.size();
    for(int i=0;i<length;i++){
        m[i]=message[i];
    }

        p=47;
        q=53;
        n=p*q;


    //ctor
}

Encryption::~Encryption()
{
    //dtor
}
string  Encryption:: Encry()
{
    int k,k2;

    for(int i=0;i<length;i++)
    {
        k2=1;
      k=m[i];
      k=k-96;    //by doing this each char converted into specific number(a->00,b->01,c->02 etc..)

      for(int j=0;j<e;j++)
      {
          k2*=k;
          k2=k2%n;
      }
     k2=k2%n;
      en1_digit[i]=k2;
     char ct=k2;
      en1[i]=ct+96; //by doing this we convert each letter into char


    }
  string temp="";

    for(int i=0;i<length;i++)
    {
        temp+=en1[i];
    }
return temp; //return encrypted word
}

