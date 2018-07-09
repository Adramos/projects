#include "Algoritms.h"

Algoritms::Algoritms(int r, int c, int dN){
	this->row = r;
	this->column = c;
	this->decksNumber = dN;
}

//r <0-9>, c <0-35> -> i == r, j == c

int Algoritms::strategicCard(bool twoCards) {		//tab[0][0] => c 20, r2
	int strategicTable[35][10] = { {2,2,2,2,2,2,2,2,2,2},{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 1,1,2,2,2,1,1,1,1,1 },{3,3,3,3,3,3,3,3,3,1},
	{ 3,3,3,3,3,3,3,3,1,1 }, {1,3,3,3,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1},{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{2,3,3,3,3,2,2,1,1,1},{1,3,3,3,3,1,1,1,1,1},{1,1,3,3,3,1,1,1,1,1},
	{ 1,1,3,3,3,1,1,1,1,1 },{ 1,1,1,3,3,1,1,1,1,1 },{ 1,1,1,3,3,1,1,1,1,1 },{4,4,4,4,4,4,4,4,4,4}, {2,2,2,2,2,2,2,2,2,2},{4,4,4,4,4,2,4,4,2,2},{ 4,4,4,4,4,4,4,4,4,4 },{4,4,4,4,4,4,1,1,1,1},{4,4,4,4,4,1,1,1,1,1},{3,3,3,3,3,3,3,3,1,1},{1,1,1,4,4,1,1,1,1,1},{4,4,4,4,4,4,1,1,1,1},{ 4,4,4,4,4,4,1,1,1,1} };
	
	if (strategicTable[this->column][this->row] == 3 && twoCards == false) {
		return 1;
	}
	else {
		return strategicTable[this->column][this->row];
	}
}

int Algoritms::countingCards(bool twoCards) {		//tab[0][0] => c 20, r2
	int strategicTable[35][10] = { { 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 2,2,2,2,2,1,1,1,1,1 },{ 1,1,2,2,2,1,1,1,1,1 },{ 3,3,3,3,3,3,3,3,3,1 },
	{ 3,3,3,3,3,3,3,3,1,1 },{ 1,3,3,3,3,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,3,3,3,3,2,2,1,1,1 },{ 1,3,3,3,3,1,1,1,1,1 },{ 1,1,3,3,3,1,1,1,1,1 },
	{ 1,1,3,3,3,1,1,1,1,1 },{ 1,1,1,3,3,1,1,1,1,1 },{ 1,1,1,3,3,1,1,1,1,1 },{ 4,4,4,4,4,4,4,4,4,4 },{ 2,2,2,2,2,2,2,2,2,2 },{ 4,4,4,4,4,2,4,4,2,2 },{ 4,4,4,4,4,4,4,4,4,4 },{ 4,4,4,4,4,4,1,1,1,1 },{ 4,4,4,4,4,1,1,1,1,1 },{ 3,3,3,3,3,3,3,3,1,1 },{ 1,1,1,4,4,1,1,1,1,1 },{ 4,4,4,4,4,4,1,1,1,1 },{ 4,4,4,4,4,4,1,1,1,1 } };
	
	int changedTable[35][10] = { { 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,2,2,1,1,3,3,1 },{ 2,2,2,2,2,1,1,1,3,1 },{ 1,1,2,2,2,1,1,1,1,1 },{ 1,1,1,1,1,1,1,1,1,1 },{ 3,3,1,1,1,1,1,1,1,1 },{ 3,3,3,3,3,3,3,1,1,3 },
	{ 3,3,3,3,3,3,1,1,3,3 },{ 3,1,1,1,3,3,1,1,1,1 },{ 1,1,3,3,3,1,1,1,1,1 },{ 1,1,3,3,3,1,1,1,1,1 },{ 1,1,3,3,3,1,1,1,1,1 },{ 1,1,3,3,3,1,1,1,1,1 },{ 2,2,2,2,2,2,2,2,2,2 },{ 2,2,2,3,3,2,2,2,2,2 },{ 2,3,3,3,3,2,2,2,2,2 },{ 3,1,3,3,3,2,2,1,1,1 },{ 3,1,3,3,3,1,1,1,1,1 },{ 1,3,1,3,3,1,1,1,1,1 },
	{ 1,1,1,1,3,1,1,1,1,1 },{ 1,1,3,1,1,1,1,1,1,1 },{ 1,1,3,1,1,1,1,1,1,1 },{ 4,4,4,4,4,4,4,4,4,1 },{ 2,2,3,3,3,2,2,2,2,2 },{ 1,1,1,4,4,2,4,4,2,2 },{ 4,4,4,4,4,4,4,4,4,4 },{ 4,4,4,4,4,4,3,1,1,1 },{ 1,1,1,4,4,1,1,1,1,1 },{ 3,3,3,3,3,3,1,1,3,3 },{ 1,1,3,1,1,1,1,1,1,1 },{ 1,1,4,4,4,4,3,1,1,1 },{ 1,4,4,4,4,4,1,1,1,1 } };

	int valueTable[35][10] = { {88,88,88,88,88,88,88,88,88,88},{ 88,88,88,88,88,88,88,88,88,88 } ,{ 88,88,88,88,88,88,88,88,88,88 } ,{ 88,88,88,88,88,88,88,88,88,88 }, {88,88,88,88,88,88,88,5,0,88}, {88,88,88,88,88,88,88,88,4,88}, {-4,-5,88,88,88,88,88,88,88,88}, {-1,-2,-4,-5,-5,88,88,88,88,88},{3,2,-100,-2,-1,88,88,88,88,88}, {88,88,88,88,88,88,88,-5,-5,1}, 
	{88,88,88,88,88,88,-5,-2,4,4},{1,-1,-3,5,8,3,88,88,88,88}, {88,88,5,3,1,88,88,88,88,88},{ 88,88,5,3,1,88,88,88,88,88 },{ 88,88,5,3,1,88,88,88,88,88 },{ 88,88,5,3,1,88,88,88,88,88 },{88,88,88,88,88,88,88,88,88,88},{88,88,88,5,4,88,88,88,88,88},{88,5,3,1,1,88,88,88,88,88}, {0,-3,88,88,88,88,88,88,88,88}, {1,-4,88,88,88,88,88,88,88,88}, {88,4,-3,88,88,88,88,88,88,88}, 
	{88,88,-1,-5,88,88,88,88,88,88}, {88,88,1,-2,-5,88,88,88,88,88}, {88,88,3,-100,-2,88,88,88,88,88}, {88,88,88,88,88,88,88,88,88,-4}, {88,88,6,5,4,88,88,88,88,88},{-3,-4,-6,88,88,88,88,88,88,88}, {88,88,88,88,88,88,88,88,88,88}, {88,88,88,88,88,88,5,88,88,88}, {-2,-2,-5,88,88,88,88,88,88,88}, {88,88,88,88,88,88,-5,-2,4,1}, {88,88,1,-2,-5,88,88,88,88,88}, {-100,-5,88,88,88,88,4,88,88,88}, {-4,88,88,88,88,88,88,88,88,88} };

	
	//wyznaczanie wartoœci prawdziwej! Trzeba zrobiæ jak bêd¹ karty
	int trueValue = 0;
	trueValue = countTrueValue();

	if (valueTable[this->column][this->row] == 88) {
		return strategicTable[this->column][this->row];
	}
	else if (valueTable[this->column][this->row] == -100) {
		if (trueValue <= 0) {
			if (changedTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return changedTable[this->column][this->row];
			}
			
		}
		else {
			if (strategicTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return strategicTable[this->column][this->row];
			}
		}
	}
	else if (valueTable[this->column][this->row] < 0) {
		if (trueValue <= valueTable[this->column][this->row]) {
			if (changedTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return changedTable[this->column][this->row];
			}
		}
		else {
			if (strategicTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return strategicTable[this->column][this->row];
			}
		}
	}
	else {
		if (trueValue >= valueTable[this->column][this->row]) {
			if (changedTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return changedTable[this->column][this->row];
			}
		}
		else {
			if (strategicTable[this->column][this->row] == 3 && twoCards == false) {
				return 1;
			}
			else {
				return strategicTable[this->column][this->row];
			}
		}
	}

	/*
	h+x -> D
	d-x -> H
	st-x -> H
	st+x -> D
	sp-x -> H
	-0 =^= -10
	*/
	
}

int Algoritms::countTrueValue() {		//trzeba dokoñczyæ!
	//we have two vectors: PlayersDeck and DealerDeck
	//both have "Cards" inside. Card value is measure in 
	//Same thing with cards on "graveyard" -> already played and waiting for shuffleing
	std::vector<int>::iterator it;
	int value = 0;
	it = this->graveyard.begin();
	while (it != this->graveyard.end()) {
		if (*it < 7 && *it > 1) {			//2, 3, 4, 5, 6
			value++;
		}
		else if (*it > 9 && *it < 11) {		//10, J, Q, K ->theoreticly could be *it == 10, but there's a chanse that it will have to be rewrite
			value--;
		}
		else if (*it == 11 || *it == 1) {	//A
			value--;
		}

		it++;
	}
	if (this->dealer[0] < 7 && this->dealer[0] > 1) {		//we only know <"see"> first dealer's card
		value++;
	}
	else if (this->dealer[0] > 9 && this->dealer[0] < 11) {
		value--;
	}
	else if (this->dealer[0] == 1 || this->dealer[0] == 11) {
		value--;
	}
	
	it = this->player.begin();
	while (it != this->player.end()) {
		if (*it < 7 && *it > 1) {			//2, 3, 4, 5, 6
			value++;
		}
		else if (*it > 9 && *it < 11) {		//10, J, Q, K ->theoreticly could be *it == 10, but there's a chanse that it will have to be rewrite
			value--;
		}
		else if (*it == 11 || *it == 1) {	//A
			value--;
		}

		it++;
	}

	return value / this->decksNumber;	//we need full values -> 3,75 is for us same as 3, so we're using ' \ ' operator
}

int Algoritms::sameBid(int lastBid) {
	return lastBid;
}

int Algoritms::paroliBid(int firstBid, int lastBid, bool victory) {
	if (victory) {
		return lastBid + (0.2*firstBid);
	}
	else {
		if (lastBid - (0.2*firstBid) <= firstBid) {
			return firstBid;
		}
		else {
			return lastBid - (0.2*firstBid);
		}
	}
}

int Algoritms::countingBid(int firstBid) {
	int trueValue = countTrueValue();
	if (trueValue <= 1) {
		return firstBid;
	}
	else {
		switch (trueValue){
		case 2:
			return firstBid*1.5;
			break;
		case 3: 
			return firstBid * 2;
			break;
		case 4:
			return firstBid*2.5;
			break;
		case 5:
			return firstBid*3;
			break;
		default:
			return firstBid;
			break;
		}
	}
}

int Algoritms::OscarGrrindBid(int firstBid, int lastBid, bool victory, int profit) {
	if (victory) {
		if (profit >= 0) {
			return firstBid;
		}
		else {			
			if (profit+lastBid > firstBid) {
				return firstBid - profit;
			}
			else {
				return lastBid + firstBid;
			}
		}
	}
	else {
		return lastBid;
	}
}