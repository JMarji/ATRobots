#include <iostream>
#include <cstdlib>

using namespace std;

#define locktype 3
string encode(string s);

string fn1, fn2, s, s1, s2, lock_code;
char f1, f2;
int i, j, k, lock_pos, lock_dat, this_dat;

int main(int argc, char* argv[]){
  if (argc < 3){
    std::cerr << "Need string and number\n";
    return EXIT_FAILURE;
  }
  lock_code = argv[2];
  cout << (encode(argv[1]));
  cout << ("\n");
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
