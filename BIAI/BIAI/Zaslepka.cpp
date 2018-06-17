#include "Zaslepka.h"

Zaslepka::Zaslepka(float wyg, int zar) {
	this->wygrane = wyg;
	this->zarobek = zar;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 35; j++) {
			this->genotype[j][i] = 0;
		}
	}
	this->nast = nullptr;
}

Zaslepka::Zaslepka(Zaslepka &copy) {
	this->wygrane = copy.wygrane;
	this->zarobek = copy.zarobek;
	this->nast = nullptr;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 35; j++) {
			this->genotype[j][i] = copy.genotype[j][i];
		}
	}
}

void Zaslepka::setGenotypeValue(int i, int j, int value) {
	this->genotype[j][i] = value;
}

int Zaslepka::getGenotypeValue(int i, int j) {
	return this->genotype[j][i];
}

float Zaslepka::getWygrane() {
	return this->wygrane;
}

int Zaslepka::getZarobek() {
	return this->zarobek;
}