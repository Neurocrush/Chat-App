#include"TCP_Connection.h"
bool AppisRunning = true;
bool AmRunning = true;
TCP_Connection Server;
int main(int argc, char* argv[])
{
    Server.Initialize();
    std::cout << "WELCOME TO HELL!" << std::endl;
    Server.OpenSocket();
    Server.C_O_Socket();
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
           if(Server.Send(Send))
           {
               system("pause");
               AmRunning = false;
           }
           Send.clear();
        }
        else
        {
            if (Server.Receive(Receive))
            {
                std::cout << "Receive: ";
                std::cout << Receive << std::endl;;
                system("pause");
                AmRunning = true;
            }
        }
    }
    Server.CloseSocket();
    Server.ShutDown();
    system("pause");
    return 0;
}