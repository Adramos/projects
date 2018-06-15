#include "Connection.h"

Connection::Connection() {
	currentGame = new Game();
	PORT = portNumber;
}

Connection::~Connection() {
	delete this->currentGame;
}

void Connection::searchForPlayers() {
	
	char data[100];					//maximum lenght of message is more or less 75 signs, but to be sure we'll use 100 signs' table				
	Json::Reader reader;
	//Json::StreamWriterBuilder fastWriter;
	Json::Value value, returnMessage;
	std::string jsonString;
	sf::IpAddress firstSender(firstIPAdress), secoundSender(secoundIPAdress);
	unsigned short firstP = firstPort, secoundP = secoundPort;
	std::size_t received;
	bool firstOK = false, secoundOK = false;

	while (currentGame->getGameStatus() != 'w') {
		if (firstOK == false) {
			socket.unbind();
			socket.bind(portNumber);
			if (socket.receive(data, 100, received, firstSender, firstP) != sf::Socket::Done) {
				std::cout << "\nError, couldn't recived message form A.";
				//socket.unbind();
				//sending error message
				jsonString = "{\"response\" : \"error\", \"error_code\" : 0}";
				strcpy_s(data, jsonString.c_str());
				if (socket.send(data, 100, firstSender, firstP) != sf::Socket::Done)
				{
					std::cout << "\nCan't send message!";
				}
			}
			else {
				//socket.unbind();
				jsonString = data;
				reader.parse(jsonString.c_str(), value);
				if (value["request"].asString() == "connection") {
					Player *playerA = new Player(firstIPAdress, firstP, 'A');
					currentGame->addPlayer(playerA, true);
					if (currentGame->getGameStatus() == 'n')
						currentGame->changeGameStatue('o');
					else
						currentGame->changeGameStatue('w');
					firstOK = true;
					//sending confirm message
					jsonString = "{\"response\" : \"confirm\"}";
					strcpy_s(data, jsonString.c_str());
					if (socket.send(data, 100, firstSender, firstP) != sf::Socket::Done)
					{
						std::cout << "\nCan't send message!";
					}
				}
				else {
					jsonString = "{\"response\" : \"error\", \"error_code\" : 1}";
					strcpy_s(data, jsonString.c_str());
					if (socket.send(data, 100, firstSender, firstP) != sf::Socket::Done)
					{
						std::cout << "\nCan't send message!";
					}
				}
			}
			
		}

		if (secoundOK == false) {
			socket.unbind();
			socket.bind(portNumber);
			if (socket.receive(data, 100, received, secoundSender, secoundP) != sf::Socket::Done) {
				std::cout << "\nError, couldn't recived message from B.";
				//socket.unbind();
				//sending error message
				jsonString = "{\"response\" : \"error\", \"error_code\" : 0}";
				strcpy_s(data, jsonString.c_str());
				if (socket.send(data, 100, secoundSender, secoundP) != sf::Socket::Done)
				{
					std::cout << "\nCan't send message!";
				}
			}
			else {
				//socket.unbind();
				jsonString = data;
				reader.parse(jsonString.c_str(), value);
				if (value["request"].asString() == "connection") {
					Player * playerB = new Player(secoundIPAdress, secoundP, 'B');
					currentGame->addPlayer(playerB, false);
					if (currentGame->getGameStatus() == 'n')
						currentGame->changeGameStatue('o');
					else
						currentGame->changeGameStatue('w');
					secoundOK = true;
					//sending confirm message
					jsonString = "{\"response\" : \"confirm\"}";
					strcpy_s(data, jsonString.c_str());
					if (socket.send(data, 100, secoundSender, secoundP) != sf::Socket::Done)
					{
						std::cout << "\nCan't send message!";
					}
				}
				else {
					jsonString = "{\"response\" : \"error\", \"error_code\" : 1}";
					strcpy_s(data, jsonString.c_str());
					if (socket.send(data, 100, secoundSender, secoundP) != sf::Socket::Done)
					{
						std::cout << "\nCan't send message!";
					}
				}
			}
		}
	}
}

void Connection::sendMessage(Player* toWho, std::string message) {
	char data[100];
	sf::IpAddress ip(toWho->getIP());
	strcpy_s(data, message.c_str());
	if (socket.send(data, 100, ip, toWho->getPort()) != sf::Socket::Done)
	{
		std::cout << "\nCan't send message!";
	}

}

std::string Connection::reciveMessage(Player* fromWho) {
	char data[100];
	std::string messageString;
	std::size_t received;
	unsigned short port = fromWho->getPort();

	socket.unbind();
	socket.bind(portNumber);	
	sf::IpAddress ip(fromWho->getIP());
	if (socket.receive(data, 100, received, ip, port) != sf::Socket::Done) {		
		std::cout << "\nCan't recive message!";
		//socket.unbind();
		return "";
	}
	//socket.unbind();
	messageString = data;
	return messageString;
}