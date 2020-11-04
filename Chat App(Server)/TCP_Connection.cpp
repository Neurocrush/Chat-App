#include "TCP_Connection.h"

bool TCP_Connection::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL could not initialize" << std::endl;
    }
    if (SDLNet_Init() == -1)
    {
        std::cout << "SDLNet could not initialize" << std::endl;
    }

    if (SDLNet_ResolveHost(&ip, nullptr, 1234) == -1)
    {
        std::cout << "Error creating a server." << std::endl;
        system("pause");
        return 0;
    }

    
	return true;
}

bool TCP_Connection::OpenSocket()
{
    listenSocket = SDLNet_TCP_Open(&ip);
	return true;
}

void TCP_Connection::C_O_Socket()  //close and open socket.
{
    if (!listenSocket)
    {
        std::cout << "Error opening up socket for connection." << std::endl;
        system("pause");
    }
    //special request to get HTML code from website
    std::cout << "Server waiting for clients to connect." << std::endl;

    while (!clientSocket)
    {
      clientSocket = SDLNet_TCP_Accept(listenSocket);
      std::cout << ".";
      SDL_Delay(1000);
    }

    SDLNet_TCP_Close(listenSocket);
}

bool TCP_Connection::Send(const std::string& message)
{
    int messageLength = message.length() + 1;
    if (SDLNet_TCP_Send(clientSocket, message.c_str(), messageLength) < messageLength)
    {
        std::cout << "Error sending the message" << std::endl;
        return false;
    }
    return true;
}

bool TCP_Connection::Receive(std::string& message)
{
    char getmessage[2000] = { '\0' };
    //send message via open socket that we opened up above
    //if return value is less than length of message thn error occured
    if (SDLNet_TCP_Recv(clientSocket, getmessage, BUFFER_SIZE) <= 0)
    {
        std::cout << "Error receiving the message" << std::endl;
        return false;
    }
    else
    {
         message = getmessage;
    }
	return true;
}

void TCP_Connection::CloseSocket()
{
    SDLNet_TCP_Close(clientSocket);
}

void TCP_Connection::ShutDown()
{
    //shut down the SDL/Connection
    SDLNet_Quit;
    SDL_Quit;
}
