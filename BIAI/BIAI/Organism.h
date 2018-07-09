#ifndef Organism_h
#define Organism_h
#include "Algoritms.h"

class Organism {
private:
	float wygrane;		//why not int? Because we use Wins/numberOfGames
	int zarobek;
	int genotype[35][10];			//r <0-9>, c <0-35> -> i == r, j == c 
	int row;
	int column;				
	bool twoCards;
public:
	Organism(float wyg, int zar);
	Organism(Organism &copy);
	Organism* nast;
	float getWygrane();
	int getZarobek();
	void setGenotypeValue(int i, int j, int value);
	int getGenotypeValue(int i, int j);
	void setRCSituation(std::vector<int> player, std::vector<int> dealer);
	void AxSituation(std::vector<int> player, std::vector<int> dealer);
	void xxSituation(std::vector<int> player, std::vector<int> dealer);
	void abSituation(std::vector<int> player, std::vector<int> dealer);
};

#endif 

