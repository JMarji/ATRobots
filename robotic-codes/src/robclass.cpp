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
     ty[(max_robot_lines - 1)], lty[(max_robot_lines - 1)], ram[max_ram]; //max_ram might be declared as max rad by mistake !!!

    double x,y,lx,ly,xv,yv,speed,shotstrength,damageadj,speedadj,meters;

    config_rec config; // robclass::config_rec ?? // line 158 in ATR2.PAS not sure how this would
    //good question to ask Dr.Confer
    prog_type code; // code = new prog_type;
    //line 159 in ATR2.PAS should we make a char array or a string type?
    string name, fn;
    vector<mine_rec> mine;
   //errorlog how should we implemnt the text data type

  public:
    void setWins(long x)
    {
      wins = x;
    }
    void setTrials(long x)
    {
      trials = x;
    }
    void setKills(long x)
    {
      kills = x;
    }
    void setDeaths(long x)
    {
      deaths = x;
    }
    void setShots_fired(long x)
    {
      shots_fired = x;
    }
    void setMatch_shots(long x)
    {
      match_shots = x;
    }
    void setHits(long x)
    {
      hits = x;
    }
    void setDamage_total(long x)
    {
      damage_total = x;
    }
    void setCycles_lived(long x)
    {
      cycles_lived = x;
    }
    void setPlen(int x)
    {
      plen = x;
    }
    void setMax_time(int x)
    {
      max_time = x;
    }
    void setName(string x)
    {
      name = x;
    }
    void setFn(string x)
    {
      fn = x;
    }
    void setSpeed (double x)
    {
      speed = x;
    }
    void setArc_count(int x)
    {
      arc_count = x;
    }
    void setSonar_count(int x)
    {
      sonar_count = x;
    }
    void setRobot_time_limit()
    void setArmor(int x)
    {
      armor = x;
    }
    int getArmor()
    {
      return armor;
    }
    void addMine()
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
    void setMines(int x)
    {
      mines = x;
    }
    mine_rec getMine(int index)
    {
      return mine[index];
    }
};
