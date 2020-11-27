#include"TCP_Connection.h"
#include <thread>

TCP_Connection Server;

bool exitChat = false;

void Sending(std::string Send);
void Receiveing(std::string Receive);

int main(int argc, char* argv[])
{
    Server.Initialize();
    std::cout << "WELCOME TO HELL!" << std::endl;
    Server.OpenSocket();
    Server.C_O_Socket();
    std::cout << "Client Connected." << std::endl;
    std::string Send;
    std::string Receive;

    std::thread SendMessage;
    std::thread ReceiveMessage;

    system("cls");
    system("pause");

    SendMessage = std::thread(Sending, Send);
    ReceiveMessage = std::thread(Receiveing, Receive);
    SendMessage.detach();
    ReceiveMessage.detach();
    
    while (!exitChat)
    {
        
    }

    Server.CloseSocket();
    Server.ShutDown();
    system("pause");
    return 0;
}
void Sending(std::string Send)
{
    while (!exitChat)
    {
        std::cout << "Say: ";
        std::getline(std::cin, Send);
        if (!Server.Send(Send))
        {
            std::cout << "Error on server sending part." << std::endl;
        }
        if (Send == "exit")
        {
            exitChat = true;
        }
        Send.clear();
    }
}

void Receiveing(std::string Receive)
{
    while (!exitChat)
    {
        if (Server.Receive(Receive))
        {
            std::cout << std::endl << "Receive: ";
            std::cout << Receive << std::endl;;
        }
        if (Receive == "exit")
        {
            exitChat = true;
        }
    }
}

