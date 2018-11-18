#pragma once
#include <iostream>

#include "Player.h"


class Controller {

private:
	Player playerOne;
	Player playerTwo;
public:

	void editOnTable(char row, char column, Player p, char c, char type);
	Ship createShip(vector<Lit>coords);
	Yacht createYacht(vector<Lit>coords);
	Submarine createSub(vector<Lit>coords);

	Controller(Player, Player);
	Controller();

};