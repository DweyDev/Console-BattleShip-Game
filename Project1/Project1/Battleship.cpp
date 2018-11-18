#include <iostream>
#include "Battleship.h"
#include "Lit.h"
Battleship::Battleship() {

}

Battleship::~Battleship() {


}


Battleship::Battleship(const vector<int>positions, const vector<int>sunkInPositions, const int sunks) {
	int i;
	for (i = 0; i < positions.size(); i++)
		this->positions.push_back(positions[i]);

	for (i = 0; i < sunkInPositions.size(); i++)
		this->sunkInPositions.push_back(sunkInPositions[i]);

		this->sunks = sunks;

}
vector<int> Battleship::getPositions() {

	return this->positions;

}

void Battleship::addPosition(int position) {

	this->positions.push_back(position);
}

int Battleship::getLen() {

	return this->positions.size();
}


void Battleship::addSunkIP(int len) {
	while (len != 0){
		int a = 0;
		sunkInPositions.push_back(a);
		len--;
	}
}

/*vector<int> Battleship::getSunkIP() {
	return this->getSunkIP;
}
*/
void Battleship::editSunkIP(int index) {

	this->sunkInPositions[index] = 1;
}

void Battleship::increaseSunks() {
	this->sunks++;
}
int Battleship::getSunks() {
	return this->sunks;
}