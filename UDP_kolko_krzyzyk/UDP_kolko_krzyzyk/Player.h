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
};

#endif
