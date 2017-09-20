#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

string getPassword()
{
	char val[10000];
	string out = getpass("Password: ");
	return out;
}


int main()
{
	
	return 0;
}
