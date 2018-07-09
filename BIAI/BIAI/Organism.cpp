#include "Organism.h"

Organism::Organism(float wyg, int zar) {
	this->wygrane = wyg;
	this->zarobek = zar;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 35; j++) {
			this->genotype[j][i] = 0;
		}
	}
	this->nast = nullptr;
}

Organism::Organism(Organism &copy) {
	this->wygrane = copy.wygrane;
	this->zarobek = copy.zarobek;
	this->nast = nullptr;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 35; j++) {
			this->genotype[j][i] = copy.genotype[j][i];
		}
	}
}

void Organism::setGenotypeValue(int i, int j, int value) {
	this->genotype[j][i] = value;
}

int Organism::getGenotypeValue(int i, int j) {
	return this->genotype[j][i];
}

float Organism::getWygrane() {
	return this->wygrane;
}

int Organism::getZarobek() {
	return this->zarobek;
}

/*
	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16		17		18		19		20		21		22		23		24		25		26			27		28		29		30		31		32		33		34
c	20	19	18	17	16	15	14	13	12	11	10	9	8	7	6	5	A-10	A-9		A-8		A-7		A-6		A-5		A-4		A-3		A-2		A-A		10-10		9-9		8-8		7-7		6-6		5-5		4-4		3-3		2-2

	0	1	2	3	4	5	6	7	8	9
r	2	3	4	5	6	7	8	9	10	A


//r <0-9>, c <0-35> -> i == r, j == c
*/

void Organism::AxSituation(std::vector<int> player, std::vector<int> dealer) {
	std::vector<int>::iterator it;
	it = player.begin();
	int otherCard;
	if (*it == 11 || *it == 1) {
		//first card is AS
		it++;
		otherCard = *it;
	}
	else {
		//secound card is AS
		otherCard = *it;
	}
	switch (otherCard) {
	case 2:
		this->column = 24;
		break;
	case 3:
		this->column = 23;
		break;
	case 4:
		this->column = 22;
		break;
	case 5:
		this->column = 21;
		break;
	case 6:
		this->column = 20;
		break;
	case 7:
		this->column = 19;
		break;
	case 8:
		this->column = 18;
		break;
	case 9:
		this->column = 17;
		break;
	case 10:
		this->column = 16;
		break;
	default:
		//AS + AS
		this->column = 25;
		break;
	}

	it = dealer.begin();
	switch (*it) {
	case 2:
		this->row = 0;
		break;
	case 3:
		this->row = 1;
		break;
	case 4:
		this->row = 2;
		break;
	case 5:
		this->row = 3;
		break;
	case 6:
		this->row = 4;
		break;
	case 7:
		this->row = 5;
		break;
	case 8:
		this->row = 6;
		break;
	case 9:
		this->row = 7;
		break;
	case 10:
		this->row = 8;
		break;
	default:
		//AS + x
		this->row = 9;
		break;
	}
}

void Organism::xxSituation(std::vector<int> player, std::vector<int> dealer) {
	std::vector<int>::iterator it;
	it = dealer.begin();
	switch (*it) {
	case 2:
		this->row = 0;
		break;
	case 3:
		this->row = 1;
		break;
	case 4:
		this->row = 2;
		break;
	case 5:
		this->row = 3;
		break;
	case 6:
		this->row = 4;
		break;
	case 7:
		this->row = 5;
		break;
	case 8:
		this->row = 6;
		break;
	case 9:
		this->row = 7;
		break;
	case 10:
		this->row = 8;
		break;
	default:
		//AS + x
		this->row = 9;
		break;
	}

	it = player.begin();
	//both cards are the same, so we could choose only one of them

	switch (*it) {
	case 2:
		this->column = 34;
		break;
	case 3:
		this->column = 33;
		break;
	case 4:
		this->column = 32;
		break;
	case 5:
		this->column = 31;
		break;
	case 6:
		this->column = 30;
		break;
	case 7:
		this->column = 29;
		break;
	case 8:
		this->column = 28;
		break;
	case 9:
		this->column = 27;
		break;
	case 10:
		this->column = 26;
		break;
	default:
		//AS + AS
		this->column = 25;
		break;
	}
}

void Organism::abSituation(std::vector<int> player, std::vector<int> dealer) {
	std::vector<int>::iterator it;
	it = dealer.begin();
	switch (*it) {
	case 2:
		this->row = 0;
		break;
	case 3:
		this->row = 1;
		break;
	case 4:
		this->row = 2;
		break;
	case 5:
		this->row = 3;
		break;
	case 6:
		this->row = 4;
		break;
	case 7:
		this->row = 5;
		break;
	case 8:
		this->row = 6;
		break;
	case 9:
		this->row = 7;
		break;
	case 10:
		this->row = 8;
		break;
	default:
		//AS + x
		this->row = 9;
		break;
	}
	int sum = 0;
	it = player.begin();
	while (it != player.end()) {
		sum += *it;
		it++;
	}

	switch (sum) {
	case 20:
		this->column = 0;
		break;
	case 19:
		this->column = 1;
		break;
	case 18:
		this->column = 2;
		break;
	case 17:
		this->column = 3;
		break;
	case 16:
		this->column = 4;
		break;
	case 15:
		this->column = 5;
		break;
	case 14:
		this->column = 6;
		break;
	case 13:
		this->column = 7;
		break;
	case 12:
		this->column = 8;
		break;
	case 11:
		this->column = 9;
		break;
	case 10:
		this->column = 10;
		break;
	case 9:
		this->column = 11;
		break;
	case 8:
		this->column = 12;
		break;
	case 7:
		this->column = 13;
		break;
	case 6:
		this->column = 14;
		break;
	default:
		this->column = 15;
		break;
	}
}


void Organism::setRCSituation(std::vector<int> player, std::vector<int> dealer) {
	std::vector<int>::iterator it;
	it = player.begin();
	//we have 3 diffrent groups: 2 cards A + x, 2 cards x + x, n cards a + ... + b 
	if (player.size() == 2) {
		this->twoCards = true;
		if (*it == 11 || *it == 1) {
			// A + x
			
			AxSituation(player, dealer);
			//
		}
		else {
			int firstCard = *it;
			it++;
			if (firstCard == *it) {
				//x + x
				xxSituation(player, dealer);
				//
			}
			else if (*it == 11 || *it == 1) {	//secound card could be As as well
				// A + x
				AxSituation(player, dealer);
				//
			}
			else {
				//a + ... + b
				abSituation(player, dealer);
			}
		}
	}
	else {
		//a + ... + b
		this->twoCards = false;
		abSituation(player, dealer);
	}
}