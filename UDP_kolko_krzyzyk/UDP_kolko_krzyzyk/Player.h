#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player {
private:
	std::string ipAdress;
	unsigned short portNumber;
	char ID;
public:
	Player(std::string ip, unsigned short port, char id);
	~Player();
	char getID() { return this->ID; }
	std::string getIP() { return this->ipAdress; }
	unsigned short getPort() { return this->portNumber; }
};

#endif
