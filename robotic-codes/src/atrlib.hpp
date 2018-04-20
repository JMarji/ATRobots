#include <string>
/* this is a port of ATR2FUNC.PAS*/
/* TODO:
    String lstr(String, int)
*/
using namespace std;
namespace atrlib {
    int customArray(int higher, int lower);
    string lstr(string s1, int l);
    string ucase(string s);
    string btrim(string s1);
    char hexnum(unsigned char num);
    string hexb(unsigned char num);
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
    string space(unsigned char i);
    string repchar(char c, unsigned char i);
    string ltrim(string s1);
    string rtrim(string s1);
    string rstr(string s1, int l);
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
    void coltextxy(int x, int y, string s, unsigned char c);
    void flushkey();
    void calibrate_timing();
    void time_delay(int n); //n=milliseconds
    void check_registration();
    void viewport(int x1, int y1, int x2, int y2);
    void main_viewport();
    void make_tables();
    double radians_to_degrees(double radian);
    void box(int x1, int y1, int x2, int y2);
    void hole(int x1, int y1, int x2, int y2);
    void chirp();
    void click();
}
