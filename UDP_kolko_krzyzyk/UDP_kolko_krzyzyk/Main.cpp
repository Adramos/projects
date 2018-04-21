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










	std::string testowy;
	/*std::cout << "\nTest";
	std::fstream plik;
	plik.open("test.json", std::ios::in);
	if (plik.good()) {
		std::cout << "Udalo sie";
		std::cin >> testowy;
	}
	else {
		std::cout << "Nie udalo sie";
		std::cin >> testowy;
	}
*/
	std::ofstream file_id;
	file_id.open("file.json");
	std::ifstream ifs("test.json");
//	Json::Reader reader;
	Json::Value obj;
	
	
	reader.parse(ifs, obj); // reader can also read strings
	std::cout << "Book: " << obj["book"].asString() << "\n";
	std::cout << "Year: " << obj["year"].asString() << "\n";
	const Json::Value& characters = obj["characters"]; // array of characters
	for (int i = 0; i < characters.size(); i++) {
		std::cout << "    name: " << characters[i]["name"].asString();
		std::cout << " chapter: " << characters[i]["chapter"].asUInt();
		std::cout << std::endl;
	}
	std::cin >> testowy;

	std::string strJson = "{\"response\" : \"error\", \"error_code\" : 1}";
		//"{\"mykey\" : \"myvalue\"}";
	reader.parse(strJson.c_str(), obj);
	Json::StreamWriterBuilder fastWriter;
	//Json::StyledStreamWriter styledWriter;

	

	
	fastWriter["commentStyle"] = "None";
	fastWriter["indentation"] = "   ";  // or whatever you like
	std::unique_ptr<Json::StreamWriter> writer(fastWriter.newStreamWriter());
	writer->write(obj, &file_id);
	std::cin >> testowy;
		/*
	std::cin >> obj;
	reader.parse(ifs, obj);
	std::cout << obj["abc"].asString() << "\n";
	std::cin >> testowy;
		*/
}