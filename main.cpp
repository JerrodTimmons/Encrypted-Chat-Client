#include <fstream>
#include "encryptor.h"
#include <algorithm>

using namespace std;

void createValues(long int, long int, long int, long int, long int, char *, long long int *, int);

int main()
{
 string inputMessage;
 ifstream myfile("log.txt");

 if (myfile.is_open())
  {
   getline(myfile, inputMessage);
   myfile.close();
  }
   else cout<<"Unable to open file";
 remove("log.txt");

 int i;
 for (i = 0; i < inputMessage.length(); i++)
    {
    if(isspace(inputMessage[i])){
     inputMessage[i] = 32;
    }
    };

 long int prime1, prime2;
 prime1 = 97;//prime();
 prime2 = 101;//prime();

 char array[100];


    long int msg[100];
    long int n = prime1*prime2;
    long int phi = (prime1-1) * (prime2-1);
    int length = inputMessage.length();
    long long int *en[100];

    for (i = 0; i <= length; i++)
    {
        msg[i] = inputMessage[i];
    }


    createValues(phi, prime1,prime2, msg, n, array, *en, length);

    }



