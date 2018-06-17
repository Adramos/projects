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
	if (beforeCrosingList != nullptr) {
		ElementOfList = this->beforeCrosingList;
		while (ElementOfList->nast != nullptr) {
			nextElement = ElementOfList->nast;
			delete ElementOfList;
			ElementOfList = nextElement;
		}
		delete ElementOfList;
	}
	if (afterCrosingList != nullptr) {
		ElementOfList = this->afterCrosingList;
		while (ElementOfList->nast != nullptr) {
			nextElement = ElementOfList->nast;
			delete ElementOfList;
			ElementOfList = nextElement;
		}
		delete ElementOfList;
	}

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

Zaslepka* Genetics::crossSingleAlgoritm(Zaslepka* first, Zaslepka* secound, int chanseToMutate) {		//returns two-member LIST of algoritms (not single valuse!)
	srand(time(NULL));
	int howManyParts = 2 + (rand() % 5);
	int startingPoint, endPoint, pointHolder, jBeg, jEnd, kBeg, kEnd, jMut, kMut, valueMut;
	Zaslepka* newAlgoritmFirst = new Zaslepka(*first);
	Zaslepka* newAlgoritmSecound = new Zaslepka(*secound);
	for (int i = 0; i < howManyParts; i++) {
		startingPoint = rand() % 349;
		endPoint = rand() % 349;
		while (startingPoint == endPoint)
			endPoint = rand() % 349;
		if (endPoint < startingPoint) {
			pointHolder = endPoint;
			endPoint = startingPoint;
			startingPoint = pointHolder;
		}
		jBeg = jEnd = kBeg = kEnd = 0;								//j <0-9>, k <0-34> -> here
		while (startingPoint - 35 >= 0) {							//Algoritm -> [j][i] -> i <0-9>, j <0-34>
			jBeg++;													// i == j
			startingPoint = startingPoint - 35;						// j == k
		}															//methode(i,j,...) = methode(j,k,...)
		kBeg = startingPoint;
		while (endPoint - 35 >= 0) {
			jEnd++;
			endPoint = endPoint - 35;
		}
		kEnd = endPoint;
		if (i == 0) {
			for (int j = jBeg; j <= jEnd; j++) {
				if (j == jBeg && j == jEnd) {
					for (int k = kBeg; k <= kEnd; k++) {
						newAlgoritmFirst->setGenotypeValue(j, k, secound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, first->getGenotypeValue(j, k));						
					}
				}
				else if (j == jBeg && j != jEnd) {
					for (int k = kBeg; k < 10; k++) {
						newAlgoritmFirst->setGenotypeValue(j, k, secound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, first->getGenotypeValue(j, k));
					}
				}
				else if (j == jEnd) {
					for (int k = 0; k <= kEnd; k++) {
						newAlgoritmFirst->setGenotypeValue(j, k, secound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, first->getGenotypeValue(j, k));
					}
				}
				else {
					for (int k = 0; k < 10; k++) {
						newAlgoritmFirst->setGenotypeValue(j, k, secound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, first->getGenotypeValue(j, k));
					}
				}

			}
		}
		else {
			for (int j = jBeg; j <= jEnd; j++) {
				if (j == jBeg && j == jEnd) {
					for (int k = kBeg; k <= kEnd; k++) {
						pointHolder = newAlgoritmFirst->getGenotypeValue(j, k);
						newAlgoritmFirst->setGenotypeValue(j, k, newAlgoritmSecound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, pointHolder);
					}
				}
				else if (j == jBeg && j != jEnd) {
					for (int k = kBeg; k < 10; k++) {
						pointHolder = newAlgoritmFirst->getGenotypeValue(j, k);
						newAlgoritmFirst->setGenotypeValue(j, k, newAlgoritmSecound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, pointHolder);
					}
				}
				else if (j == jEnd) {
					for (int k = 0; k <= kEnd; k++) {
						pointHolder = newAlgoritmFirst->getGenotypeValue(j, k);
						newAlgoritmFirst->setGenotypeValue(j, k, newAlgoritmSecound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, pointHolder);
					}
				}
				else {
					for (int k = 0; k < 10; k++) {
						pointHolder = newAlgoritmFirst->getGenotypeValue(j, k);
						newAlgoritmFirst->setGenotypeValue(j, k, newAlgoritmSecound->getGenotypeValue(j, k));
						newAlgoritmSecound->setGenotypeValue(j, k, pointHolder);
					}
				}

			}
		}
	}

	//mutating
	if (chanseToMutate >= rand() % 100) {
		jMut = rand() % 10;
		kMut = rand() % 35;
		valueMut = rand() % numberOfAlgoritsm;
		newAlgoritmFirst->setGenotypeValue(jMut, kMut, valueMut);
		newAlgoritmSecound->setGenotypeValue(jMut, kMut, valueMut);
	}

	newAlgoritmFirst->nast = newAlgoritmSecound;
	return newAlgoritmFirst;
}


void Genetics::crossAllAlgoritms(int mutationChance) {	//it removes basic values from "afterCrossingList" -> replace them with new algoritms	
	Zaslepka* listHolder = afterCrosingList;
	afterCrosingList = nullptr;
	Zaslepka* algoritmIterator = listHolder;
	Zaslepka* algoritmHolder = listHolder->nast;
	Zaslepka* lastAfterCrossingElement = nullptr;
	bool first = true;

	while (algoritmIterator->nast != nullptr) {
		while (algoritmHolder != nullptr) {
			if (first) {
				afterCrosingList = crossSingleAlgoritm(algoritmIterator, algoritmHolder, mutationChance);
				lastAfterCrossingElement = afterCrosingList->nast;
			}
			else {
				lastAfterCrossingElement->nast = crossSingleAlgoritm(algoritmIterator, algoritmHolder, mutationChance);
				lastAfterCrossingElement = lastAfterCrossingElement->nast->nast;
			}
			algoritmHolder = algoritmHolder->nast;
		}
		algoritmIterator = algoritmIterator->nast;
		algoritmHolder = algoritmIterator->nast;
	}
	algoritmIterator = listHolder;
	listHolder = nullptr;
	while (algoritmIterator != nullptr) {
		algoritmHolder = algoritmIterator;
		algoritmIterator = algoritmIterator->nast;
		delete algoritmHolder;
	}
}