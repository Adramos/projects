/*
Author:		Pawe³ Jurczyk
*/

#include "Connection.h"
#include <memory>





int main() {

	Connection *connector = new Connection();
	//end -> end of playing, finished -> end of single game, whoMakesMove -> is it now the first player move
	bool end = false, finished = false, whoMakesMove;
	std::string messageString;
	Json::Reader reader;
	Json::StreamWriterBuilder builder;
	Json::Value value;
	int row, column;

	connector->searchForPlayers();
	while (end != true) {
		finished = false;
		connector->getCurrentGame()->startGame();
		if (connector->getCurrentGame()->isReversted()) {
			//PlayerTwo makes first move
			//send message that player is making first move
			messageString = "{\"response\" : \"your move\"}";
			connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
			whoMakesMove = false;
			while (finished != true) {
				if (whoMakesMove == true) {
					//first palyer's (A) move
					messageString = connector->getCurrentGame()->getBoard();
					connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
					messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('A'));
					if (messageString != "") {
						reader.parse(messageString, value);
						if (value["request"].asString() == "player move") {
							//player move
							if (value["player"].asString() != "A") {
								messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
								connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
							}
							else {
								if (value["position"]["x"].isInt() && value["position"]["y"].isInt()) {
									row = value["position"]["x"].asInt();
									column = value["position"]["y"].asInt();
									messageString = connector->getCurrentGame()->makeMove('A', row, column);
									reader.parse(messageString, value);
									if (value["response"].asString() == "ok") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										whoMakesMove = false;
									}
									else if (value["response"].asString() == "error") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
									}
									else {
										//game is finished
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										messageString = connector->getCurrentGame()->getBoard();

										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										finished = true;
									}
								}
								else {
									messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
									connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
								}
							}
						}
						else if (value["request"].asString() == "game status") {
							//game status
							messageString = connector->getCurrentGame()->getBoard();
							connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
						}
						else {
							//bad request
							messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
							connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
						}
					}
				}
				else {
					//secound player's (B) move
					messageString = connector->getCurrentGame()->getBoard();
					connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
					messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('B'));
					if (messageString != "") {
						reader.parse(messageString, value);
						if (value["request"].asString() == "player move") {
							//player move
							if (value["player"].asString() != "B") {
								messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
								connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
							}
							else {
								if (value["position"]["x"].isInt() && value["position"]["y"].isInt()) {
									row = value["position"]["x"].asInt();
									column = value["position"]["y"].asInt();
									messageString = connector->getCurrentGame()->makeMove('B', row, column);
									reader.parse(messageString, value);
									if (value["response"].asString() == "ok") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
										whoMakesMove = true;
									}
									else if (value["response"].asString() == "error") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
									}
									else {
										//game is finished
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										messageString = connector->getCurrentGame()->getBoard();

										//showing how board looks like
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										finished = true;
									}
								}
								else {
									messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
									connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
								}
							}
						}
						else if (value["request"].asString() == "game status") {
							//game status
							messageString = connector->getCurrentGame()->getBoard();
							connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
						}
						else {
							//bad request
							messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
							connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
						}
					}
				}
			}
		}
		else {
			//PlayerOne makes first move
			//send message that player is making first move
			messageString = "{\"response\" : \"your move\"}";
			connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
			whoMakesMove = true;
			while (finished != true) {
				if (whoMakesMove == true) {
					//first palyer's (A) move
					messageString = connector->getCurrentGame()->getBoard();
					connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
					messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('A'));
					if (messageString != "") {
						reader.parse(messageString, value);
						if (value["request"].asString() == "player move") {
							//player move
							if (value["player"].asString() != "A") {
								messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
								connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
							}
							else {
								if (value["position"]["x"].isInt() && value["position"]["y"].isInt()) {
									row = value["position"]["x"].asInt();
									column = value["position"]["y"].asInt();
									messageString = connector->getCurrentGame()->makeMove('A', row, column);
									reader.parse(messageString, value);
									if (value["response"].asString() == "ok") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										whoMakesMove = false;
									}
									else if(value["response"].asString() == "error"){
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
									}
									else {
										//game is finished
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										messageString = connector->getCurrentGame()->getBoard();

										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										finished = true;
									}
								}
								else {
									messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
									connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
								}
							}
						}
						else if (value["request"].asString() == "game status") {
							//game status
							messageString = connector->getCurrentGame()->getBoard();
							connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
						}
						else {
							//bad request
							messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
							connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
						}
					}
				}
				else {
					//secound player's (B) move
					messageString = connector->getCurrentGame()->getBoard();
					connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
					messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('B'));
					if (messageString != "") {
						reader.parse(messageString, value);
						if (value["request"].asString() == "player move") {
							//player move
							if (value["player"].asString() != "B") {
								messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
								connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
							}
							else {
								if (value["position"]["x"].isInt() && value["position"]["y"].isInt()) {
									row = value["position"]["x"].asInt();
									column = value["position"]["y"].asInt();
									messageString = connector->getCurrentGame()->makeMove('B', row, column);
									reader.parse(messageString, value);
									if (value["response"].asString() == "ok") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
										whoMakesMove = true;
									}
									else if (value["response"].asString() == "error") {
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
									}
									else {
										//game is finished
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										messageString = connector->getCurrentGame()->getBoard();

										//showing how board looks like
										connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
										connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

										finished = true;
									}
								}
								else {
									messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
									connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
								}
							}
						}
						else if (value["request"].asString() == "game status") {
							//game status
							messageString = connector->getCurrentGame()->getBoard();
							connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
						}
						else {
							//bad request
							messageString = "{\"response\" : \"error\", \"error_code\" : 1}";
							connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);
						}
					}
				}
			}		
		}

		//continue/end
		//{"response" : "continue"}
		/*
		{"request" : "Yes"}	-> end == false 	-> for continue playing
		{"request" : "No"}	-> end == true		-> for ending game (if one gives yes, and another gives no -> end game) 
		*/


		messageString = "{\"response\" : \"continue\"}";
		connector->sendMessage(connector->getCurrentGame()->getPlayer('A'), messageString);
		connector->sendMessage(connector->getCurrentGame()->getPlayer('B'), messageString);

		messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('A'));
		reader.parse(messageString, value);
		if (value["response"].asString() == "No")
			end = true;
		
		messageString = connector->reciveMessage(connector->getCurrentGame()->getPlayer('B'));
		reader.parse(messageString, value);
		if (value["response"].asString() == "No")
			end = true;

	}
	//clearing
	delete connector;
}