#include<iostream>
#include<string>
#include <SDL.h>
#include<SDL_net.h>


int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL could not initialize" << std::endl;
    }
    if (SDLNet_Init() == -1)
    {
        std::cout << "SDLNet could not initialize" << std::endl;
    }

    std::cout << "WELCOME TO HELL!" << std::endl;

    IPaddress ip;

    if (SDLNet_ResolveHost(&ip, "www.youtube.com", 80) == -1)
    {
        std::cout << "Error establishing connection to the website." << std::endl;
        system("pause");
        return 0;
    }

    TCPsocket socket = SDLNet_TCP_Open(&ip);

    if (!socket)
    {
        std::cout << "Error opening up socket for connection." << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        //special request to get HTML code from website
        std::string message = "GET /HTTPS/1.0\r\n\r\n";

        //we ned length of message in order to send data
        //we add an extra space for the terminating null '\0'
        int messageLength = message.length() + 1;

        //send message via open socket that we opened up above
        //if return value is less than length of message thn error occured
        if (SDLNet_TCP_Send(socket, message.c_str(), messageLength) < messageLength)
        {
            std::cout << "Error sending the request to website" << std::endl;
        }
        else
        {
            const int BUFFER_SIZE = 2000;

            char response[BUFFER_SIZE];

            if (SDLNet_TCP_Recv(socket, response, 2000) <= 0)
            {
                std::cout << "Error receiving message from website." << std::endl;
            }
            else
            {
                std::cout << response << std::endl;
            }
        }
        SDLNet_TCP_Close(socket);
    }
    //shut down the SDL/Connection
    SDLNet_Quit;
    SDL_Quit;

    system("pause");
    return 0;
}