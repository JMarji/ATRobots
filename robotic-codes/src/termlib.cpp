#include <iostream>
#include <cstdlib>
#include "termlib.hpp"

using namespace std;

namespace termlib
{

  typedef struct
  {
    string[max_var_len];
  } stringz; // struct made in order to make array of array of strings varname

int num_robots, numvars, numlabels, maxcode, lock_pos, lock_dat, game_delay,
time_slice, insanity, update_timer, max_gx, max_gy, stats_mode, kill_count,
report_type;

int varloc[(max_vars + 1)], labelnum[(max_labels + 1)];

stringz varname[(max_vars + 1)], labelname[(max_vars + 1)];

//flag for viewing debugger panel vs. robot stats
bool show_source, compile_only, old_shields, insane_missiles, debug_info, windoze,
no_gfx, logging_errors, timing, show_arcs, quit, report, show_cnotice;

bool bout_over;     //made global from procedure bout}
int step_mode;     //0=off, for (0<step_mode<=9) = #of game cycles per step}
int temp_mode;     //stores previous step_mode for return to step}
int step_count;    //step counter used as break flag}
bool step_loop;     //break flag for stepping}

long int matches, played, game_limit;

robot_ptr robot[(max_robots+2)];
missile_rec missile[max_missiles];

FILE text;

}
