/*
Author:		Pawe³ Jurczyk

This file contains the game's logic. 

*/

#include "Connection.h"
#include <memory>





int main() {

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
	Json::Reader reader;
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