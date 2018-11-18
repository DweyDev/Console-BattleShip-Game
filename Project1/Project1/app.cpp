#include <iostream>
#include "UI.h"
#include "Controller.h"

using namespace std;


int main() {

	Controller controller = Controller();
	UI ui = UI(controller);
	ui.run();
	return 0;
}