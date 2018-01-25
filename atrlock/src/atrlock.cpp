/* C++ version of ATRLOCK

*/

#include <iostream>
#include <cstdlib>
#include "atrlib.hpp"

using namespace std;

#define locktype 3
string encode(string s);
string prepare(string s, string s1);
void write_line(string s, string s1);

string fn1, fn2, s, s1, s2, lock_code;
char f1, f2;
int i, j, k, lock_pos, lock_dat, this_dat;

int main(int argc, char* argv[]){
  return EXIT_SUCCESS;
}

string encode(string s){  //Ported by Ed Green
  int i, j, k;
  if (lock_code != ""){
    for (i = 1; i <= s.length(); i++){
      lock_pos++;
      if (lock_pos > lock_code.length()){
        lock_pos = 1;
      }
      if ((int(s[i]) >= 0 && int(s[i]) <= 31) || (int(s[i]) >= 128 && int(s[i]) <= 255)){
        // this is simpler in Pascal, if it's within two ranges (0-31 and 128-255)
        s[i] = ' ';
      }
      this_dat = int(s[i]) & 15;
      //Line 69 ---____---
      s[i] = char((int(s[i]) ^ (int(lock_code[lock_pos]) ^ lock_dat)) + 1);
      lock_dat = this_dat;
    }
  }
  return s;
}

string prepare(string s, string s1){ //Ported by Jordan LaComb
  int i, j, k, l;
  string s2;
  if ((s1.length() == 0) || (s1[1] == ';')){
     s1 = '';
  }
  else{
    k = 0;
    for (i = s1.length(); i >= 1; i--){
        if (s1[1] = ';'){
           k = 1;
        }
        if (k > 0){
           s1 = lstr(s1, k-1); // ended here
        }
    }
  }

  return "";
}

void write_line(string s, string s1){

}
