#include<iostream>
#include<string>
#include <SDL.h>
#include<SDL_net.h>

const int port = 1234;

std::string message;
//Struct to store the host address (IP) and port number.
IPaddress ip;

//socket to listen to incoming connections
TCPsocket listenSocket = nullptr;

//socket to transfr data to client
TCPsocket clientSocket = nullptr;


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
 //Server setings
 //=============================================


    if (SDLNet_ResolveHost(&ip, nullptr, 1234) == -1)
    {
        std::cout << "Error creating a server." << std::endl;
        system("pause");
        return 0;
    }

    listenSocket= SDLNet_TCP_Open(&ip);   

    if (!listenSocket)
    {
        std::cout << "Error opening up socket for connection." << std::endl;
        system("pause");
        return 0;
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
    std::cout << "Client Connected." << std::endl;
    system("pause");

    system("cls");
    std::cout << "WELCOME TO HELL!" << std::endl;

        //create a friendly message for the client
    message = "Ohh you poor soul, You just had to come here.";
        //we ned length of message in order to send data
        //we add an extra space for the terminating null '\0'
        int messageLength = message.length() + 1;

        //send message via open socket that we opened up above
        //if return value is less than length of message thn error occured
        if (SDLNet_TCP_Send(clientSocket, message.c_str(), messageLength) < messageLength)
        {
            std::cout << "Error sending the message" << std::endl;
        }
        else
        {
            std::cout << "Message sent to client." << std::endl;
        }
        SDLNet_TCP_Close(clientSocket);
    //shut down the SDL/Connection
    SDLNet_Quit;
    SDL_Quit;

    system("pause");
    return 0;
}