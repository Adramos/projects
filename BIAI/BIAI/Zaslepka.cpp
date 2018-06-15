#include "Zaslepka.h"

Zaslepka::Zaslepka(float wyg, int zar) {
	this->wygrane = wyg,
	this->zarobek = zar,
	this->nast = nullptr;
}

Zaslepka::Zaslepka(Zaslepka &copy) {
	this->wygrane = copy.wygrane;
	this->zarobek = copy.zarobek;
	this->nast = nullptr;
}

float Zaslepka::getWygrane() {
	return this->wygrane;
}

int Zaslepka::getZarobek() {
	return this->zarobek;
}