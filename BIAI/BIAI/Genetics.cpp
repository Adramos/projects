#include "Genetics.h"

Genetics::Genetics(Zaslepka* beforeCrossing){
	this->beforeCrosingList = beforeCrossing,
	this->afterCrosingList = nullptr;
}

Zaslepka* Genetics::getAfterCrossing() {
	return this->afterCrosingList;
}

Genetics::~Genetics() {

	Zaslepka* ElementOfList = nullptr, *nextElement;
	ElementOfList = this->beforeCrosingList;
	while (ElementOfList->nast != nullptr) {
		nextElement = ElementOfList->nast;
		delete ElementOfList;
		ElementOfList = nextElement;
	}
	delete ElementOfList;

	ElementOfList = this->afterCrosingList;
	while (ElementOfList->nast != nullptr) {
		nextElement = ElementOfList->nast;
		delete ElementOfList;
		ElementOfList = nextElement;
	}
	delete ElementOfList;

}

Zaslepka* Genetics::getBestAlgoritm(char kindMark) {
	Zaslepka* bestAlgoritm = nullptr, *iterator;
	int numberOfElements = 0;
	int highestSum = this->beforeCrosingList->getZarobek();
	float hightestVictories = -1;	//minimal equals 0, so it'll be lower then any of elements
	switch (kindMark){
	case 'w':	//wygrane = victories -> number of won games
		
		iterator = this->beforeCrosingList;
		while (iterator != nullptr) {
			if (iterator->getWygrane() > hightestVictories) {
				hightestVictories = iterator->getWygrane();
			}
			iterator = iterator->nast;
		}
		iterator = this->beforeCrosingList;
		while (iterator->getWygrane() != hightestVictories)
			iterator = iterator->nast;
		bestAlgoritm = iterator;
		iterator = this->beforeCrosingList;
		if (iterator == bestAlgoritm) {
			beforeCrosingList = bestAlgoritm->nast;
		}
		else {
			while (iterator->nast != bestAlgoritm)
				iterator = iterator->nast;
			iterator->nast = bestAlgoritm->nast;
		}
		break;
	case 'z':	//zarobek = won sum -> amount of won/lost money
		
		iterator = this->beforeCrosingList->nast;
		while (iterator != nullptr) {
			if (iterator->getZarobek() > highestSum) {
				highestSum = iterator->getZarobek();
			}
			iterator = iterator->nast;
		}
		iterator = this->beforeCrosingList;
		if (iterator->getZarobek() == highestSum) {
			bestAlgoritm = iterator;
			beforeCrosingList = bestAlgoritm->nast;
		}
		else {
			while (iterator->nast->getZarobek() != highestSum) {
				iterator = iterator->nast;
			}
			bestAlgoritm = iterator->nast;
			iterator->nast = bestAlgoritm->nast;
		}
		break;
	case 'l':	//losowy = random -> we should also take 2-3 (3!) random algoritsm
		
		iterator = beforeCrosingList;
		while (iterator != nullptr) {
			iterator = iterator->nast;
			numberOfElements++;
		}
		srand(time(NULL));
		numberOfElements = rand() % numberOfElements;
		iterator = beforeCrosingList;
		while (numberOfElements != 0) {
			iterator = iterator->nast;
			numberOfElements--;
		}
		bestAlgoritm = iterator;
		iterator = beforeCrosingList;
		if (iterator == bestAlgoritm) {
			beforeCrosingList = bestAlgoritm->nast;
		}
		else {
			while (iterator->nast != bestAlgoritm)
				iterator = iterator->nast;
			iterator->nast = bestAlgoritm->nast;
		}
		break;
	default:
		std::cout << "\nZly znak rodzaju!\n";
		break;
	}
	bestAlgoritm->nast = nullptr;
	return bestAlgoritm;
}

void Genetics::getBestAlgoritmsList() {
	Zaslepka* lastElement;
	//victories > sum > random
	afterCrosingList = this->getBestAlgoritm('w');
	lastElement = afterCrosingList;
	for (int i = 0; i < 4; i++) {
		lastElement->nast = this->getBestAlgoritm('w');
	}
	for (int i = 0; i < 5; i++) {
		lastElement->nast = this->getBestAlgoritm('z');
	}
	for (int i = 0; i < 3; i++) {
		lastElement->nast = this->getBestAlgoritm('l');
	}
	//now "afterCrossingList" has 13 elements -> but still not crossed
	this->updateBestAlgoritms();
}

Zaslepka* Genetics::getBestVictory() {
	return this->bestVictory;
}
Zaslepka* Genetics::getBestSum() {
	return this->bestSum;
}

void Genetics::updateBestAlgoritms() {
	Zaslepka* iterator = afterCrosingList, *helpIterator = nullptr;
	int zar = iterator->getZarobek();
	if (this->bestVictory->getWygrane() < iterator->getWygrane()) {
		delete this->bestVictory;
		this->bestVictory = new Zaslepka(*iterator);
	}
	iterator = iterator->nast;
	for (int i = 0; i < 5; i++) {
		if (iterator->getZarobek() > zar) {
			zar = iterator->getZarobek();
			helpIterator = iterator;
		}
		iterator = iterator->nast;
	}
	if (zar > this->bestSum->getZarobek()) {
		delete this->bestSum;
		this->bestSum = new Zaslepka(*helpIterator);
	}
}