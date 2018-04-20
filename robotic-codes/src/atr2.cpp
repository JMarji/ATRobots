#include <iostream>
#include <cstdlib>
#include "atrlib.hpp"
//#include "guilib.hpp"
#include "termlib.hpp"
#include "robclass.cpp"
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


robot_ptr robot[customArray(max_robots, -2)];
missile_rec missile[max_missiles];

FILE text;
//end of variable declartions that started at line 174 in ATR2-term.PAS

//string parsetype[max_op];

//robot_rec *robot_ptr;
void init(int argc);
void main_func();
void shutdown();
void delete_compile_report();
void write_compile_report();
void parse_param(string s);
void bout();
void init_bout();
string operand(int n, int m);
string mnemonic(int n, int m);
void reset_hardware(int n);
void reset_software(int n);
void init_robot(int n);


int main(int argc, char *argv[])
{
  int errors = 0;
  srand(time(NULL));
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
    robot[n] = robot[0];
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
void print_code(int n, int p)
{
  int i;
  cout << hex(p) << ": ";
  for (i = 0; i <= max_op; i++)
  {
    cout << zero_pad(robot[n].code[p].op[i], 5) << " ";
  }
  cout << " =  ";
  for (i = 0; i <= max_op; i++)
  {
    cout << hex(robot[n].code[p].op[i]) << "h ";
  }
  cout << endl << endl;
}
void parse1(int n, int p, parsetype s)
{
  int i, j, k, opcode, microcode;
  bool found, indirect;
  char * ss;

  for (i = 0; i <= max_op - 1; i++)
  {
    k = 0;
    found = false;
    opcode = 0;
    microcode = 0;
    s[i] = btrim(ucase(s[i]));
    indirect = false;

    if (s[i] == " ")
    {
      opcode = 0;
      microcode = 0;
      found = true;
    }
    if ((lstr(s[i], 1) == "[") && (rstr(s[i], 1) == "]"))
    {
      s[i] = s[i].substr(1, s[i].length() - 3);
      indirect = true;
    }
   /*
   Microcode:
      0 = instruction, number, constant
      1 = variable, memory access
      2 = :label
      3 = !label (unresolved)
      4 = !label (resolved)
     8h mask = inderect addressing (enclosed in [])
   */
    if ((!(found)) && (s[i][0] = "!"))
    {
      ss = s[i];
      ss = btrim(rstr(ss, ss.length() - 1));
      if (numlabels > 0)
      {
        for (j = 1; j <= numlabels; j++)
        {
          if (ss == labelname[j])
          {
            found = true;
            if (labelnum[j] >= 0)
            {
              opcode = labelnum[j];
              microcode = 4;
            }
            else
            {
              opcode = j;
              microcode = 3;
            }
          }
        }
      }
      if (!(found))
      {
        numlabels++;
        labelname[numlabels] = ss;
        labelnum[numlabels] = -1;
        opcode = numlabels;
        microcode = 3;
        found = true;
      }
    }
    if ((numvars > 0) && (!(found)))
    {
      for (j = 1; j <= numvars; j++)
      {
        if (s[i] == varname[j])
        {
          opcode = varlic[j];
          microcode = 1;
          found = true;
        }
      }
    }
    switch (s[i])
    {
      //Instructions
      case "NOP":
           opcode = 000;
           found = true;
           break;
      case "ADD":
           opcode = 001;
           found = true;
           break;
      case "SUB":
           opcode = 002;
           found = true;
           break;
      case "OR":
           opcode = 003;
           found = true;
           break;
      case "AND":
           opcode = 004;
           found = true;
           break;
      case "XOR":
           opcode = 005;
           found = true;
           break;
      case "NOT":
           opcdoe = 006;
           found = true;
           break;
      case "MPY":
           opcode = 007;
           found = true;
           break;
      case "DIV":
           opcode = 008;
           found = true;
           break;
      case "MOD":
           opcode = 009;
           found = true;
           break;
      case "RET":
           opcode = 010;
           found = true;
           break;
      case "RETURN":
           opcode = 010;
           found = true;
           break;
      case "GSB":
           opcode = 011;
           found = true;
           break;
      case "GOSUB":
           opcode = 011;
           found = true;
           break;
      case "CALL":
           opcode = 011;
           found = true;
           break;
      case "JMP":
           opcode = 012;
           found = true;
           break;
      case "JUMP":
           opcode = 012;
           found = true;
           break;
      case "GOTO":
           opcode = 012;
           found = true;
           break;
      case "JLS":
           opcode = 012;
           found = true;
           break;
      case "JB":
           opcode = 013;
           found = true;
           break;
      case "JGR":
           opcode = 014;
           found = true;
           break;
      case "JA":
           opcode = 014;
           found = true;
           break;
      case "JNE":
           opcode = 015;
           found = true;
           break;
      case "JEQ":
           opcode = 016;
           found = true;
           break;
      case "JE":
           opcode = 016;
           found = true;
           break;
      case "XCHG":
           opcode = 017;
           found = true;
           break;
      case "SWAP":
           opcode = 017;
           found = true;
           break;
      case "DO":
           opcode = 018;
           found = true;
           break;
      case "LOOP":
           opcode = 019;
           found = true;
           break;
      case "CMP":
           opcode = 020;
           found = true;
           break;
      case "TEST":
           opcode = 021;
           found = true;
           break;
      case "SET":
           opcode = 022;
           found = true;
           break;
      case "MOV":
           opcode = 022;
           found = true;
           break;
      case "LOC":
           opcode = 023;
           found = true;
           break;
      case "ADDR":
           opcode = 023;
           found = true;
           break;
      case "GET":
           opcode = 024;
           found = true;
           break;
      case "PUT":
           opcode = 025;
           found = true;
           break;
      case "INT":
           opcode = 026;
           found = true;
           break;
      case "IPO":
           opcode = 027;
           found = true;
           break;
      case "IN":
           opcode = 027;
           found = true;
           break;
      case "OPO":
           opcode = 028;
           found = true;
           break;
      case "OUT":
           opcode = 028;
           found = true;
           break;
      case "DEL":
           opcode = 029;
           found = true;
           break;
      case "DELAY":
           opcode = 029;
           found = true;
           break;
      case "PUSH":
           opcode = 030;
           found = true;
           break;
      case "POP":
           opcode = 031;
           found = true;
           break;
      case "ERR":
           opcode = 032;
           found = true;
           break;
      case "ERROR":
           opcode = 032;
           found = true;
           break;
      case "INC":
           opcode = 033;
           found = true;
           break;
      case "DEC":
           opcode = 034;
           found = true;
           break;
      case "SHL":
           opcode = 035;
           found = true;
           break;
      case "SHR":
           opcode = 036;
           found = true;
           break;
      case "ROL":
           opcode = 037;
           found = true;
           break;
      case "ROR":
           opcode = 038;
           found = true;
           break;
      case "JZ":
           opcode = 039;
           found = true;
           break;
      case "JNZ":
           opcode = 040;
           found = true;
           break;
      case "JAE":
           opcode = 041;
           found = true;
           break;
      case "JGE":
           opcode = 041;
           found = true;
           break;
      case "JLE":
           opcode = 042;
           found = true;
           break;
      case "JBE":
           opcode = 042;
           found = true;
           break;
      case "SAL":
           opcode = 043;
           found = true;
           break;
      case "SAR":
           opcode = 044;
           found = true;
           break;
      case "NEG":
           opcode = 045;
           found = true;
           break;
      case "JTL":
           opcode = 046;
           found = true;
           break;

      //registers
      case "COLCNT":
           opcode = 008;
           microcode = 01;
           found = true;
           break;
      case "METERS":
           opcode = 009;
           microcode = 01;
           found = true;
           break;
      case "COMBASE":
           opcode = 010;
           microcode = 01;
           found = true;
           break;
      case "COMEND":
           opcode = 011;
           microcode = 01;
           found = true;
           break;
      case "FLAGS":
           opcode = 064;
           microcode = 01;
           found = true;
           break;
      case "AX":
           opcode = 065;
           microcode = 01;
           found = true;
           break;
      case "BX":
           opcode = 066;
           microcode = 01;
           found = true;
           break;
      case "CX":
           opcode = 067;
           microcode = 01;
           found = true;
           break;
      case "DX":
           opcode = 068;
           microcode = 01;
           found = true;
           break;
      case "EX":
           opcode = 069;
           microcode = 01;
           found = true;
           break;
      case "FX":
           opcode = 070;
           microcode = 01;
           found = true;
           break;
      case "SP":
           opcode = 071;
           microcode = 01;
           found = true;
           break;

      //constants
      case "MAXINT":
           opcode = 32767;
           microcode = 0;
           found = true;
           break;
      case "MININT":
           opcode = -32768;
           microcode = 0;
           found = true;
           break;
      case "P_SPEDOMETER":
           opcode = 01;
           microcode = 0;
           found = true;
           break;
      case "P_HEAT":
           opcode = 02;
           microcode = 0;
           found = true;
           break;
      case "P_COMPASS":
           opcode = 03;
           microcode = 0;
           found = true;
           break;
      case "P_TANGLE":
           opcode = 04;
           microcode = 0;
           found = true;
           break;
      case "P_TURRET_OFS":
           opcode = 04;
           microcode = 0;
           found = true;
           break;
      case "P_THREADING":
           opcode = 05;
           microcode = 0;
           found = true;
           break;
      case "P_TURRET_ABS":
           opcode = 05;
           microcode = 0;
           found = true;
           break;
      case "P_ARMOR":
           opcode = 06;
           microcode = 0;
           found = true;
           break;
      case "P_DAMAGE":
           opcode = 06;
           microcode = 0;
           found = true;
           break;
      case "P_SCAN":
           opcode = 07;
           microcode = 0;
           found = true;
           break;
      case "P_ACCURACY":
           opcode = 08;
           microcode = 0;
           found = true;
           break;
      case "P_RADAR":
           opcode = 09;
           microcode = 0;
           found = true;
           break;
      case "P_RANDOM":
           opcode = 10;
           microcode = 0;
           found = true;
           break;
      case "P_RAND":
           opcode = 10;
           microcode = 0;
           found = true;
           break;
      case "P_THROTTLE":
           opcode = 11;
           microcode = 0;
           found = true;
           break;
      case "P_TROTATE":
           opcode = 12;
           microcode = 0;
           found = true;
           break;
      case "P_OFS_TURRET":
           opcode = 12;
           microcode = 0;
           found = true;
           break;
      case "P_TAIM":
           opcode = 13;
           microcode = 0;
           found = true;
           break;
      case "P_ABS_TURRET":
           opcode = 13;
           microcode = 0;
           found = true;
           break;
      case "P_STEERING":
           opcode = 14;
           microcode = 0;
           found = true;
           break;
      case "P_WEAP"
           opcode = 15;
           microcode = 0;
           found = true;
           break;
      case "P_WEAPON":
           opcode = 15;
           microcode = 0;
           found = true;
           break;
      case "P_FIRE":
           opcode = 15;
           microcode = 0;
           found = true;
           break;
      case "P_SONAR":
           opcode = 16;
           microcode = 0;
           found = true;
           break;
      case "P_ARC":
           opcode = 17;
           microcode = 0;
           found = true;
           break;
      case "P_SCANARC":
           opcode = 17;
           microcode = 0;
           found = true;
           break;
      case "P_OVERBURN":
           opcode = 18;
           microcode = 0;
           found = true;
           break;
      case "P_TRANSPONDER":
           opcode = 19;
           microcode = 0;
           found = true;
           break;
      case "P_SHUTDOWN":
           opcode = 20;
           microcode = 0;
           found = true;
           break;
      case "P_CHANNEL":
           opcode = 21;
           microcode = 0;
           found = true;
           break;
      case "P_MINELAYER":
           opcode = 22;
           microcode = 0;
           found = true;
           break;
      case "P_MINETRIGGER":
           opcode = 23;
           microcode = 0;
           found = true;
           break;
      case "P_SHIELD":
           opcode = 24;
           microcode = 0;
           found = true;
           break;
      case "P_SHIELDS":
           opcode = 24;
           microcode = 0;
           found = true;
           break;
      case "I_DESTRUCT":
           opcode = 00;
           microcode = 0;
           found = true;
           break;
      case "I_RESET":
           opcode = 01;
           microcode = 0;
           found = true;
           break;
      case "I_LOCATE":
           opcode = 02;
           microcode = 0;
           found = true;
           break;
      case "I_KEEPSHIFT":
           opcode = 03;
           microcode = 0;
           found = true;
           break;
      case "I_OVERBURN":
           opcode = 04;
           microcode = 0;
           found = true;
           break;
      case "I_ID":
           opcode = 05;
           microcode = 0;
           found = true;
           break;
      case "I_TIMER":
           opcode = 06;
           microcode = 0;
           found = true;
           break;
      case "I_ANGLE":
           opcode = 07;
           microcode = 0;
           found = true;
           break;
      case "I_TID":
           opcode = 08;
           microcode = 0;
           found = true;
           break;
      case "I_TARGETID":
           opcode = 08;
           microcode = 0;
           found = true;
           break;
      case "I_TINFO":
           opcode = 09;
           microcode = 0;
           found = true;
           break;
      case "I_TARGETINFO":
           opcode = 09;
           microcode = 0;
           found = true;
           break;
      case "I_GINFO":
           opcode = 10;
           microcode = 0;
           found = true;
           break;
      case "I_GAMEINFO":
           opcode = 10;
           microcode = 0;
           found = true;
           break;
      case "I_RINFO":
           opcode = 11;
           microcode = 0;
           found = true;
           break;
      case "I_ROBOTINFO":
           opcode = 11;
           microcode = 0;
           found = true;
           break;
      case "I_COLLISIONS":
           opcode = 12;
           microcode = 0;
           found = true;
           break;
      case "I_RESETCOLCNT":
           opcode = 13;
           microcode = 0;
           found = true;
           break;
      case "I_TRANSMIT":
           opcode = 14;
           microcode = 0;
           found = true;
           break;
      case "I_RECEIVE":
           opcode = 15;
           microcode = 0;
           found = true;
           break;
      case "I_DATAREADY":
           opcode = 16;
           microcode = 0;
           found = true;
           break;
      case "I_CLEARCOM":
           opcode = 17;
           microcode = 0;
           found = true;
           break;
      case "I_KILLS":
           opcode = 18;
           microcode = 0;
           found = true;
           break;
      case "I_DEATHS":
           opcode = 18;
           microcode = 0;
           found = true;
           break;
      case "I_CLEARMETERS":
           opcode = 19;
           microcode = 0;
           found = true;
           break;

    }
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
  bout_over=false;
  if(step_mode == 0)
  {
    step_loop = false;
  }
  else
  {
    step_loop = true;
  }
  step_count = -1;
  // if graphix line 2793 in atr2-term.pas

  do
  {
    game_cycle++;
    for(i=0; i <= num_robots; i++)
    {
      if(robot[i].get_armor() > 0)
      {
        do_robot(i);
      }
    }
    for(i=0; i <= max_missiles; i++)
    {
      if( missile[i].a > 0)
      {
        do_missile(i);
      }
    }
    for(i=0; i<= num_robots; i++)
    {
      for(k=0; k <= max_mines; k++)
      {
        if(robot[i].)
      }
    }
  }


}

void init_bout();
{
  int i,j,k;

  game_cycle = 0;
  for(i=0; i <= max_missiles; i++)
  {
    //class missle_rec in robclass.cpp
    missile[i].a = 0;
    missile[i].source = -1;
    missile[i].x = 0;
    missile[i].y = 0;
    missile[i].lx = 0;
    missile[i].ly = 0;
    missile[i].mult = 1;
  }
  for(i=0; i <= num_robots; i++)
  {
    robot[i].set_mem_watch(128);
    reset_hardware(i);
    reset_software(i);
    // if not graphix block in pas code
  }
}
void init_robot(int n)
{
  int i, j, k, l;

  robot[i].set_wins(0);
  robot[i].set_trials(0);
  robot[i].set_kills(0);
  robot[i].set_deaths(0);
  robot[i].set_shots_fired(0);
  robot[i].set_match_shots(0);
  robot[i].set_hits(0);
  robot[i].set_damage_total(0);
  robot[i].set_cycles_lived(0);
  robot[i].set_error_count(0);
  robot[i].set_plen(0);
  robot[i].set_max_time(0);
  robot[i].set_name(" ");
  robot[i].set_fn(" ");
  robot[i].set_speed(0);
  robot[i].set_arc_count(0);
  robot[i].set_sonar_count(0);
  robot[i].set_robot_time_limit(0);
  robot[i].set_scanrange(1500);
  robot[i].set_shotstrength(1);
  robot[i].set_damageadj(1);
  robot[i].set_speedadj(1);
  robot[i].set_mines(0);
  robot[i].set_config_scanner(5);
}
// have to come up with a consences on syntax
void reset_hardware(int n)
{
  int i;
  double d, dd;

  for(i=0; i<= max_robot_lines; i++)
  {
    robot[n].ltx[i] = 0;
    robot[n].tx[i] = 0;
    robot[n].lty[i] = 0;
    robot[n].ty[i] = 0;
  }
  do // do while == repeat until
  {
    robot[n].x =rand() % 1000;
    robot[n].y = rand() % 1000;
    dd=1000;
    for(i=0; i <= num_robots; i++)
    {
      d=distance(robot[n].x,robot[n].y,robot[n].x,robot[n].y);
      if(robot[n].armor > 0) && (i != n) && (d < dd)
      {
        dd=d;
      }
    }
  }while(dd>32);

  for(i=0; i<=max_mines; i++)
  {
    mine[i].x=-1;
    mine[i].y=-1;
    mine[i].yield=0;
    mine[i].detect=0;
    mine[i].detonate = false;
  }
  robot[n].set_lx(-1);
  robot[n].set_ly(-1);
  robot[n].set_hd(rand() % 256);
  robot[n].set_shift(0);
  robot[n].set_lhd(robot[n].get_hd() + 1);
  robot[n].set_lshift(robot[n].get_shift() + 1);
  robot[n].set_spd(0);
  robot[n].set_speed(0);
  robot[n].set_cooling(false);
  robot[n].set_armor(100);
  robot[n].set_larmor(0);
  robot[n].set_heat(0);
  robot[n].set_lheat(1);
  robot[n].set_match_shots(0);
  robot[n].set_won(false);
  robot[n].set_last_damage(0);
  robot[n].set_last_hit(0);
  robot[n].set_transponder(n+1);
  robot[n].set_meters(0);
  robot[n].set_shutdown(400);
  robot[n].set_shields_up(false);
  robot[n].set_channel(robot[n].get_transponder());
  robot[n].set_startkills(robot[n].get_kills());
  robot_config(n);
}
void reset_software(int n)
{
  int i;
  for(i=0; i<=max_ram; i++)
  {
    robot[n].ram[i]=0;
    robot[n].ram[71]=768;
    robot[n].thd = hd;
    robot[n].tspd =0;
    robot[n].scanarc =8;
    robot[n].shift = 0;
    robot[n].err=0;
    robot[n].overburn=false;
    robot[n].keepshift=false;
    robot[n].ip = 0;
    robot[n].accuracy=0;
    robot[n].meters=0;
    robot[n].delay_left=0;
    robot[n].time_left=0;
    robot[n].shields_up=false;
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
