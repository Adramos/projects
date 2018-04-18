#include "Game.h"

void Game::clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->gameBoard[i][j] = '.';
		}
	}
}
