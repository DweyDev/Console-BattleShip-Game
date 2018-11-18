#include "UI.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


UI::UI(Controller controller) {
	this->controller = controller;
}



void UI::showMenu() {

	cout << "B A T T L E S H I P " << "          " << "G A M ME" << endl;
	cout << endl << endl << endl << endl;
	cout << "PLAYER 1 - UMAN" << endl;
	cout << "PLAYER 2 - PC" << endl;
	cout << "PLAYER 1 in stanga, PLAYER 2 in dreapta" << endl;
	cout << "Fiecare player va avea 3 barcute: 1 ship, 1 yacht, 1 submarine" << endl;

}

void UI::run() {
	showMenu();
	int running = 1;
	srand(time(NULL)); // initialize the RNG


	while (running == 1) {
		int totalP1 = 0, totalP2 = 0;
		//setari Player 1    
		//presupunem ca playerul uman alege corect coordonatele pe tabla de joc
		Player player1;
		player1.createTable();
		player1.createDecoy();
		cout << "Preparare Player 1" << endl;
		cout << "Creare SHIP" << endl;
		vector <Lit> coordsShip;
		int contor = 0;
		/*Lit pseudo; char a = 'z'; pseudo.setFirst(a); pseudo.setSecond(a);
		for (contor = 0; contor < 5; contor++)
			coordsShip.push_back(pseudo);*/
		int len = 5;
		for (int i = 0; i < len; i++) {
			char first, second;
			cout << "Row: " << endl; cin >> first;
			cout << "Column: " << endl; cin >> second;
			Lit litera;
			litera.setFirst(first);
			litera.setSecond(second);
			coordsShip.push_back(litera);
		}
		/*cout << "Coordonate Ship: ";
		int k = 0;
		for (k = 0; k < coordsShip.size(); k++) {
			cout << coordsShip[k].getFirst()<<coordsShip[k].getSecond()<< ' ';
		}*/
		Ship saux;

		saux = controller.createShip(coordsShip);
		player1.setShip(saux);



		/*int k = 0;
		for (k = 1; k <= coordsShip.size(); k++) {
			cout << player1.getShip().getPositions()[k] << ' ';
		}*/
		//cout << endl;

		cout << "Creare YACHT" << endl;
		vector<Lit>coordsYacht;
		for (int i = 0; i < 3; i++) {
			char first, second;
			cout << "Row: " << endl; cin >> first;
			cout << "Column: " << endl; cin >> second;
			Lit litera;
			litera.setFirst(first);
			litera.setSecond(second);
			coordsYacht.push_back(litera);
		}
		Yacht yaux;
		yaux = controller.createYacht(coordsYacht);
		player1.setYacht(yaux);

		cout << "Creare SUBMARINE" << endl;
		vector<Lit>coordsSub;
		for (int i = 0; i < 2; i++) {
			char first, second;
			cout << "Row: " << endl; cin >> first;
			cout << "Column: " << endl; cin >> second;
			Lit litera;
			litera.setFirst(first);
			litera.setSecond(second);
			coordsSub.push_back(litera);
		}

		Submarine suaux;

		suaux = controller.createSub(coordsSub);
		player1.setSubmarine(suaux);

		//setari Player 2, care va trebui sa fie random
		Player player2;
		player2.createTable();
		player2.createDecoy();

		cout << "Barcile SHIP, YACHT si SUBMARINE alea Playerului 2 vor fi create aleatoriu" << endl;
		vector<Lit>coordsShip2;
		vector<Lit>coordsYacht2;
		vector<Lit>coordsSub2;
		vector<Lit>total;
		vector<int>verificare;
		int i = 0, j = 0;
		//create coords for Ship
		bool gen = false;
		char *string = "ABCDEFGHI";


		while (!gen) {
			int cord = rand() % 89 + 11;
			if ((cord / 10 - 2) >= 1 && (cord / 10 + 2) <= 9) {

				gen = true;
				Lit litera;
				char first = string[cord / 10 - 2];
				char second = string[cord % 10];
				litera.setFirst(first); litera.setSecond(second);
				coordsShip2.push_back(litera);
				total.push_back(litera);
				verificare.push_back((cord / 10 - 2) * 10 + cord % 10);

				first = string[cord / 10 - 1];
				second = string[cord % 10];
				litera.setFirst(first); litera.setSecond(second);
				total.push_back(litera);
				coordsShip2.push_back(litera);
				verificare.push_back((cord / 10 - 1) * 10 + cord % 10);

				first = string[cord / 10];
				second = string[cord % 10];
				litera.setFirst(first); litera.setSecond(second);
				total.push_back(litera);
				coordsShip2.push_back(litera);
				verificare.push_back((cord / 10) * 10 + cord % 10);

				first = string[cord / 10 + 1];
				second = string[cord % 10];
				litera.setFirst(first); litera.setSecond(second);
				total.push_back(litera);
				coordsShip2.push_back(litera);
				verificare.push_back((cord / 10 + 1) * 10 + cord % 10);

				first = string[cord / 10 + 1];
				second = string[cord % 10];
				litera.setFirst(first); litera.setSecond(second);
				total.push_back(litera);
				coordsShip2.push_back(litera);
				verificare.push_back((cord / 10 + 2) * 10 + cord % 10);

			}
		}
		//create coords for Yacht
		gen = false;
		//int i;
		while (!gen) {
			int cord = rand() % 89 + 11;
			if ((cord / 10 - 1) >= 1 && (cord / 10 + 1) <= 9) {

				bool found = false;
				for (i = 0; i < verificare.size(); i++) {
					if ((cord == verificare[i]) || (((cord / 10 * 10 - 1) + cord % 10) == verificare[i]) || (((cord / 10 * 10 + 1) + cord % 10) == verificare[i]))
						found = true;
				}
				if (!found) {
					gen = true;

					Lit litera;
					char first = string[cord / 10 - 1];
					char second = string[cord % 10];
					litera.setFirst(first); litera.setSecond(second);
					coordsYacht2.push_back(litera);
					total.push_back(litera);
					verificare.push_back((cord / 10 - 1) * 10 + cord % 10);

					first = string[cord / 10];
					second = string[cord % 10];
					litera.setFirst(first); litera.setSecond(second);
					coordsYacht2.push_back(litera);
					total.push_back(litera);
					verificare.push_back((cord / 10) * 10 + cord % 10);

					first = string[cord / 10 + 1];
					second = string[cord % 10];
					litera.setFirst(first); litera.setSecond(second);
					coordsYacht2.push_back(litera);
					total.push_back(litera);
					verificare.push_back((cord / 10 + 1) * 10 + cord % 10);

				}
			}
		}
		//create coords for Submarine
		gen = false;
		while (!gen) {
			//int j = 0;
			int cord = rand() % 89 + 11;
			if ((cord / 10 - 1) >= 1) {

				bool found = false;
				//cout << "random= " << cord << endl;
				//cout << "SIZE" << verificare.size();
				for (j = 0; j < 8; j++) {
					//cout << "for j= " << j << ' ';
					if ((cord == verificare[j]) || (((cord / 10 * 10 - 1) + cord % 10) == verificare[j])) {
						found = true;
						//cout << "if j= " << j << ' ';
						//continue;
					}
				}

				if (!found) {
					gen = true;

					Lit litera;
					char first = string[cord / 10 - 1];
					char second = string[cord % 10];
					litera.setFirst(first); litera.setSecond(second);
					coordsSub2.push_back(litera);
					total.push_back(litera);
					verificare.push_back((cord / 10 - 1) * 10 + cord % 10);

					first = string[cord / 10];
					second = string[cord % 10];
					litera.setFirst(first); litera.setSecond(second);
					coordsSub2.push_back(litera);
					total.push_back(litera);
					verificare.push_back((cord / 10) * 10 + cord % 10);


				}
			}
		}

	

		//Ship p2;
		//p2 = controller.createShip()
		//mi-ar trebui un setShip pentru Player
		Ship saux2; Yacht yaux2; Submarine suaux2;

		saux2 = controller.createShip(coordsSub2);
		player2.setShip(saux2);
		yaux2 = controller.createYacht(coordsYacht2);
		player2.setYacht(yaux2);
		suaux2 = controller.createSub(coordsSub2);
		player2.setSubmarine(suaux2);


		while (totalP1 != 10 && totalP2 != 10) {
			cout << "Player 1" << endl;
			player1.showTable();

			cout << "Player 2" << endl;
			player2.showTable();
			cout << endl << endl << endl;
			int round = 1; // daca e 1, da player 1, daca e -1, da player 2
			if (round == 1) {

				cout << "Ataca Player 1" << endl;
				Lit atac; char first, second;
				cout << "Row: "; cin >> first; atac.setFirst(first);
				cout << "Column: "; cin >> second; atac.setSecond(second);
				int index1=0, index2=0;
				char *string = "XABCDFEFGHI";
				char c = 'O';
				char type = 'O';
				int i = 1;
				for (i=1; i < 10; i++) {
					if (string[i] == first)
						index1 = i;
					if (string[i] == second)
						index2 = i;
				}
				int coord = 0;
				coord = index1 * 10 + index2;
				i = 0;
				//DE AICI SE TAIE FIRUL PROGRAMULUI
				for (i = 0; i < player2.getShip().getPositions().size(); i++) {
					if (coord = player2.getShip().getPositions()[i]) {
						type = 'x';
						c = 'L';
						totalP2 += player2.getShip().getSunks();
						cout << "Player 1 a nimerit " << totalP2 << "parti de barca" << endl;
					}
				}
				for (i = 0; i < player2.getYacht().getPositions().size(); i++) {
					if (coord = player2.getYacht().getPositions()[i]) {
						type = 'y';
						c = 'L';
						totalP2 += player2.getYacht().getSunks();
						cout << "Player 1 a nimerit " << totalP2<< "parti de barca" << endl;
					}
				}
				for (i = 0; i < player2.getSubmarine().getPositions().size(); i++) {
					if (coord = player2.getSubmarine().getPositions()[i]) {
						type = 'z';
						c = 'L';
						totalP2 += player2.getSubmarine().getSunks();
						cout << "Player 1 a nimerit " << totalP2 << "parti de barca" << endl;
					}
				}

				controller.editOnTable(first, second, player2,c, type);



				round *= -1;
			}//end if round 1
			else {
				cout << "Ataca Player 2" << endl;
				char c = 'O';
				char type = 'O';
				int coord = rand() % 89 + 11;
				char first, second;
				char *string = "XABCDEFGHI";
				first = string[coord / 10];
				second = string[coord % 10];
				for (int i = 0; i < player2.getShip().getPositions().size(); i++) {
					if (coord = player1.getShip().getPositions()[i]) {
						type = 'x';
						c = 'L';
						totalP1 += player1.getShip().getSunks();
						cout << "Player 1 a nimerit " << totalP1 << "parti de barca" << endl;
					}
				}
				for (int i = 0; i < player1.getYacht().getPositions().size(); i++) {
					if (coord = player1.getYacht().getPositions()[i]) {
						type = 'y';
						c = 'L';
						totalP1 += player1.getYacht().getSunks();
						cout << "Player 1 a nimerit " << totalP1 << "parti de barca" << endl;
					}
				}
				for (int i = 0; i < player1.getSubmarine().getPositions().size(); i++) {
					if (coord = player1.getSubmarine().getPositions()[i]) {
						type = 'z';
						c = 'L';
						totalP1 += player1.getSubmarine().getSunks();
						cout << "Player 1 a nimerit " << totalP1 << "parti de barca" << endl;
					}
				}

				controller.editOnTable(first, second, player1, c, type);



				round *= -1;
			}//end else round -1





		}

		if (totalP1 == 10)
			cout << "Player 2 castiga !" << endl;
		else
			cout << "Player 1 castiga !" << endl;



		cout << "Doriti sa mai jucati ?" << endl;
		cout << "Da: -> 1 " << "     " << "Nu: -> 0" << endl;
		cin >> running;
	}












}