#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <SDL.h>
#include<SDL_net.h>
#include<string>
#include<iostream>
#include<Windows.h>

class TCP_Connection
{
public:
	bool Initialize();
	bool OpenSocket();
	void C_O_Socket();
	bool Send(const std::string& message);
	bool Receive(std::string& message);
	void CloseSocket();
	void ShutDown();
private:
	IPaddress m_IP;
	TCPsocket m_socket;
	std::string sendMessage;
	IPaddress ip;
	TCPsocket listenSocket = nullptr;
	TCPsocket clientSocket = nullptr;
	const int BUFFER_SIZE = 2000;
};

#endif !TCP_CONNECTION_H