#ifndef CONNECTION_H
#define CONNECTION_H
#include "Game.h"
#include <SFML/Network.hpp>
#include "json\json.h"
#include <fstream>


#define serverIPAdress	"127.0.0.1"	//server's IP Adress -								modify only here
#define portNumber		55888		//port on which we'll be waiting ffor players -		modify only here
#define firstIPAdress	"127.0.0.1"	//IP adress of first player -						modify only here
#define firstPort		55889		//port of first player -							modify only here
#define secoundIPAdress "127.0.0.1"	//IP adress of secound player -						modify only here
#define secoundPort		558890		//port of secound player -							modify only here

/*
How the data is send between clients and server:
-The side that want to send message creates properly .json file;
-The file is then parse to string and then to char*;
-Char* is send to the receiving side by sfml (by ehternet using sfml library);
-Received char* turns into string and then it is used to make .json file;
-Receiving side reads on .json file.
*/


class Connection {
private:
	Game *currentGame;
	int PORT;
	sf::UdpSocket socket;
public:
	Connection();
	~Connection();
	void searchForPlayers();
	void sendMessage(Player* toWho, std::string message);
	std::string reciveMessage(Player* fromWho);
	Game* getCurrentGame() { return this->currentGame; }
};

#endif
