#include "guilib.hpp"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

namespace guilib
{
  void viewport(int x1, int y1, int x2, int y2)
  {
    if (!graphix)
      exit;
  }
  void main_viewport()
  {

  }
  void textxy(int x, int y, string s)
  {
    // draw text on top of a graphical box
    setfillstyle(1,0);
    bar(x,y,x+s.length()*8, y+7);
    outtextxy(x,y,s);
  }
  void coltextxy(int x, int y, string s, byte c)
  {
      textxy(x,y,s);
  }

}
