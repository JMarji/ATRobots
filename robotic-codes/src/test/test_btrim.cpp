#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "/usr/include/boost/algorithm/string/trim.hpp"
//#include "btrim.cpp"
#define _USE_MATH_DEFINES
#define byte uint8_t
#define word uint16_t
using namespace std;
//using namespace atrlib;

int main(void)
{
  string hello;
  string s1;
  cout<< "enter a string to be trimed";
  cin >> s1;
  boost::algorithm::trim(s1);
  cout<<s1;

  return 0;
}
