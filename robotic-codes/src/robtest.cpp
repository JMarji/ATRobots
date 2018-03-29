#include <iostream>
#include "robclass.cpp"

using namespace std;

int main (void)
{
  robot_rec robot;
  robot.setArmor(4);
  cout << "Armor: "<< robot.getArmor() << endl;
  robot.addMine();
  mine_rec testMine = robot.getMine(0);
  testMine.x = 300;
  cout << "Mine x: "<< testMine.x << endl;


  return 0;
}
