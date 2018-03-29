#include <iostream>
#include <cstdlib>
#include "atrlib.hpp"
#include "guilib.hpp"
#include "termlib.hpp"
#include "errorloging.hpp"
#include <iostream>

#define byte uint8_t
#define word uint16_t
#define progname "Robotic-Codes"
#define version "2.10"
#define cnotice1 "Copyright 2018 - SUNY Polytechnic Institute"
#define cnotice2 "License: GPL V3"
#define main_filename "ATR2"
#define robot_ext "AT2"
#define locked_ext ".AT2"
#define config_ext ".ATS"
#define compile_ext ".CMP"
#define report_ext ".REP"
#define _T true
#define _F false
#define minint -32768
#define maxint 32787

//debugging/compiler
#define show_code "_F"
#define compile_by_line "_F"
#define max_var_len 16
#define debugging_compiler "_F"

//robots
#define max_robots 31
#define max_code 1023
#define max_op 3
#define max_stack 256
#define max_ram 1023
#define max_vars 256
#define max_labels 256
#define acceleration 4
#define turn_rate 8
#define max_vel 4
#define max_missiles 1023
#define missie_spd 32
#define hit_range 14
#define blast_radius 25
#define crash_range 8
#define max_sonar 250
#define com_queue 512
#define max_queue 255
#define max_config_points 12
#define max_mines 63
#define mine_blast 35

//simulator & graphics
#define screen_scale    =0.46;
#define screen_x        =5;
#define screen_y        =5;
#define robot_scale     =06;
#define default_delay   =20;
#define default_slice   =05;
#define mine_circle     =trunc(mine_blast*screen_scale)+1;
#define blast_circle    =trunc(blast_radius*screen_scale)+1;
#define mis_radius      =trunc(hit_range/2)+1;
#define max_robot_lines =8;
#define Gray50

using namespace std;

//global variable declorations starting form line 174 in ATR2-TERM.PAS
  typedef struct
  {
    string[max_var_len];
  } stringz; // struct made in order to make array of array of strings varname
  typedef struct
  {
    robot_rec *
  }robot_ptr; // this might work for robot pointer im not sure tho

  typedef struct
  {
    char[max_op][16];
  }parsetype;

int num_robots, numvars, numlabels, maxcode, lock_pos, lock_dat, game_delay,
time_slice, insanity, update_timer, max_gx, max_gy, stats_mode, kill_count,
report_type;

int varloc[(max_vars + 1)], labelnum[(max_labels + 1)];

stringz varname[(max_vars + 1)], labelname[(max_vars + 1)];

string lock_code;

long int game_limit, game_cycle, matches, played, executed;
//does long int have the neccesary amount of bits ? as it should ?


//flag for viewing debugger panel vs. robot stats
bool show_source, compile_only, old_shields, insane_missiles, debug_info, windoze,
no_gfx, logging_errors, timing, show_arcs, quit, report, show_cnotice;

bool bout_over;     //made global from procedure bout}
int step_mode;     //0=off, for (0<step_mode<=9) = #of game cycles per step}
int temp_mode;     //stores previous step_mode for return to step}
int step_count;    //step counter used as break flag}
bool step_loop;     //break flag for stepping}


robot_ptr robot[(max_robots+2)];
missile_rec missile[max_missiles];

FILE text;
//end of variable declartions that started at line 174 in ATR2-term.PAS

//string parsetype[max_op];

//robot_rec *robot_ptr;
void init(int argc);
void main_func();
void shutdown();
void delete_compile_report();
void parse_param(string s);
void bout();
void init_bout();
string operand(int n, int m);
string mnemonic(int n, int m);


int main(int argc, char *argv[])
{
  int errors = 0;
  init(argc);
  main_func();
  shutdown();
  return(errors);
}

void init(int argc)
{
  int i;

  if(debugging_compiler || compile_by_line || show_code)
  {
    cout << "!!! Warning !!! Compiler Debugging enabled !!!" << '\n';
    flushkey();
    readkey(); // should readkey return its value
    cout << "   " // cout << " return of readkey ? "
  }
  logging_errors = false;
  stats_mode = 0;
  insane_missles = false;
  insanity = 0;
  delay_per_sec = 0;
  windowze = true;
  graphix = false; //add graphix to guilib
  no_gfx = true; //possibly change to false for only command lines
  sound_on = true; //in ATR2FUNC.PAS
  timing = true;
  matches = 1;
  played = 0;
  old_shields = false;
  quit = false;
  compile_only = false;
  show_arcs = false;
  debug_info = false;
  show_cnotice = true;
  show_source = true;
  report = false;
  kill_count = 0;
  maxcode = max_code; // is max_code a constant?
  make_tables();
  num_robots = -1;
  game_limit = 100000;
  game_cycle = 0;
  game_delay = default_delay;
  time_slice = default_slice;
  // below lies an object of class missile_rec


  for (i = 0; i <= max_missiles; i++)
  {
    //class missle_rec in robclass.cpp
    missile[i].set_a(0);
    missile[i].set_source(-1);
    missile[i].set_x(0);
    missile[i].set_y(0);
    missile[i].set_lx(0);
    missile[i].set_ly(0);
    missile[i].set_mult(1);
  }
  registered = false;
  reg_name = 'Unregistered';    // all these vars are declared in atrlib.cpp
  reg_num = 0xFFFF;
  //check_registration();
  cout << endl;
  cout << progname << ' ' << version << ' ' << endl;
  cout << cnotice1 << endl << cnotice2 << endl;
  if(!(registered))
  {
    cout << 'Unregistered version' << endl;
  }
  else
  {
    cout << 'Registered to: ' << reg_name << endl;
  }
  cout << endl;
  delete_compile_report();
  if(argc > 0)
  {
    for(i=1; i <= argc; i++)
    {
      parse_param(btrim(ucase(p)))
    }
  }
  else
  {
    prog_error(5, "");
  }
  temp_mode = step_mode;
  if (logging_errors)
  {
    //always false
    int fake_var;
  }
  if (compile_only)
  {
    write_compile_report();
  }
  if (num_robots < 1)
  {
    prog_error(4, "");
  }
  if (!(no_gfx))
  {
    graph_mode(true);
  }
  if (matches > 100000)
  {
    matches = 100000;
  }
  if (matches < 1)
  {
    matches = 1;
  }
  if (game_delay > 1000)
  {
    game_delay = 1000;
  }
  if (time_slice > 100)
  {
    time_slice = 100;
  }
  if (time_slice < 1)
  {
    time_slice = 1;
  }
  if (game_limit > 100000)
  {
    game_limit = 100000;
  }
  if (maxcode < 1)
  {
    maxcode = 1;
  }
  if (maxcode > max_code)
  {
    maxcode = max_code;
  }
  for (i = num_robots + 1; i <= maxrobots + 2; i++)
  {
    robot[i] = robot[0];
  }
}

void main_func()
{
  int i,j,k,l,n,w;
  if ( matches > 0)
  {
    for(i=0; i<= matches; i++)
    {
      bout();
    }
  }
}

void shutdown()
{
  int i,j,k;
  if (show_cnotice)
  {
    cout << Progname, ' ',version, ' ' << endl;
    cout << cnotice1 << endl;
    cout << cnotice2 << endl;
    cout << cnotice3 << endl;
  }
  if (!registered)
  {
    cout << "Unregistered version";
  }
  else
  {
    cout << "Registered to: " << reg_name;
  }
  cout << " "
  if (logging_errors = true)
  {
    for (i = 0, i <= num_robots, i++)
    {
      cout << "Robot error-log created: " << base_name(fn) << ".ERR"
      outputFile.close();
    }
    return 0;
  }

}

void delete_compile_report()
{
  ifstream input_file;
  input_file.open((string)main_filename + (sting)compile_ext);
  if(input_file.good((string)main_filename + (sting)compile_ext));
  {
    remove((string)main_filename + (sting)compile_ext));
  }
}
void parse_param(string s)
{
  FILE f;
  string fn, s1;
  bool found;

  found = false;
  s = btrim(ucase(s));
  if(s.empty())
  {
    return;
  }
  if(s[0] == '#') // checking begining of string
  {

  }
}

void bout()
{
  int i,j,k;
  char c;
  long timer;
  int n; //loop count for mem_watch

  if(quit)
    return;

  played++; //inc is a function that does incremntation
  init_bout();
}

void init_bout();
{
  int i,j,k;

  game_cycle = 0;
  for(i=0; i <= max_missiles; i++)
  {
    //class missle_rec in robclass.cpp
    missile[i].x = 
  }
  for(i=0; i <= num_robots; i++)
  {

  }
}
string operand(int n, int m)
{
  string s;
  s = cstr(n);
  switch (m & 7)
  {
   case 1:
     s = "@" + s;
     break;
   case 2:
     s = ":" + s;
     break;
    case 3:
     s = "$" + s;
     break;
   case 4:
     s = "!" + s;
     break;
   else
     s = cstr(n);
 }
 if (m & 8>0)
    s = "[" + s + "]";
}
string mnemonic(int n, int m)
{
  string s;
  if (m == 0)
  {
    switch (n)
    {
      case 00:
        s = "NOP";
        break;
      case 01:
        s = "ADD";
        break;
      case 02:
        s = "SUB";
        break;
      case 03:
        s = "OR";
        break;
      case 04:
        s = "AND";
        break;
      case 05:
        s = "XOR";
        break;
      case 06:
        s = "NOT";
        break;
      case 07:
        s = "MPY";
        break;
      case 08:
        s = "DIV";
        break;
      case 09:
        s = "MOD";
        break;
      case 10:
        s = "RET";
        break;
      case 11:
        s = "CALL";
        break;
      case 12:
        s = "JMP";
        break;
      case 13:
        s = "JLS";
        break;
      case 14:
        s = "JGR";
        break;
      case 15:
        s = "JNE";
        break;
      case 16:
        s = "JE";
        break;
      case 17:
        s = "SWAP";
        break;
      case 18:
        s = "DO";
        break;
      case 19:
        s = "LOOP";
        break;
      case 20:
        s = "CMP";
        break;
      case 21:
        s = "TEST";
        break;
      case 22:
        s = "MOV";
        break;
      case 23:
        s = "LOC";
        break;
      case 24:
        s = "GET";
        break;
      case 25:
        s = "PUT";
        break;
      case 26:
        s = "INT";
        break;
      case 27:
        s = "IPO";
        break;
      case 28:
        s = "OPO";
        break;
      case 29:
        s = "DELAY";
        break;
      case 30:
        s = "PUSH";
        break;
      case 31:
        s = "POP";
        break;
      case 32:
        s = "ERR";
        break;
      case 33:
        s = "INC";
        break;
      case 34:
        s = "DEC";
        break;
      case 35:
        s = "SHL";
        break;
      case 36:
        s = "SHR";
        break;
      case 37:
        s = "ROL";
        break;
      case 38:
        s = "ROR";
        break;
      case 39:
        s = "JZ";
        break;
      case 40:
        s = "JNZ";
        break;
      case 41:
        s = "JGE";
        break;
      case 42:
        s = "JLE";
        break;
      case 43:
        s = "SAL";
        break;
      case 44:
        s = "SAR";
        break;
      case 45:
        s = "NEG";
        break;
      case 46:
        s = "JTL";
        break;
      else
        s = "XXX";
    }
  }
  s = operand(n,m);
  return s;
}
int max_shown()
{
  switch (stats_mode)
  {
    case 1:
      return 12;
    case 2:
      return 32;
    else
      return 6;
  }
}
