#include <iostream>
#include <string>
#include "Genetics.h"

int main() {
	std::string tekst;
	std::cout << "\nHello. Please choose how many generations you want to test: \n";
	std::cin >> tekst;
	int numberOfGenerations = 0;
	numberOfGenerations = std::stoi(tekst);

	while (numberOfGenerations <= 0) {
		std::cout << "\nPlease choose number highter then 0: \n";
		std::cin >> tekst;
		numberOfGenerations = std::stoi(tekst);
	}

	std::cout << "\nPlease be patient, it could take a while.\n";



}

/*
1)Choosing how many generations we're going to test						DONE
2)Prepering basic algoritms
3) =Loop=
4)Play 1000 times for evety organism
5)Check which organisms are best
6)Cross them
7)Repete =Loop= until reaching generations number
8)Show resualts
*/