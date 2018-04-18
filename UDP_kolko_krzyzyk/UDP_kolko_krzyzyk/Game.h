#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game {
private:
	//Status of the game, possible valuses: n - no players, o - only one player, w - waiting for move (both players - game started).
	char gameStatus;
	Player playerOne, PlayerTwo;
	//If reversedPlayers is false: PlayerA = PlayerOne, PlayerB = PlayerTwo. If it's false": PlayerA = PlayerTwo, PlayerB = PlayerOne. 
	bool reversedPlayers;
	char gameBoard[3][3];
	void clearBoard();
public:
	
};

#endif 

