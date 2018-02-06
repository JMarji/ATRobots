/* C++ version of ATRLOCK

*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include "atrlib.hpp"

using namespace std;
using namespace atrlib;

#define locktype 3
string encode(string s);
string prepare(string s, string s1);
void write_line(string s, string s1);

string fn1, fn2, s, s1, s2, lock_code; 
ifstream inputFile;
ofstream outputFile;
char currentDate[9];
int i, j, k, lock_pos, lock_dat, this_dat;

int main(int argc, char* argv[]){
  lock_pos = 0;
  lock_dat = 0;
  if ((argc < 2) || (argc > 3)){
     cout << "Usage: ATRLOCK <robot[.at2]> [locked[.atl]]";
     exit(0); //Check later
  }
  fn1 = btrim(ucase(argv[1]));
  if (fn1 == base_name(fn1)){
    fn1 = fn1 +'.AT2'
  }
  if (!(exist(fn1))){
    cout << "Robot \"" << fn1 << "\" not found!";
    exit(0);
  }
  if (argc == 2){
    fn2 = btrim(ucase(argv[2]));
  }
  else{
    fn2 = base_name(fn1) + '.ATL';
  }
  if (!(valid(fn2))){
    cout << "Output name \"" << fn1 << "\" not valid!";
    exit(0);
  }
  if (fn1 == fn2){
    cout << "Filenames can not be the same!";
    exit(0);
  }
  inputFile.open(fn1);
  outputFile.open(fn2);
  
  //copy comment header
  outputFile << ";------------------------------------------------------------------------------";
  s = '';
  while (!(inputFile.eof()) && (s == '')){
    inputFile >> s;
    s = btrim(s);
    if (s[1] == ';'){
      outputFile << s;
      s = '';
    }
  }
  //lock header
  outputFile << ";------------------------------------------------------------------------------";
  _strdate(currentDate);
  outputFile << "; " << no_path(base_name(fn1)) << " Locked on " << currentDate;
  outputFile << ";------------------------------------------------------------------------------";
  lock_code = '';
  k = (rand() % 21) + 20;
  for (i = 1; i <= k; i++){
    lock_code = lock_code + char((rand() % 32) + 65);
  }
  outputFile << "#LOCK" << locktype << " " << lock_code;
  //decode lock code
  for (i = 1; 1 <= lock_code.length(); i++){
    lock_code = char(int(lock_code[i])-65);
  }
  cout << "Encoding " << fn1 << "...";
  
  //encode robot
  s = btrim(s);
  if (length(s) > 0){
    write_line('', ucase(s));
  }
  while (!(inputFile.eof()){
    //read line
    inputFile >> s1;
    s = '';
    s1 = btrim(ucase(s1));
    //write line
    write_line(s, s1);
  }
  cout << "Done. Use LOCK Format #" << locktype << "." << endl;
  cout << "Only ATR2 v.2.08 or later can decode." << endl;
  cout << "LOCKed robot saved as \"" << fn2 << "\" "; 
  inputFile.close();
  outputFile.close();       

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
        if (s1[i] == ';'){
           k = i;
        }
    }
    if (k > 0){
       s1 = lstr(s1, k-1);
    }
  }
  s2 = '';
  for (i = 1; i < s1.length(); i++){
      if (s1[i] != (' ' || char(8) || char(9) || char(10) || ',')){
         s2 = s2 + s1[i];
      }
      else{
        if (s2 != ''){
           s = s + s2 + '';
           s2 = '';
        }
      }
  }
  if (s2 != ''){
     s = s + s2;
  }
  return s;
}

void write_line(string s, string s1) //Ported by Andrew Delia and Joseph Marji
{
  s = prepare(s,s1);
  if(s.length() > 0)
  {
    s = encode(s);
    outputFile << s;
  }
}
