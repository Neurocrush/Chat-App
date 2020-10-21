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

	std::cout << "WELCOME TO HELL!"<<std::endl;

    while (1)
    {
        std::cout << ".";
        SDL_Delay(500);
    }

	system("pause");
	return 0;
}