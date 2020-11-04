#ifndef Client_Connection_H
#define Client_Connection_H

#include <SDL.h>
#include<SDL_net.h>
#include<string>
#include<iostream>
class Client_Connection
{
public:
	bool Initialize();
	bool Open_Socket();
	bool Send(const std::string& message);
	bool Receive(std::string& message);
	void CloseSocket();
	void ShutDown();
private:
	IPaddress m_IP;
	TCPsocket m_socket;
	std::string sendMessage;
	IPaddress ip;
	TCPsocket Socket = nullptr;
	const int BUFFER_SIZE = 2000;
};

#endif !Client_Connection_H