#pragma once
#include "Controller.h"

class UI {
private:
	Controller controller;
	void showMenu();
public:
	UI(Controller controller);
	void run();


};