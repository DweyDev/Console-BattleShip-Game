#include <iostream>
#include "Controller.h"





void Controller::editOnTable(char row, char column, Player p, char c, char type) {

	char *string2 = "XABCDEFGHI";
	int index1=0, index2=0;


	for (int i = 1; i < 10; i++) {
		if (string2[i] == row)
			index1 = i;
		if (string2[i] == column)
			index2 = i;
	}

	//cand apelez functia edit, deja stiu daca e lovitura sau nu
	//si in ce tip de barca e
	if (c == 'O' && type == 'O') {
		char o = 'O';
		p.getTable()[index1][index2].setFirst(o);
		p.getTable()[index1][index2].setSecond(o);
	}
	else {
		//adica daca c == 'X', de la lovit
		char x = 'X';
		//editarea in tabela playerului
		p.getTable()[index1][index2].setFirst(x);
		p.getTable()[index1][index2].setSecond(x);

		//cautare in cele 3 barci de tip ship, yacht si submarine
		//cresterea totalului de sunks
		//modificare index in vector de sunk
		char *string = "XABCDEFGHI";

		if (type == 'x') {
			int index = -1;
			for (int i = 0; i < p.getShip().getPositions().size(); i++) {
				if (row == string[p.getShip().getPositions()[i] / 10] && string[p.getShip().getPositions()[i] % 10] == column)
					index = i;
			}
			if (index != -1) {
				//p.getShip().getSunkIP()[index]++;
				p.getShip().increaseSunks();
			}
		}
		if (type == 'y') {
			int index = -1;
			for (int i = 0; i < p.getYacht().getPositions().size(); i++) {
				if (row == string[p.getYacht().getPositions()[i] / 10] && string[p.getYacht().getPositions()[i] % 10] == column)
					index = i;
			}
			if (index != -1) {
				//p.getYacht().getSunkIP()[index]++;
				p.getYacht().increaseSunks();
			}
		}
		if (type == 'z') {
			int index = -1;
			for (int i = 0; i < p.getSubmarine().getPositions().size(); i++) {
				if (row == string[p.getSubmarine().getPositions()[i] / 10] && string[p.getSubmarine().getPositions()[i] % 10] == column)
					index = i;
			}
			if (index != -1) {
				//p.getSubmarine().getSunkIP()[index]++;
				p.getSubmarine().increaseSunks();
			}
		}
	}
	}


//Ship Controller::createShip(vector<Lit>coords, Player player)
Ship Controller::createShip(vector<Lit>coords) {

	
	char *string = "XABCDEFGHI";
	int index1=0, index2=0;

	Ship saux;
	for (int i = 0; i < coords.size(); i++) { // in loc de coords size e 5
		char a = coords[i].getFirst();
		char b = coords[i].getSecond();
		for (int j = 1; j < 10; j++) {
			if (a == string[j])
				index1 = j;
			if (b == string[j])
				index2 = j;
		}
		//tre` sa incerc manual cu push_back in loc de addPosition
		//player.getShip().addPosition(index1 * 10 + index2);
		saux.addPosition(index1 * 10 + index2);
		saux.addSunkIP(saux.getLen());
	}
	return saux;
	//player.getShip().addSunkIP(player.getShip().getLen());


}

Yacht Controller :: createYacht(vector<Lit>coords) {
	char *string = "XABCDEFGHI";
	int index1=0, index2=0;

	Yacht yaux;

	for (int i = 0; i < coords.size(); i++) {
		char a = coords[i].getFirst();
		char b = coords[i].getSecond();
		for (int j = 1; j < 10; j++) {
			if (a == string[j])
				index1 = j;
			if (b == string[j])
				index2 = j;
		}
		yaux.addPosition(index1 * 10 + index2);
		yaux.addSunkIP(yaux.getLen());
		//player.getYacht().addPosition(index1 * 10 + index2);
	}
	return yaux;
	//player.getYacht().addSunkIP(player.getYacht().getLen());


}

Submarine Controller::createSub(vector<Lit>coords) {

	char *string = "XABCDEFGHI";
	int index1=0, index2=0;

	Submarine suaux;

	for (int i = 0; i < coords.size(); i++) {
		char a = coords[i].getFirst();
		char b = coords[i].getSecond();
		for (int j = 1; j < 10; j++) {
			if (a == string[j])
				index1 = j;
			if (b == string[j])
				index2 = j;
		}
		suaux.addPosition(index1 * 10 + index2);
		suaux.addSunkIP(suaux.getLen());
		//player.getSubmarine().addPosition(index1 * 10 + index2);
	}
	return suaux;
	//player.getSubmarine().addSunkIP(player.getSubmarine().getLen());

}

Controller::Controller() {
	this->playerOne = Player();
	this->playerTwo = Player();	}



Controller::Controller(Player p1, Player p2) {
	this->playerOne = p1;
	this->playerTwo = p2;
}