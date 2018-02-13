#include <iostream>

using namespace std;

#define progname "AT-Robots"
#define version "2.10"
#define cnotice1 "Copyright 1997 ''99, Ed T. Toton III"
#define cnotice2 "All Rights Reserved."
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
#define mine_blast 35 //start here
