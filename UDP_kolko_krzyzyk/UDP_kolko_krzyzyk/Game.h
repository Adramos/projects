#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <ctime>

class Game {
private:
	//Status of the game, possible valuses: n - no players, o - only one player, w - waiting for move (both players - game started).
	char gameStatus;
	Player *playerOne, *playerTwo;
	//If reversedPlayers is false: PlayerA = PlayerOne, PlayerB = PlayerTwo. If it's false": PlayerA = PlayerTwo, PlayerB = PlayerOne. 
	bool reversedPlayers;
	char gameBoard[3][3];
	void clearBoard();
public:
	Game();
	~Game();
	void addPlayer(Player* player, bool first);
	bool isFinishedA();
	bool isFinishedB();
	bool isFinishedT();
	char getGameStatus() { return this->gameStatus; }
	void changeGameStatue(char change) { this->gameStatus = change; }
	Player* getPlayer(char who);
	void startGame();
	std::string getBoard();
	std::string makeMove(char playerID, int row, int column);
	bool isReversted() { return this->reversedPlayers; }
};

#endif 

