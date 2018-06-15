#include <iostream>
#include <SFML\Network.hpp>

int main() {
	unsigned short port;
	std::string navMark = "o";
	const std::string ip = "127.0.0.1";
	sf::IpAddress server(ip);
	sf::IpAddress client(ip);
	sf::UdpSocket socket;
	char data[100];
	std::string messageString;
	std::size_t received;

	std::getline(std::cin, messageString);
	port = stoi(messageString);
	socket.bind(port);

	while (navMark != "q") {
		std::getline(std::cin, navMark);
		if (navMark == "r") {
			//socket.unbind();
			
			if (socket.receive(data, 100, received, server, port) != sf::Socket::Done) {
				std::cout << "\nCan't recive message!\n";
				//socket.unbind();
			}
			//socket.unbind();

			messageString = data;
			std::cout << messageString << "\n";
		}
		else if (navMark == "s") {

			std::getline(std::cin, messageString);
			strcpy_s(data, messageString.c_str());
			if (socket.send(data, 100, server, 55888) != sf::Socket::Done)
			{
				std::cout << "\nCan't send message!\n";
			}
		}

	}
}