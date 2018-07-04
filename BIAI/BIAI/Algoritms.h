#ifndef Algoritms_h
#define Algoritms_h

class Algoritms {
private:
	int row;
	int column;
	int decksNumber;
	//cards on board
	//carts in graveyard
public:
	Algoritms(int r, int c, int dN);		//r <0-9>, c <0-35> -> i == r, j == c 
	int countTrueValue();

	//game algoritms
	int strategicCard();
	int countingCards();
	//algorytm w³asny


	//bet algoritms
	int sameBid(int lastBid);
	int paroliBid(int firstBid, int lastBid, bool victory);
	int countingBid(int firstBid);
	int OscarGrrindBid(int firstBid, int lastBid, bool victory, int profit);	//przy pora¿ce zmniejsszamy profit o sumê zak³adu, przy zwyciêstwie-analogicznie <uwaga: POZA algorytmem -> w programie g³ównym>

};

#endif


/*
hit = 1, //1
stand,	//2
doubleDown,		//3
split,	// 4 //
insurance	// 5 //


HELP
	 r	20	19	18	17	16	15	14	13	12	11	10	9	8	7	6	5`	A-10	A-9		A-8		A-7		A-6		A-5		A-4		A-3		A-2		A-A		10-10		9-9		8-8		7-7		6-6	`	5-5		4-4		3-3		2-2
 c
2		ST	ST	ST	ST	ST	ST	ST	ST	H	D	D	H	H	H	H	H	ST		ST		ST		ST		H		H		H		H		H		SP		ST			SP		SP		SP		SP		D		H		SP		SP
3		ST	ST	ST	ST	ST	ST	ST	ST	H	D	D	D	H	H	H	H	ST		ST		ST		D		D		H		H		H		H		SP		ST			SP		SP		SP		SP		D		H		SP		SP
4		ST	ST	ST	ST	ST	ST	ST	ST	ST	D	D	D	H	H	H	H	ST		ST		ST		D		D		D		D		H		H		SP		ST			SP		SP		SP		SP		D		H		SP		SP
5		ST	ST	ST	ST	ST	ST	ST	ST	ST	D	D	D	H	H	H	H	ST		ST		ST		D		D		D		D		D		D		SP		ST			SP		SP		SP		SP		D		SP		SP		SP
6		ST	ST	ST	ST	ST	ST	ST	ST	ST	D	D	D	H	H	H	H	ST		ST		ST		D		D		D		D		D		D		SP		ST			SP		SP		SP		SP		D		SP		SP		SP
7		ST	ST	ST	ST	H	H	H	H	H	D	D	H	H	H	H	H	ST		ST		ST		ST		H		H		H		H		H		SP		ST			ST		SP		SP		H		D		H		SP		SP
8		ST	ST	ST	ST	H	H	H	H	H	D	D	H	H	H	H	H	ST		ST		ST		ST		H		H		H		H		H		SP		ST			SP		SP		H		H		D		H		H		H
9		ST	ST	ST	ST	H	H	H	H	H	D	D	H	H	H	H	H	ST		ST		ST		H		H		H		H		H		H		SP		ST			SP		SP		H		H		D		H		H		H
10		ST	ST	ST	ST	H	H	H	H	H	D	H	H	H	H	H	H	ST		ST		ST		H		H		H		H		H		H		SP		ST			ST		SP		H		H		H		H		H		H
A		ST	ST	ST	ST	H	H	H	H	H	H	H	H	H	H	H	H	ST		ST		ST		H		H		H		H		H		H		SP		ST			ST		SP		H		H		H		H		H		H
*/