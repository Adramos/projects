#ifndef Zaslepka_h
#define Zaslepka_h

class Zaslepka {
private:
	float wygrane;		//why not int? Because we use Wins/numberOfGames
	int zarobek;
public:
	Zaslepka(float wyg, int zar);
	Zaslepka(Zaslepka &copy);
	Zaslepka* nast;
	float getWygrane();
	int getZarobek();
};

#endif 

