#include "Connection.h"

Connection::Connection(int portAdress) {
	currentGame = new Game();
	PORT = portAdress;
}

void Connection::searchForPlayers() {
	
	char data[100];					//maximum lenght of message is more or less 75 signs, but to be sure we'll use 100 signs' table				
	Json::Reader reader;
	Json::StreamWriterBuilder fastWriter;
	Json::Value value, returnMessage;
	std::string jsonString;
	sf::IpAddress firstSender(firstIPAdress), secoundSender(secoundIPAdress);
	unsigned short firstP = firstPort, secoundP = secoundPort;
	std::size_t received;
	bool firstOK = false, secoundOK = false;

	while (currentGame->getGameStatus() != 'w') {
		if (firstOK == false) {
			socket.bind(portNumber);
			if (socket.receive(data, 100, received, firstSender, firstP) != sf::Socket::Done) {
				std::cout << "\nError, couldn't recived message form A.";
				//sending error message
				jsonString = "{\"response\" : \"error\", \"error_code\" : 0}";
				strcpy_s(data, jsonString.c_str());
				if (socket.send(data, 100, firstSender, firstP) != sf::Socket::Done)
				{
					std::cout << "\nCan't send message!";
				}
			}
			else {
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
			}
			socket.unbind();
		}

		if (secoundOK == false) {
			socket.bind(portNumber);
			if (socket.receive(data, 100, received, secoundSender, secoundP) != sf::Socket::Done) {
				std::cout << "\nError, couldn't recived message from B.";
				//sending error message
				jsonString = "{\"response\" : \"error\", \"error_code\" : 0}";
				strcpy_s(data, jsonString.c_str());
				if (socket.send(data, 100, secoundSender, secoundP) != sf::Socket::Done)
				{
					std::cout << "\nCan't send message!";
				}
			}
			else {
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
			}
		}
	}
}