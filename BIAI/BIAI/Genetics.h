#ifndef Genetics_h
#define Genetics_h

//#include <list>
#include "Organism.h"
#include <iostream>
#include <time.h>

#define numberOfAlgoritsm	10;

class Genetics {
private:
	//std::list<Organism> beforeCrosingList;
	//std::list<Organism> afterCrosingList;
	Organism* beforeCrosingList;
	Organism* afterCrosingList;
	Organism* bestVictory;
	Organism* bestSum;
	Organism* getBestAlgoritm(char kindMark);
	void updateBestAlgoritms();
public:
	Genetics(Organism* beforeCrossing);
	Organism* getAfterCrossing();	
	void getBestAlgoritmsList();
	~Genetics();
	Organism* getBestVictory();
	Organism* getBestSum();
	void crossAllAlgoritms(int mutationChance);
	Organism* crossSingleAlgoritm(Organism* first, Organism* secound, int chanceToMutate);	//chanseTomutate <0-100>
};

#endif 
