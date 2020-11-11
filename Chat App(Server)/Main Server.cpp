#include"TCP_Connection.h"
#include <thread>

TCP_Connection Server;

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
    
    while (Send != "end" && Receive != "end")
    {
        SendMessage = std::thread(Sending, Send);
        ReceiveMessage = std::thread(Receiveing, Receive);
        SendMessage.join();
        ReceiveMessage.join();
        
    }
    Server.CloseSocket();
    Server.ShutDown();
    system("pause");
    return 0;
}
void Sending(std::string Send)
{
    std::cout << "Say: ";
    std::getline(std::cin, Send);
    if (!Server.Send(Send))
    {
        std::cout << "Error on server sending part." << std::endl;
    }
    Send.clear();
}

void Receiveing(std::string Receive)
{
    if (Server.Receive(Receive))
    {
        std::cout << std::endl << "Receive: ";
        std::cout << Receive << std::endl;;
    }
}

