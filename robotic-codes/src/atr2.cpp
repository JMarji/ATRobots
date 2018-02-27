#include <iostream>
#include <cstdlib>
#include "atrlib.hpp"
#include "guilib.hpp"
#include "termlib.hpp"
#include "errorloging.hpp"

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
void init();
void main_func();
void shutdown();

int main(int argc, char *argv[])
{
  int errors = 0;
  init();
  main_func();
  shutdown();
  return(errors);
}

void init()
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
  missile_rec missile_object

  for (i = 0; i <= max_missiles; i++)
  {
    //class missle_rec in robclass.cpp
    missile_object.set_a(0);
    missile_object.set_source(-1);
    missile_object.set_x(0);
    missile_object.set_y(0);
    missile_object.set_lx(0);
    missile_object.set_ly(0);
    missile_object.set_mult(1);
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
  delete_compile_report

}

void main_func()
{

}

void shutdown()
{

}
