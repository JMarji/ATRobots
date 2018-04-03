void init_robot (int n)
{
  int i, j, k, l;

  robot[i].setWins(0);
  robot[i].setTrials(0);
  robot[i].setKills(0);
  robot[i].setDeaths(0);
  robot[i].setShots_fired(0);
  robot[i].setMatch_shots(0);
  robot[i].setHits(0);
  robot[i].setDamage_total(0);
  robot[i].setCycles_lived(0);
  robot[i].setError_count(0);
  robot[i].setPlen(0);
  robot[i].setMax_time(0);
  robot[i].setName(" ");
  robot[i].setFn(" ");
  robot[i].setSpeed(0);
  robot[i].setArc_count(0);
  robot[i].setSonar_count(0);
  robot[i].setRobot_time_limit(0);
  robot[i].setScanRange(1500);
  robot[i].setShotStrength(1);
  robot[i].setDamageAdj(1);
  robot[i].setSpeedAdj(1);
  robot[i].setMines(0);
  robot[i].setConfig_scanner(5);
}
