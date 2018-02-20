/* this is a port of ATR2FUNC.PAS*/
/* TODO:
    String lstr(String, int)
*/
namespace atrlib {
  class atrlib{
  public:
    string lstr(string s1, int l);
    string ucase(string s);
    string btrim(string s1);
    char hexnum(byte num);
    string hexb(byte num);
    string hex(uint num);
    float valuer(string i);
    long int value(string i);
    string cstrr(float i);
    string cstr(long int i);
    string zero_pad(long int n, long int l);
    string zero_pads(string s, long int l);
    string addfront(string b, int l);
    string addrear(string b, int l);
    string lcase(string s);
    string space(byte i);
    string repchar(char c, byte i);
    string ltrim(string s1);
    string rtrim(string s1);
    string rstr(string s1; int l);
    int rol(int n, int k);
    int ror(int n, int k);
    int sal(int n, int k);
    int sar(int n, int k);
    int robot_color(int n);
    int hex2int(string s);
    int str2int(string s);
    float distance(float x1, float y1, float x2, float y2);
    float find_angle(float xx, float yy, float tx, float ty);
    int find_anglei(float xx, float yy, float tx, float ty);
    string bin(int n);
    string decimal(int num, int length);
  }
}
