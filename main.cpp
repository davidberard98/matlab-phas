#include <iostream>
#include <unistd.h>
#include <string>
#include "Connection.h"

using namespace std;

string getPassword()
{
	string out = getpass("Password: ");
	return out;
}


int main()
{
	Connection c;
	string p = getPassword();
	c.connect("ssh.phas.ubc.ca", "dberard", p);

	
	return 0;
}
