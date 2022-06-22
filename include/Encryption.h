#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <iostream>
using namespace std;

class Encryption
{
    public:
        Encryption(string message,string name); //string is name of to whom you send the message
        virtual ~Encryption();
        string Encry();    //function for Encrypt the message

         char en1[20];     //Encrypted message
         int en1_digit[20]; //each char of encrypted message converted into specific value
                           //example a->00, b->01, c->02..
    int length;
    string receiver;  //store the name of to whom u want to send a message

    protected:

    private:
        int m[80];   //original message in ASCII value


        long int p; //1st prime number
        long int q; //2nd prime number
        long int n; //p*q
        long int e; //public key


};

#endif // ENCRYPTION_H
