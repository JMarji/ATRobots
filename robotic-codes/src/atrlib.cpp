#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "atrlib.hpp"

#define _USE_MATH_DEFINES
#define byte uint8_t
#define word uint16_t
using namespace std;

namespace atrlib {
  double sint[256], cost[256];
  long int delay_per_sec;
  bool registered, graphix, sound_on;
  string reg_name;
  word reg_num;


  string atrlib::lstr(string s1, int l){
    if (s1.length() <= 1){
      return s1;
    }
    else
      return s1.substr(1,l);
  }
  int customArray (int higher, int lower)
  {
    return (higher - lower);
  }
  string ucase(string s)
  {
    int i;
    if (s.length() >= 1)
    {
      for (i = 0; i <= s.length(); i++)
      {
        s[i] = toupper(s[i]);
      }
    }
    return s;
  }
  string btrim(string s1)
  {
    return ltrim(rtrim(s1));
  }
  char hexnum(byte num)
  {
    if (num > 9)
    {
      switch (num)
      {
        case "10":
          return "A";
          break;
        case "11":
          return "B";
          break;
        case "12":
          return "C";
          break;
        case "13":
          return "D";
          break;
        case "14":
          return "E";
          break;
        case "15":
          return "F";
          break;
        else
          return "X";
      }
    }
  else
  {
    return (String)num;
  }

  }
  string hexb(byte num)
  {
    return hexnum(num >> 4) + hexnum(num && 15);
  }
  string hex(word num)
  {
    return hexb(num >> 8) + hexb(num && 255);
  }
  float valuer(string i)
  {
    float s;
    int n;
    val(i,s,n);
    if (n>0)
      s=0;
    return s;
  }
  long int value(string i)
  {
    long int s;
    int n;
    val(i,s,n);
    if (n>0)
      s=0;
    return s;
  }
  string cstrr(double i)
  {
    string s1[255];
    s1 = to_string(i);
    return s1;
  }
  string cstr(long int i)
  {
    string s1[255];
    s1 = to_string(i);
    return s1;
  }
  string zero_pad(long int n, long int l)
  {
    string s;
    s = cstr(n);
    while (s.length() < l)
    {
      s = "0" + s;
    }
    return s;
  }
  string zero_pads(string s, long int l)
  {
    string s1;
    s1 = s;
    while (s1.length() < l)
    {
      s1 = "0" + s1;
    }
    return s1;
  }
  string addfront(string b, int l)
  {
    while (b.length() < l)
    {
      b = " "+b;
    }
    return b;
  }
  string addrear(string b, int l)
  {
    while (b.length() < l)
    {
      b = b+" ";
    }
    return b;
  }
  string lcase(string s)
  {
    int i;
    if (s.length() >= 1)
    {
      for (i = 0; i <= s.length(); i++)
      {
        s[i] = tolower(s[i]);
      }
    }
    return s;
  }
  string space(unsigned char i)
  {
    string s;
    int k;

    s = '';
    if (i > 0)
    {
      for (k = 0; k <= i; k++)
        s = s + '';
    }
    return s;
  }
  string repchar(char c, unsigned char i)
  {
    string s;
    int k;

    s = '';
    if (i > 0)
    {
      for (k = 1; k <= i; k++)
        s = s + c;
    }
    return s;
  }
  string ltrim(string s1)
  {
    int i;
    while ((s1.length()>0)&&(s1.substr(0,1)=" ")||(s1.substr(0,1)=#8)||(s1.substr(0,1)=#9))
    {
      s1 = s1.substr(2,s1.length()-1)
    }
    return s1;
  }
  string rtrim(string s1)
  {
    int i;
    while ((s1.length()>0) && (s1.substr(s1.length(),1)=' ') || (s1.substr(s1.length(),1)=#8)||(s1.substr(s1.length(),1)=#9))
    {
      s1 = s1.substr(1,s1.length()-1);
    }
    return s1;
  }
  string rstr(string s1, int l)
  {
    if (s1.length()<= l)
      return s1;
    else
      return s1.substr(s1.length()-l+1, l);
  }
  int rol(int n, int k){
    return ;
  }
  int ror(int n, int k){
    return ;
  }
  int sal(int n, int k){
    return ;
  }
  int sar(int n, int k){
    return ;
  }
  int robot_color(int n)
  {
    int k;
    k = 7;
    switch (n % 14)
    {
      case "0": k = 10;
        break;
      case "1": k = 12;
        break;
      case "2": k = 9;
        break;
      case "3": k = 11;
        break;
      case "4": k = 13;
        break;
      case "5": k = 14;
        break;
      case "6": k = 7;
        break;
      case "7": k = 6;
        break;
      case "8": k = 2;
        break;
      case "9": k = 4;
        break;
      case "10": k = 1;
        break;
      case "11": k = 3;
        break;
      case "12": k = 5;
        break;
      else
        k = 15;
    }
    return k;
  }
  int hex2int(string s)
  {
    word w;
    int i, j;
    i = 0;
    w = 0;
    while (i < s.length())
    {
      switch (s[i])
      {
        case "0": w = (w << 4) || 0x0;
                  break;
        case "1": w = (w << 4) || 0x1;
                  break;
        case "2": w = (w << 4) || 0x2;
                  break;
        case "3": w = (w << 4) || 0x3;
                  break;
        case "4": w = (w << 4) || 0x4;
                  break;
        case "5": w = (w << 4) || 0x5;
                  break;
        case "6": w = (w << 4) || 0x6;
                  break;
        case "7": w = (w << 4) || 0x7;
                  break;
        case "8": w = (w << 4) || 0x8;
                  break;
        case "9": w = (w << 4) || 0x9;
                  break;
        case "A": w = (w << 4) || 0xA;
                  break;
        case "B": w = (w << 4) || 0xB;
                  break;
        case "C": w = (w << 4) || 0xC;
                  break;
        case "D": w = (w << 4) || 0xD;
                  break;
        case "E": w = (w << 4) || 0xE;
                  break;
        case "F": w = (w << 4) || 0xF;
                  break;
        else
             i = s.length();
      }
    }
    return w;
  }
  int str2int(string s)
  {
    long int i, j, k;
    bool neg;
    neg = false;
    s = btrim(ucase(s));
    if (s= "")
      k = 0;
    else
    {
      if (s[1]= "-")
      {
        neg = true;
        s = rstr(s, s.length()-1);
      }
    }
    k = 0;
    if (lstr(s,2)= "0X")
      k = hex2int(rstr(s,s.length()-2))
    else if (rstr(s,1)= "H")
      k = hex2int(lstr(s,s.length()-1))
    else
      k = value(s);
    if (neg = true)
      k = 0 - k;
    return k;
  }
  float distance(float x1, float y1, float x2, float y2){
    return ;
  }
  float find_angle(float xx, float yy, float tx, float ty){
    return ;
  }
  int find_anglei(float xx, float yy, float tx, float ty){
    return ;
  }
  string bin(int n)
  {
    int i;
    string bin_string;
    bin_string = "";
    for (i = 0; i <= 15; i++)
    {
      if ((n % 2) = 0)
      {
        bin_string = "0" + bin_string;
      }
      else
        bin_string = "1" + bin_string;
      n = n/2;
    }
    return bin_string;
  }
  string decimal(int num, int length)
  {

    return ;
  }
  void textxy(int x, int y, string s){
    // draw text on top of a graphical box
  }
  void coltextxy(int x, int y, string s, byte c){

  }
  void flushkey()
  {
    fflush(stdin); //this might affect portabliltiy
  }
  void readkey()
  {
    int c;
    c = getchar();
  }
  void calibrate_timing(){

  }
  void time_delay(int n){

  } //n=milliseconds
  void check_registration()
  {
    byte w;
    int i;
    ifstream inputFile;
    string s;
    registered = false;
    inputFile.open("ATR2.REG");
    if (inputFile.good())
    {
      getline(inputFile, reg_name);
      getline(inputFile, reg_num);
      inputFile.close();
      w = 0;
      s = btrim(ucase(reg_name));
      for (i = 0; i <= s.length(); i++)
         w = w + (int)s[i];

      w = w ^ 0x5AA5;
      if (w == reg_num)
         registered = true;
    }
  }
  void viewport(int x1, int y1, int x2, int y2){

  }
  void main_viewport(){

  }
  void make_tables()
  {
    int i, j, k;

    for (i = 0; i <= 255; i++)
    {
      sint[i] = radians_to_degrees(sin(((double)i/128)*M_PI));
      cost[i] = radians_to_degrees(cos(((double)i/128)*M_PI));
    }
  }

  double radians_to_degrees (double radian)
  {
    double degrees = radian * (180.0/M_PI);
    return degrees;
  }
  void box(int x1, int y1, int x2, int y2){

  }
  void hole(int x1, int y1, int x2, int y2){

  }
  void chirp(){

  }
  void click(){

  }
}
