
/*rough skelton for the PAS code starting at line 131 in ATR2.PAS the type
/statement
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "termlib.hpp"
#include "atrlib.hpp"

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

    int tx[customArray(max_robot_lines, 1)], ltx[customArray(max_robot_lines, 1)],
     ty[customArray(max_robot_lines, 1)], lty[customArray(max_robot_lines, 1)],
     ram[max_ram + 1]; //max_ram might be declared as max rad by mistake !!!

    double x,y,lx,ly,xv,yv,speed,shotstrength,damageadj,speedadj,meters;

    config_rec config; // robclass::config_rec ?? // line 158 in ATR2.PAS not sure how this would
    //good question to ask Dr.Confer
    // code = new prog_type;
    //line 159 in ATR2.PAS should we make a char array or a string type?
    string name, fn;
    vector<mine_rec> mine;
   //errorlog how should we implemnt the text data type

  public:
    prog_type code;
    void set_x(double x)
    {
      x = x;
    }
    void set_y(double x)
    {
      y = x;
    }
    void set_lx(double x)
    {
      lx = x;
    }
    void set_ly(double x)
    {
      ly =x;
    }
    void set_xv(double x)
    {
      xv = x;
    }
    void set_yv(double x)
    {
      yv =x;
    }
    //setters for arrays
    void add_tx(int x)
    {

    }
    void set_speed(double x)
    {
      speed=x;
    }
    void set_shotstrenght(double x)
    {
      shotstrength = x;
    }
    void set_damageadj(double x)
    {
      damageadj =x;
    }
    void set_speedadj(double x)
    {
      speedadj = x;
    }
    void set_meters(double x)
    {
      meters = x;
    }
    // end of setter for doubles joe marji
    // some int setter that havent been already made
    void set_mem_watch(int x)
    {
      mem_watch = x;
    }
    void set_hd(int x)
    {
      hd =x ;
    }
    void set_thd(int x)
    {
      thd = x;
    }
    void set_lhd(int x)
    {
      lhd = x;
    }
    void set_spd(int x)
    {
      spd = x;
    }
    void set_tspd(int x)
    {
      tspd =x ;
    }
    void set_larmor(int x)
    {
      larmor = x;
    }
    void set_heat(int x)
    {
      heat = x;
    }
    void set_lheat(int x)
    {
      lheat = x;
    }
    void set_ip(int x)
    {
      ip = x;
    }
    void set_scanarc(int x)
    {
      scanarc = x;
    }
    void set_accuracy(int x)
    {
      accuracy = x;
    }
    void set_shift(int x)
    {
      shift = x;
    }
    void set_err(int x)
    {
      err = x;
    }
    void set_delay_left(int x)
    {
      delay_left = x;
    }
    void set_time_left(int x)
    {
      time_left = x;
    }
    void set_channel(int x)
    {
      channel = x;
    }
    void set_lshift(int x)
    {
      lshift = x;
    }
    void set_shutdown(int x)
    {
      shutdown = x;
    }
    void set_startkills(long x)
    {
      startkills = x;
    }
    void set_scanrange(int x)
    {
      scanrange = x;
    }
    void set_last_damage(int x)
    {
      last_damage = x;
    }
    void set_last_hit(int x)
    {
      last_hit = x;
    }
    void set_transponder(int x)
    {
      transponder = x;
    }

    void set_wins(long x)
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
    } //Tst changce
    //Continuing to try and fix something
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
    void set_speed(double x)
    {
      speed = x;
    }
    void set_arc_count(int x)
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
