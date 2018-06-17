#ifndef Genetics_h
#define Genetics_h

//#include <list>
#include "Zaslepka.h"
#include <iostream>
#include <time.h>

#define numberOfAlgoritsm	10;

class Genetics {
private:
	//std::list<Zaslepka> beforeCrosingList;
	//std::list<Zaslepka> afterCrosingList;
	Zaslepka* beforeCrosingList;
	Zaslepka* afterCrosingList;
	Zaslepka* bestVictory;
	Zaslepka* bestSum;
	Zaslepka* getBestAlgoritm(char kindMark);
	void updateBestAlgoritms();
public:
	Genetics(Zaslepka* beforeCrossing);
	Zaslepka* getAfterCrossing();	
	void getBestAlgoritmsList();
	~Genetics();
	Zaslepka* getBestVictory();
	Zaslepka* getBestSum();
	void crossAllAlgoritms(int mutationChance);
	Zaslepka* crossSingleAlgoritm(Zaslepka* first, Zaslepka* secound, int chanceToMutate);	//chanseTomutate <0-100>
};

#endif 
