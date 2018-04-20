
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
#define txca
#define tyca
#define ltxca
#define ltyca

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

    int txca, tyca, ltxca, ltyca;
    int ram[max_ram + 1]; //max_ram might be declared as max rad by mistake !!!
    int * tx;
    int * ty;
    int * ltx;
    int * lty;
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

    void init_customarrays()
    {
      txca = atrlib::customArray(max_robot_lines, 1);
      tyca = atrlib::customArray(max_robot_lines, 1);
      ltxca = atrlib::customArray(max_robot_lines, 1);
      ltyca = atrlib::customArray(max_robot_lines, 1);
    }
    void set_cutomarray()
    {
      tx = new int [txca];
      ty = new int [tyca];
      ltx = new int [ltxca];
      lty = new int [ltyca];
    }
    void set_x(double x)
    {
      x = x;
    }
    double get_x()
    {
      return x;
    }
    void set_y(double x)
    {
      y = x;
    }
    double get_y()
    {
      return y;
    }
    void set_lx(double x)
    {
      lx = x;
    }
    double get_lx()
    {
      return lx;
    }
    void set_ly(double x)
    {
      ly =x;
    }
    double get_ly()
    {
      return ly;
    }
    void set_xv(double x)
    {
      xv = x;
    }
    double get_xv()
    {
      return xv;
    }
    void set_yv(double x)
    {
      yv =x;
    }
    double set_yv()
    {
      return yv;
    }
    //setters for arrays
    void add_tx(int x)
    {

    }
    void set_speed(double x)
    {
      speed=x;
    }
    double get_speed()
    {
      return speed;
    }
    void set_shotstrength(double x)
    {
      shotstrength = x;
    }
    double get_shotstrength()
    {
      return shotstrength;
    }
    void set_damageadj(double x)
    {
      damageadj =x;
    }
    double get_damageadj()
    {
      return damageadj;
    }
    void set_speedadj(double x)
    {
      speedadj = x;
    }
    double get_speedadj()
    {
      return speedadj;
    }
    void set_meters(double x)
    {
      meters = x;
    }
    double get_meters()
    {
      return meters;
    }
    // end of setter for doubles joe marji
    // some int setter that havent been already made
    void set_mem_watch(int x)
    {
      mem_watch = x;
    }
    int get_mem_watch()
    {
      return mem_watch;
    }
    void set_hd(int x)
    {
      hd =x ;
    }
    int get_hd()
    {
      return hd;
    }
    void set_thd(int x)
    {
      thd = x;
    }
    int get_thd()
    {
      return thd;
    }
    void set_lhd(int x)
    {
      lhd = x;
    }
    int get_lhd()
    {
      return lhd;
    }
    void set_spd(int x)
    {
      spd = x;
    }
    int get_spd()
    {
      return spd;
    }
    void set_tspd(int x)
    {
      tspd =x ;
    }
    int get_tspd()
    {
      return tspd;
    }
    void set_larmor(int x)
    {
      larmor = x;
    }
    int get_larmor()
    {
      return larmor;
    }
    void set_heat(int x)
    {
      heat = x;
    }
    int get_heat()
    {
      return heat;
    }
    void set_lheat(int x)
    {
      lheat = x;
    }
    int get_lheat()
    {
      return lheat;
    }
    void set_ip(int x)
    {
      ip = x;
    }
    int get_ip()
    {
      return ip;
    }
    void set_scanarc(int x)
    {
      scanarc = x;
    }
    int get_scanarc()
    {
      return scanarc;
    }
    void set_accuracy(int x)
    {
      accuracy = x;
    }
    int get_accuracy()
    {
      return accuracy;
    }
    void set_shift(int x)
    {
      shift = x;
    }
    int get_shift()
    {
      return shift;
    }
    void set_err(int x)
    {
      err = x;
    }
    int get_err()
    {
      return err;
    }
    void set_delay_left(int x)
    {
      delay_left = x;
    }
    int get_delay_left()
    {
      return delay_left;
    }
    void set_time_left(int x)
    {
      time_left = x;
    }
    int get_time_left()
    {
      return time_left;
    }
    void set_channel(int x)
    {
      channel = x;
    }
    int get_channel()
    {
      return channel;
    }
    void set_lshift(int x)
    {
      lshift = x;
    }
    int get_lshift()
    {
      return lshift;
    }
    void set_shutdown(int x)
    {
      shutdown = x;
    }
    int get_shutdown()
    {
      return shutdown;
    }
    void set_startkills(long x)
    {
      startkills = x;
    }
    long get_startkills()
    {
      return startkills;
    }
    void set_scanrange(int x)
    {
      scanrange = x;
    }
    int get_scanrange()
    {
      return scanrange;
    }
    void set_last_damage(int x)
    {
      last_damage = x;
    }
    int get_last_damage()
    {
      return last_damage;
    }
    void set_last_hit(int x)
    {
      last_hit = x;
    }
    int get_last_hit()
    {
      return last_hit;
    }
    void set_transponder(int x)
    {
      transponder = x;
    }
    int get_transponder()
    {
      return transponder;
    }
    void set_wins(long x)
    {
      wins = x;
    }
    long get_wins()
    {
      return wins;
    }
    void set_trials(long x)
    {
      trials = x;
    }
    long get_trials()
    {
      return trials;
    }
    void set_kills(long x)
    {
      kills = x;
    }
    long get_kills()
    {
      return kills;
    } //Tst changce
    //Continuing to try and fix something
    void set_deaths(long x)
    {
      deaths = x;
    }
    long get_deaths()
    {
      return deaths;
    }
    void set_shots_fired(long x)
    {
      shots_fired = x;
    }
    long get_shots_fired()
    {
      return shots_fired()
    }
    void set_match_shots(long x)
    {
      match_shots = x;
    }
    long get_match_shots()
    {
      return match_shots;
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
    long get_damage_total()
    {
      return damage_total;
    }
    void set_cycles_lived(long x)
    {
      cycles_lived = x;
    }
    long get_cycles_lived()
    {
      return cycles_lived;
    }
    void set_plen(int x)
    {
      plen = x;
    }
    int get_plen()
    {
      return plen;
    }
    void set_max_time(int x)
    {
      max_time = x;
    }
    int get_max_time()
    {
      return max_time;
    }
    void set_name(string x)
    {
      name = x;
    }
    string get_name()
    {
      return name;
    }
    void set_fn(string x)
    {
      fn = x;
    }
    string get_fn()
    {
      return fn;
    }
    void set_arc_count(int x)
    {
      arc_count = x;
    }
    int get_arc_count()
    {
      return arc_count;
    }
    void set_sonar_count(int x)
    {
      sonar_count = x;
    }
    int get_sonar_count()
    {
      return sonar_count;
    }
    void set_robot_time_limit(int x)
    {
      robot_time_limit = x;
    }
    int get_robot_time_limit()
    {
      return robot_time_limit;
    }
    void set_armor(int x)
    {
      armor = x;
    }
    int get_armor()
    {
      return(armor);
    }
    void set_ram(int c, int x)
    {
      ram[c] = x;
    }
    int get_ram(int c)
    {
      return ram[c];
    }
    void set_config_scanner(int x)
    {
      config.scanner = x;
    }
    int get_config_scanner()
    {
      return config.scanner;
    }
    void set_config_weapon(int x)
    {
      config.weapon = x;
    }
    int get_config_weapon()
    {
      return config.weapon;
    }
    void set_config_armor(int x)
    {
      config.armor = x;
    }
    int get_config_armor()
    {
      return config.armor;
    }
    void set_config_engine(int x)
    {
      config.engine = x;
    }
    int get_config_engine()
    {
      return config.engine;
    }
    void set_config_heatsinks(int x)
    {
      config.heatsinks = x;
    }
    int get_config_heatsinks()
    {
      return config.heatsinks;
    }
    void set_config_shield(int x)
    {
      config.shield = x;
    }
    int get_config_shield()
    {
      return config.shield;
    }
    void set_config_mines(int x)
    {
      config.mines = x;
    }
    int get_config_mines()
    {
      return config.mines;
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
