#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <chrono>
#include <thread>


void error(const std::string message) {
	perror(message.c_str());
	exit(EXIT_FAILURE);
}

int main() {
	std::cout << "Server starting..." << std::endl;
	
	int sock = 0;
	uint16_t port = 8000;
	sockaddr_in server_addr;

	// create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) error("socket");

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
	int bind_result = bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (bind_result < 0) error("bind");

	// wait for client
	int client = 0;
	sockaddr_in client_addr;
	socklen_t client_len;

	std::cout << "Listening..." << std::endl;
	int listen_result = listen(sock, SOMAXCONN);
	if (listen_result != 0) error("listen");

	client = accept(sock, (struct sockaddr *)&client_addr, &client_len);

	// respond
	std::string response = "HTTP/1.1 200 OK\n\nHi aoeu\n";
	int write_result = write(client, response.c_str(), sizeof(char) * response.size());

	// done
	close(client);
	close(sock);
}
