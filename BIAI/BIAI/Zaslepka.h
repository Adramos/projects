#ifndef Zaslepka_h
#define Zaslepka_h

class Zaslepka {
private:
	float wygrane;		//why not int? Because we use Wins/numberOfGames
	int zarobek;
	int genotype[35][10];
public:
	Zaslepka(float wyg, int zar);
	Zaslepka(Zaslepka &copy);
	Zaslepka* nast;
	float getWygrane();
	int getZarobek();
	void setGenotypeValue(int i, int j, int value);
	int getGenotypeValue(int i, int j);
};

#endif 

