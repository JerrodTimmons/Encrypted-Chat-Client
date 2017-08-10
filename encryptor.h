#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include <bitset>
#include <stdlib.h>


using namespace std;

int prime(long int);
long int finde(long int, long int, long int, long int *, long int *);
long int findD(long int, long int);
void createValues(long int, long int, long int, long int, long int, long long int *, int);
long long int encrypt(long int *, long int *, long int, char *, long long int *, int);

long long encrypt(long int *message, long int *e, long int mod, char **messageChar, long long int *en, int Length)
{
  long long int length, k, plainText, cipherText, key = e[1];
  long long int cipher[100];
  int i = 0, j, counter;

 while (i != Length)
      {
       k = 1;
       plainText = message[i];

       for(j = 0; j < key; j++){
          k = k * plainText;
          k = k % mod;
          }
       cipher[i] = k;
       i++;
      }
 cipher[i] = -1;

 ofstream myfile;
 myfile.open ("textfile.txt");

 for (i = 0; cipher[i] != -1; i++)
    {
     myfile<<cipher[i]<<" ";
    };
 myfile<<"\n";
 myfile.close();

}


/********** CREATE VALUES FUNCTION ********************/

void createValues(long int phiFunction, long int pFunction, long int qFunction, long int M[100], long int mod, char *messageChar, long long int *EN, int Lengthincreate)
{
 long int e[100], d[100];
 long long int answer;

 finde(phiFunction, pFunction, qFunction, d, e);

 encrypt(&M[0], e, mod, &messageChar, EN, Lengthincreate);

}


/*********** PRIME FUNCTION *********************/

int prime(long int value)
{
 int i, test;

 test = sqrt(value);
 for (i = 2; i <= test; i++)
    {
     if (value % i == 0)
        return 0;
    }
 return 1;

}


/******** find e function **********************/

long int finde(long int functionPhi, long int p, long int q, long int *d, long int *e)
{
 int i, k = 0;
 long flag;

 for (i = 2; i < functionPhi; i++)
    {

    if ( functionPhi % i == 0)
       continue;
     flag = prime(i);

     if( (flag == 1) && (i != p) && (i != q) )
       {
        e[k] = i;
        flag = findD(e[k], functionPhi);
     if (flag > 0)
        {
         d[k] = flag;
         k++;
        }
       }
 if (k == 99)
    break;
    }
}


/******** FIND D FUNCTION **********************/

long int findD(long int e, long int phi)
{
 long int tester = 1;

 while (1 == 1)
      {
    tester = tester + phi;
    if (tester % e == 0)
       return (tester/e);
      }
}




#endif // ENCRYPTOR_H

