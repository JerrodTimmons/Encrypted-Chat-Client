#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H

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
 long int test;
  srand (time(NULL));
  int check = 0;
while (check == 0){
  long int test = rand()%1000;
  check = prime(test);
}
 return test;

}







#endif // PRIMEGENERATOR_H
