#include "Game.h"

void Game::clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->gameBoard[i][j] = '.';
		}
	}
}

Game::Game() {
	gameStatus = 'n';
	this->clearBoard();
	
}

Game::~Game() {
	delete this->playerOne;
	delete this->playerTwo;
}

void Game::addPlayer(Player* player, bool first) {
	if (first)
		playerOne = player;
	else
		playerTwo = player;
}

bool Game::isFinishedA() {
	for (int i = 0; i < 3; i++) {
		if (this->gameBoard[i][0] == 'A' && this->gameBoard[i][1] == 'A' && this->gameBoard[i][2] == 'A')
			return true;
		if (this->gameBoard[0][i] == 'A' && this->gameBoard[1][i] == 'A' && this->gameBoard[2][i] == 'A')
			return true;
	}
	if (this->gameBoard[0][0] == 'A' && this->gameBoard[1][1] == 'A' && this->gameBoard[2][2] == 'A')
		return true;
	if (this->gameBoard[2][0] == 'A' && this->gameBoard[1][1] == 'A' && this->gameBoard[0][2] == 'A')
		return true;

	return false;
}

bool Game::isFinishedB() {
	for (int i = 0; i < 3; i++) {
		if (this->gameBoard[i][0] == 'B' && this->gameBoard[i][1] == 'B' && this->gameBoard[i][2] == 'B')
			return true;
		if (this->gameBoard[0][i] == 'B' && this->gameBoard[1][i] == 'B' && this->gameBoard[2][i] == 'B')
			return true;
	}
	if (this->gameBoard[0][0] == 'B' && this->gameBoard[1][1] == 'B' && this->gameBoard[2][2] == 'B')
		return true;
	if (this->gameBoard[2][0] == 'B' && this->gameBoard[1][1] == 'B' && this->gameBoard[0][2] == 'B')
		return true;

	return false;
}

bool Game::isFinishedT() {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			if (this->gameBoard[i][j] == '.')
				return false;

	return true;
}

void Game::startGame() {
	this->clearBoard();
	srand(time(NULL));
	if (rand() % 2 == 0)
		this->reversedPlayers = false;
	else
		this->reversedPlayers = true;
}

std::string Game::getBoard() {
	std::string returnString = "{\"response\" : \"game status\", \"board\" : [";
	for (int i = 0; i < 3; i++) {
		returnString += "\"";
		for (int j = 0; j < 3; j++) {
			returnString = returnString + this->gameBoard[i][j];
		}
		returnString += "\"";
		if (i < 2)
			returnString += ", ";
	}

	returnString += "]}";
	return returnString;
}

std::string Game::makeMove(char playerID, int row, int column) {
	std::string returnString = "{\"response\" : ";
	if (row < 0 || row > 2 || column < 0 || column > 2)
		returnString += "\"error\", \"error_code\" : 3}";	
	else if (this->gameBoard[row][column] != '.') 
		returnString += "\"error\", \"error_code\" : 4}";
	else {
		this->gameBoard[row][column] = playerID;
		if (playerID == 'A') {
			if (this->isFinishedA()) 
				returnString += "\"game over\", \"details\" : \"A won\"}";			
			else if(this->isFinishedT())
				returnString += "\"game over\", \"details\" : \"undecided\"}";
			else
				returnString += "\"ok\"";
		}
		else {
			if (this->isFinishedB())
				returnString += "\"game over\", \"details\" : \"B won\"}";
			else if (this->isFinishedT())
				returnString += "\"game over\", \"details\" : \"undecided\"}";
			else
				returnString += "\"ok\"";
		}		
	}
	return returnString;
}

Player* Game::getPlayer(char who) {
	if (who == 'A')
		return this->playerOne;
	else
		return this->playerTwo;
}