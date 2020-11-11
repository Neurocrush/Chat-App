#include"Client_Connection.h"
#include <thread>

Client_Connection Client;

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

    while (Send != "end" && Receive != "end")
    {
        SendMessage = std::thread(Sending, Send);
        ReceiveMessage = std::thread(Receiveing, Receive);
        SendMessage.join();
        ReceiveMessage.join();
    }
    Client.CloseSocket();
    Client.ShutDown();
    system("pause");
    return 0;
}

void Sending(std::string Send)
{
    std::cout << "Say: ";
    std::getline(std::cin, Send);
    if (!Client.Send(Send))
    {
        std::cout << "Error on client sending part." << std::endl;
    }
    Send.clear();
}

void Receiveing(std::string Receive)
{
    if (Client.Receive(Receive))
    {
        std::cout << std::endl<< "Receive: ";
        std::cout << Receive << std::endl;;
    }
}
