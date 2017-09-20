#pragma once

#include <string>
#include <libssh2.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

class Connection{
	private:
		std::string password;
		bool success;

	public:
		Connection();
};
