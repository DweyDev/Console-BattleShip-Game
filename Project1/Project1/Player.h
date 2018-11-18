#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"
#include "Yacht.h"
#include "Submarine.h"
#include "Lit.h"


class Player {
private:
	vector<vector<Lit> > table;
	vector<vector<Lit> > decoy;
	Ship ship;
	Yacht yacht;
	Submarine submarine;

public:

	Ship getShip();
	void setShip(Ship s);
	Yacht getYacht();
	void setYacht(Yacht y);
	Submarine getSubmarine();
	void setSubmarine(Submarine su);

	void createTable();
	void createDecoy();
	void showTable();
	void showDecoy();
	vector<vector<Lit> > getTable();

	//void editOnTable(int row, int column, Lit litera);




	Player();
	~Player();
};