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
#include <time.h>

using namespace std;

long int primegenerator(){

  srand (time(NULL));
  int check = 0;
while (check == 0){
  long int test = rand()%1000;
  check = prime(test);
}
 return test;

}







#endif // ENCRYPTOR_H
