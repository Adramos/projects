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

void Game::addPlayer(Player* player, bool first) {
	if (first)
		playerOne = player;
	else
		PlayerTwo = player;
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