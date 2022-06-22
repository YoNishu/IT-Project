#ifndef DECRYPTION_H
#define DECRYPTION_H
#include "Encryption.h"
#include <iostream>

using namespace std;
class Decryption
{
    public:
        Decryption(Encryption &m ); //we pass to the object of Encrypted class to access Encrypted message
        virtual ~Decryption();
        string originalmessage();  //this function is doing decryption from encrypted message


    protected:

    private:
        int d; // this is private key using this receiver get original message(decrypted message)
               // d is different for every receiver so even though third person get message but, he cant get decrypted message

        int n;
        int encr_digit[20]; //encrypted message is stored here
        char decry[20];     //Decrypted message is sored in this array
        int length2;


};

#endif // DECRYPTION_H
