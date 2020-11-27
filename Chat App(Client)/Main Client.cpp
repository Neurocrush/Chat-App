#include"Client_Connection.h"
#include <thread>

Client_Connection Client;

bool exitChat = false;

void Sending(std::string Send);
void Receiveing(std::string Receive);

int main(int argc, char* argv[])
{
    Client.Initialize();
    std::cout << "WELCOME TO HELL!" << std::endl;
    Client.Open_Socket();
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

    Client.CloseSocket();
    Client.ShutDown();
    system("pause");
    return 0;
}

void Sending(std::string Send)
{
    while (!exitChat)
    {
        std::cout << "Say: ";
        std::getline(std::cin, Send);
        if (!Client.Send(Send))
        {
            std::cout << "Error on client sending part." << std::endl;
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
        if (Client.Receive(Receive))
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
