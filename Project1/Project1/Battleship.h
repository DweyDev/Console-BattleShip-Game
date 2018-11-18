#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Battleship {

private:
	vector<int>positions;
	vector<int>sunkInPositions;
	int sunks = 0;
public:
	vector<int>getPositions();
	void addPosition(int position);
	int getLen();

	void addSunkIP(int len); //voi adauga 0-uri initial
	//vector<int>getSunkIP();
	void editSunkIP(int index);

	void increaseSunks();
	int getSunks();

	Battleship(const vector<int>positions, const vector<int>sunkInPositions, const int sunks);
	Battleship();
	~Battleship();


};