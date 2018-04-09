#include <iostream> 
#include <string> 
#include "hello.h"
using namespace std; 

int main(void)
{
	cout<< "this is main"<< endl;
	string s1;
	s1 = "yo this is s1";
	cout << s1 << endl; 
	s1 = helloworld(s1);
	cout<< "yo this is s1 after helloworld()" << s1 << endl;
	return 0;
}
