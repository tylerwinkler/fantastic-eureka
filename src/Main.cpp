#include <iostream>

#include "SFML/Network/Packet.hpp"
#include "SFML/Network/TcpListener.hpp"
#include "SFML/Network/TcpSocket.hpp"

int main(int argc, char* argv[])
{
    sf::TcpListener listener;
    if (listener.listen(2000) == sf::Socket::Error)
    {
        std::cout << "Failed to listen on port 80\n";
        return false;
    }

    while (true)
    {
        sf::TcpSocket socket;
        if (listener.accept(socket) == sf::Socket::Done)
        {
            std::cout << "Packet received\n";

            sf::Packet packet;
            socket.receive(packet);

            std::string str;
            packet >> str;

            std::cout << str << "\n";
        }
    }

    return 0;
}
