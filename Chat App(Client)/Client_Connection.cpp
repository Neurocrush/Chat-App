#include "Client_Connection.h"

bool Client_Connection::Initialize()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL could not initialize" << std::endl;
    }
    if (SDLNet_Init() == -1)
    {
        std::cout << "SDLNet could not initialize" << std::endl;
    }

    if (SDLNet_ResolveHost(&ip, "192.168.1.85", 1234) == -1)
    {
        std::cout << "Error creating a server." << std::endl;
        system("pause");
        return 0;
    }
    return true;
}

bool Client_Connection::Open_Socket()
{
    Socket = SDLNet_TCP_Open(&ip);
    if (!Socket)
    {
        std::cout << "Error opening up socket for connection." << std::endl;
        system("pause");
        return false;
    }
    return true;
}

bool Client_Connection::Send(const std::string& message)
{
    int messageLength = message.length() + 1;
    if (SDLNet_TCP_Send(Socket, message.c_str(), messageLength) < messageLength)
    {
        std::cout << "Error sending the message" << std::endl;
        return false;
    }
    return true;
}

bool Client_Connection::Receive(std::string& message)
{
    char getmessage[2000] = { '\0' };
    //send message via open socket that we opened up above
    //if return value is less than length of message thn error occured
    if (SDLNet_TCP_Recv(Socket, getmessage, BUFFER_SIZE) <= 0)
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

void Client_Connection::CloseSocket()
{
    SDLNet_TCP_Close(Socket);
}

void Client_Connection::ShutDown()
{
    SDLNet_Quit;
    SDL_Quit;
}
