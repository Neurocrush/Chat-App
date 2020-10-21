#include<iostream>
#include<string>
#include <SDL.h>
#include<SDL_net.h>

const int port = 1234;
const int BUFFER_SIZE = 2000;
//Struct to store the host address (IP) and port number.
IPaddress ip;

//socket to listen to incoming connections
TCPsocket socket = nullptr;


int main(int argc, char* argv[])

//=============================================
//initialization
//=============================================

{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL could not initialize" << std::endl;
    }
    if (SDLNet_Init() == -1)
    {
        std::cout << "SDLNet could not initialize" << std::endl;
    }

    //=============================================
    //Client Code
    //=============================================


    if (SDLNet_ResolveHost(&ip, "127.0.0.1", 1234) == -1)
    {
        std::cout << "Error creating a server." << std::endl;
        system("pause");
        return 0;
    }

    socket = SDLNet_TCP_Open(&ip);
    if (!socket)
    {
        std::cout << "Error opening the socket." << std::endl;
        system("pause");
        return 0;
    }

    std::cout << "Client Connected." << std::endl;
    system("pause");

    system("cls");
    std::cout << "WELCOME TO HELL!" << std::endl;

    //create a friendly message for the client

    char message [BUFFER_SIZE];
    //we ned length of message in order to send data
    //we add an extra space for the terminating null '\0'

    //receive message
    if (SDLNet_TCP_Recv(socket, message, BUFFER_SIZE) <= 0)
    {
        std::cout << "Error receiving the message" << std::endl;
    }
    else
    {
        std::cout << message << std::endl;
        system("pause");

    }
    //shut down the SDL/Connection
    SDLNet_TCP_Close(socket);
    SDLNet_Quit;
    SDL_Quit;
    system("pause");
    return 0;
}