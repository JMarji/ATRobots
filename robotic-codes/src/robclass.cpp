/*rough skelton for the PAS code starting at line 131 in ATR2.PAS the type
/statement
*/

#include <iostream>
#include <string>
#include <fstream>
#include "termlib.hpp"
using namespace std;

typedef struct
{
  double x, y;
  int detect, yield;
  bool detonate;
}mine_rec;

typedef struct
{
  double x, y, lx, ly, mult, mspd;
  int source, a, hd, rad, lrad, max_rad;
}missle_rec;

class robot_rec
{
  private:
    bool is_locked,shields_up,lshields,overburn,keepshift,cooling,won;
    int mem_watch,hd,thd,lhd,spd,tspd,armor,larmor,heat,lheat,ip,
     plen,scanarc,accuracy,shift,err,delay_left,robot_time_limit,
     max_time,time_left,lshift,arc_count,sonar_count,scanrange,
     last_damage,last_hit,transponder,shutdown,channel,
     lendarc,endarc,lstartarc,startarc,mines;

    long wins,trials,kills,deaths,startkills,shots_fired,match_shots,
    hits,damage_total,cycles_lived,error_count;

    int tx[(max_robot_lines - 1)], ltx[(max_robot_lines - 1)],
     ty[(max_robot_lines - 1)], lty[(max_robot_lines - 1)], ram[max_ram]; //max_ram might be declared as max rad by mistake !!!

    double x,y,lx,ly,xv,yv,speed,shotstrength,damageadj,speedadj,meters;

    struct config_rec config; // robclass::config_rec ?? // line 158 in ATR2.PAS not sure how this would
    //good question to ask Dr.Confer
    struct prog_type code; // code = new prog_type;
    //line 159 in ATR2.PAS should we make a char array or a string type?
    string name, fn;
    mine_rec mine[max_mines];
   //errorlog how should we implemnt the text data type
};
