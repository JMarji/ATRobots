#include <iostream>
#include <string>
#include "../atrlib.hpp"
using namespace std;

int main(void)
{
  string s, s1;
  s = "hello";
  char i;
  i ='a';
  unsigned int num l;
  cout << "enter 2 ints" <<endl;
  cin >> num;
  cin >> l;
  s1 = repchar(i, num);
}
