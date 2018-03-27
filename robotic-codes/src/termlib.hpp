#include <iostream>
#include <cstdlib>

#define max_op 3
#define max_code 1023

using namespace std;

typedef struct
{
  int op[max_op];
}op_rec;

typedef struct
{
  op_rec oprec[max_code];
}prog_type;

typedef struct
{
  int scanner, weapon, armor, engine, heatsinks, shield, mines;
}config_rec;
