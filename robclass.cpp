/*rough skelton for the PAS code starting at line 131 in ATR2.PAS the type
/statement
*/

#include <iostream>
#include <string>
using namespace std;

class op_rec
{
  private:
    int op[max_op];

  public:

}

class progtype
{
  private:
    prog_type[max_code] = new op_rec;

  public:
}

class config_rec
{
  private:
    int scanner, weapon, armor, engine, heatsinks, shield, mines;
  public:
}

class mine_rec
{
  private:
    double x, y;
    int detect, yield;
    bool detonate;

  public:

}

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

    config = new config_rec; // robclass::config_rec ?? // line 158 in ATR2.PAS not sure how this would
    //good question to ask Dr.Confer
    code = new prog_type;
    //line 159 in ATR2.PAS should we make a char array or a string type?
   string name, fn;
   mine[max_mines] = new mine_rec;
   //errorlog how should we implemnt the text data type

  public:

}

class missile_rec
{
  private:
    double x,y,lx,ly,mult,mspd;
    int source,a,hd,rad,lrad,max_rad;

  private:

}
