#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <cstdint>
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

string parsetype[max_op];

robot_rec *robot_ptr;

int main(int argc, char *argv[]){
  int errors = 0;
  init();
  main_func();
  shutdown();
  return(errors);
}
