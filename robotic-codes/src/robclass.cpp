/*rough skelton for the PAS code starting at line 131 in ATR2.PAS the type
/statement
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "termlib.hpp"

#define max_robot_lines 8
#define max_ram 1023
#define max_mines 63

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
     ty[(max_robot_lines - 1)], lty[(max_robot_lines - 1)], ram[max_ram + 1]; //max_ram might be declared as max rad by mistake !!!

    double x,y,lx,ly,xv,yv,speed,shotstrength,damageadj,speedadj,meters;

    config_rec config; // robclass::config_rec ?? // line 158 in ATR2.PAS not sure how this would
    //good question to ask Dr.Confer
    // code = new prog_type;
    //line 159 in ATR2.PAS should we make a char array or a string type?
    string name, fn;
    vector<mine_rec> mine;
   //errorlog how should we implemnt the text data type
   //errorlog how should we implemnt the text data type

  public:
    prog_type code;
    void setWins(long x)
    {
      wins = x;
    }
    void set_trials(long x)
    {
      trials = x;
    }
    void set_kills(long x)
    {
      kills = x;
    }
    void set_deaths(long x)
    {
      deaths = x;
    }
    void set_shots_fired(long x)
    {
      shots_fired = x;
    }
    void set_match_shots(long x)
    {
      match_shots = x;
    }
    void set_hits(long x)
    {
      hits = x;
    }
    long get_hits()
    {
      return hits;
    }
    void set_damage_total(long x)
    {
      damage_total = x;
    }
    void set_cycles_lived(long x)
    {
      cycles_lived = x;
    }
    void set_plen(int x)
    {
      plen = x;
    }
    void set_max_time(int x)
    {
      max_time = x;
    }
    void set_name(string x)
    {
      name = x;
    }
    void set_fn(string x)
    {
      fn = x;
    }
    void setSpeed(double x)
    {
      speed = x;
    }
    void setArc_count(int x)
    {
      arc_count = x;
    }
    void set_sonar_count(int x)
    {
      sonar_count = x;
    }
    void set_robot_time_limit(int x)
    {
      robot_time_limit = x;
    }
    void set_armor(int x)
    {
      armor = x;
    }
    void set_ram(int c, int x)
    {
      ram[c] = x;
    }
    void set_config_scanner(int x)
    {
      config.scanner = x;
    }
    void set_config_weapon(int x)
    {
      config.weapon = x;
    }
    void set_config_armor(int x)
    {
      config.armor = x;
    }
    void set_config_engine(int x)
    {
      config.engine = x;
    }
    void set_config_heatsinks(int x)
    {
      config.heatsinks = x;
    }
    void set_config_shield(int x)
    {
      config.shield = x;
    }
    void set_config_mines(int x)
    {
      config.mines = x;
    }
    int get_armor()
    {
      return armor;
    }
    void add_mine()
    {
      if (mine.size() < max_mines + 1)
      {
        mine_rec newMine;
        mine.push_back(newMine);
      }
      else
      {
        cout << "Too many mines";
      }
    }
    void set_mines(int x)
    {
      mines = x;
    }
    mine_rec get_mine(int index)
    {
      return mine[index];
    }
};
