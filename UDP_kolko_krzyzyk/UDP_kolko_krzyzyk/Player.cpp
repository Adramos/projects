#include "Player.h"

Player::Player(std::string ip, unsigned short port, char id) {
	this->ID = id;
	this->ipAdress = ip;
	this->portNumber = port;
}