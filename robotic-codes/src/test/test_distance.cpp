#include <iostream>
#include <string>
#include "../atrlib.hpp"
using namespace std;

int main(void)
{
  string s, s1;
  float j, x1, y1, x2, y2;
  char i;
  int num,l,k;
  s = "hello";
  i ='a';
  cout << "enter 4 floats" <<endl;
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;
  j = distance(x1, y1, x2, y2);
}
