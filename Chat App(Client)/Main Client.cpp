#include"Client_Connection.h"
bool AppisRunning = true;
bool AmRunning = false;
Client_Connection Client;
int main(int argc, char* argv[])
{
    Client.Initialize();
    std::cout << "WELCOME TO HELL!" << std::endl;
    Client.Open_Socket();
    std::cout << "Client Connected." << std::endl;
    std::string Send;
    std::string Receive;

    system("cls");
    system("pause");

    while (AppisRunning)
    {
        if (AmRunning)
        {
            std::cout << "Say: ";
            std::getline(std::cin, Send);
            if (Client.Send(Send))
            {
                system("pause");
                AmRunning = false;
            }
            Send.clear();
        }
        else
        {
            if (Client.Receive(Receive))
            {
                std::cout << "Receive: ";
                std::cout << Receive << std::endl;;
                system("pause");
                AmRunning = true;
            }
        }
    }
    Client.CloseSocket();
    Client.ShutDown();
    system("pause");
    return 0;
}