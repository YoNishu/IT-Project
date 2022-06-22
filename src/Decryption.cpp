#include "Decryption.h"
#include <iostream>
#include <string.h>
#include "Encryption.h"
struct node
{
    string name;
    int publickey;
    node* link;

};
using namespace std;
Decryption::Decryption(Encryption &m)
{
    length2=m.length;


    for(int i=0;i<length2;i++)
    {
        encr_digit[i]=m.en1_digit[i];
    }

// we are giving different private key to send message to different person for encrypt message
//using linked list
node*head;
    node* n1=new(node);
    n1->name="raj";
    n1->publickey=165;
    head=n1;
    node* n2=new(node);
    n2->name="kashyap";
    n2->publickey=1293;
    n1->link=n2;
    node* n3=new(node);
    n3->name="shrey";
    n3->publickey=1419;
    n2->link=n3;
    n3->link=NULL;
    node* n4=new(node);
    n4->name="nishith";
    n4->publickey=1421;
    n3->link=n4;
    node* n5=new(node);
    n5->name="mudit";
    n5->publickey=2183;
    n4->link=n5;

    node*search;
    node*ptr;
     search=head;
    while(search)
    {
        ptr=search;
        if(search->name==m.receiver)
        {
            break;
        }
        search=search->link;
    }
    d=ptr->publickey;




    n=47*53;
    //ctor
}

Decryption::~Decryption()
{
    //dtor
}

string Decryption:: originalmessage()
{
    long int ct,k;
    char fine;
    for(int j=0;j<length2;j++)
    {
        ct=encr_digit[j];
        k=1;
        for(int i=0;i<d;i++)
        {
            k=k*ct;
            k=k%n;

        }

        fine=k+96;
        decry[j]=fine;

    }

    string temp2="";

    for(int i=0;i<length2;i++)
    {
        temp2+=decry[i];
    }
    return temp2;
}

