#include "termlib.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace termlib {

  void init() 
  {
    int i;

    if(debugging_compiler or compile_by_line or show_code)
    {
      cout << "!!! Warning !!! Compiler Debugging enabled !!!" << '\n';
      flushkey();
      readkey();
    }
  }

}
