#include "Connection.h"
/**
 * https://www.libssh2.org/examples/ssh2.html
 */

Connection::Connection() {}

Connection::Connection(std::string host, std::string user, std::string password) {
	connect(host, user, password);

}

bool Connection::connect(std::string host, std::string user, std::string password) {
	/**
	 * Based on https://www.libssh2.org/examples/ssh2.html
	 */

	unsigned long hostaddr;
	int rc, sock, i, auth_pw = 0;
	struct sockaddr_in sin;
	const char *fingerprint;
	char *userauthlist;
	LIBSSH_SESSION *session;
	LIBSSH_CHANNEL *channel;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	sin.sin_family = AF_INET;
	sin.sin_port = htons(22);
	sin.sin_addr.s_addr = hostaddr;

	if(connect(sock, (struct sockaddress*)(&sin),
		sizeof((struct sockaddr_in)) != 0)
	{
		std::cerr << "Failed to connect \n" << std::endl;
		return false;
	}

	session = libssh2_session_init();
	
	if(libssh2_session_handshake(session, sock)) {
		std::cerr << "Failure establishing SSH connection" << std::endl;
	}

	fingerprint = libssh2_hostkey_hash(session, LIBSSH2_HOSTKEY_HASH_SHA1);

	std::cout << "Fingerprint: ";
	for(i=0;i<20;++i)
		printf("%02X", (unsigned char) fingerprint[i]);
	std::cout << std::endl;

}
