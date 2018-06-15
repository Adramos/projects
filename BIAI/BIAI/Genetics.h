#ifndef Genetics_h
#define Genetics_h

//#include <list>
#include "Zaslepka.h"
#include <iostream>
#include <time.h>

class Genetics {
private:
	//std::list<Zaslepka> beforeCrosingList;
	//std::list<Zaslepka> afterCrosingList;
	Zaslepka* beforeCrosingList;
	Zaslepka* afterCrosingList;
	Zaslepka* bestVictory;
	Zaslepka* bestSum;

public:
	Genetics(Zaslepka* beforeCrossing);
	Zaslepka* getAfterCrossing();
	Zaslepka* getBestAlgoritm(char kindMark);
	void getBestAlgoritmsList();
	~Genetics();
	Zaslepka* getBestVictory();
	Zaslepka* getBestSum();
	void updateBestAlgoritms();
};

#endif 
