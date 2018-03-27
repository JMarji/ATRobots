#include <iostream>
#include <cstdlib>
#include "termlib.hpp"

#define max_op 3
#define max_code 1023

using namespace std;

namespace termlib{
  typedef struct
  {
    int op[max_op];
  }op_rec;

  typedef struct
  {
    op_rec oprec[max_code];
  }prog_type;
}
