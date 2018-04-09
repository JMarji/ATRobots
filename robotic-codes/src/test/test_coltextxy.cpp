#include <iostream>
#include <string>
#include "../atrlib.hpp"
using namespace std;

int main(void)
{
  string s, s1;
  float j, x1, y1, x2, y2;
  unsigned char i;
  int num,l,k;
  s = "hello";
  i ='a';
  cout << "enter 2 int" <<endl;
  cin >> num;
  cin >> l;
  //cin >> x2;
  //cin >> y2;
  coltextxy(num, l, s, i);
}
