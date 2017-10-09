#pragma once

#include <string>
#include <libssh2.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

/** Based on https://www.libssh2.org/examples/ssh2.html
 *
 */

class Connection{
	private:
		std::string password;
		bool success;

	public:
		Connection();
		Connection(std::string, std::string, std::string);
		bool connect(std::string host, std::string user, std::string password);
};
