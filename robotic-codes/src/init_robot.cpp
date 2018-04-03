#include "robclass.cpp"

using namespace std;

robot_rec robot[16];

int main(void)
{
  for (int i = 0; i <= 15; i++)
  {
    init_robot(i);
  }
}
void init_robot (int n)
{
  int i, j, k, l;

  robot[n].setWins(0);
  robot[n].setTrials(0);
  robot[n].setKills(0);
  robot[n].setDeaths(0);
  robot[n].setShots_fired(0);
  robot[n].setMatch_shots(0);
  robot[n].setHits(0);
  robot[n].setDamage_total(0);
  robot[n].setCycles_lived(0);
  robot[n].setError_count(0);
  robot[n].setPlen(0);
  robot[n].setMax_time(0);
  robot[n].setName(" ");
  robot[n].setFn(" ");
  robot[n].setSpeed(0);
  robot[n].setArc_count(0);
  robot[n].setSonar_count(0);
  robot[n].setRobot_time_limit(0);
  robot[n].setScanRange(1500);
  robot[n].setShotStrength(1);
  robot[n].setDamageAdj(1);
  robot[n].setSpeedAdj(1);
  robot[n].setMines(0);
  robot[n].setConfig_scanner(5);
}
