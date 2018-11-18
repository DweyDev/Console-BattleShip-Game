#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() {

}

Player::~Player() {


}


Ship Player::getShip() {
	return this->ship;
}

void Player::setShip(Ship s) {
	this->ship = s;
}

Yacht Player::getYacht() {
	return this->yacht;
}

void Player::setYacht(Yacht y) {
	this->yacht = y;
}

Submarine Player::getSubmarine() {
	return this->submarine;
}

void Player::setSubmarine(Submarine su) {
	this->submarine = su;
}

void Player::createTable() {

	char *string = "ABCDEFGHI";
	Lit litera;

	for (int i = 0; i < 9; i++) {
		vector<Lit> row;
		for (int j = 0; j < 9; j++) {
			litera.setFirst(string[i]);
			litera.setSecond(string[j]);
			row.push_back(litera);
		}
		table.push_back(row);
	}

}

void Player::showTable() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << table[i][j].getFirst() << table[i][j].getSecond() << ' ';
		}
		cout <<char(' \ ')<<"        " <<endl;
	}

	cout << endl << endl << endl << endl;
}
void Player::createDecoy() {

	char *string = "ABCDEFGHI";
	Lit litera;

	for (int i = 0; i < 9; i++) {
		vector<Lit> row;
		for (int j = 0; j < 9; j++) {
			litera.setFirst(string[i]);
			litera.setSecond(string[j]);
			row.push_back(litera);
		}
		decoy.push_back(row);
	}

}
void Player::showDecoy() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << decoy[i][j].getFirst() << decoy[i][j].getSecond() << ' ';
		}
		cout << endl;
	}
}

vector<vector<Lit> > Player::getTable() {
	return this->table;
}

/*void Player::editOnTable(int row, int column, Lit litera) {

	this->table[row][column]
}*/