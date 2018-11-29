#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification

/*Constants used during the calculation*/
#define g 3.7
#define c 0.13
#define a 8.3
#define vmax 46
void runSimulation() {
	/*Variable declaration*/
	double userSelectedBurnValue, burnReserve;
	double minutes, seconds, milSeconds;
	double speedOfDescent, heightAboveSurface;
	double initTime = GetTickCount();

	char keyPressed = NULL;
	bool keyPressedFlag = false;
	int bounces;
	/*Variable initialization*/
	userSelectedBurnValue = speedOfDescent = 0;
	minutes = seconds = milSeconds = bounces = 0;
	burnReserve = 100.00;
	heightAboveSurface = 1000.000;
	while (1) {
		Sleep(25);
		milSeconds = GetTickCount() - initTime;
		if (milSeconds >= 999) {
			/* Incrementing seconds by one and setting initTime i.e milSecond to zero*/
			seconds++;
			initTime = GetTickCount();
		}
		/* Incrementing minutes when seconds equal to 60*/
		if (seconds == 60) {
			minutes++;
			seconds = 0;
		}
		system("CLS");
		cout << endl;
		cout << "******************** STARTING DESCENT ********************" << endl;
		if (_kbhit()) {
			keyPressed = _getch();
			if (keyPressed == 'w') {
				keyPressedFlag = true;
				userSelectedBurnValue++;
			}
			else if (keyPressed == 'e') {
				keyPressedFlag = true;
				if(userSelectedBurnValue > 0)
				userSelectedBurnValue--;
			}
		}
		if (keyPressed != NULL)
		{
			if (keyPressed == 'w') {
				cout << keyPressed << " was pressed - increase burn";
			}
			else if (keyPressed == 'e') {
				cout << keyPressed << " was pressed - reduce burn";
			}
		}
		cout << ": BURN = " << userSelectedBurnValue << "; BURN RESERVE = " << burnReserve << endl;
		cout << "MINUTE = " << minutes << "; SECOND = " << seconds << "; MILLIESECOND = " << milSeconds << endl;
		cout << "SPEED OF DESCENT = " << speedOfDescent << endl;
		cout << "HEIGHT ABOVE MARTIAN SURFACE = " << heightAboveSurface << "metres" << endl;
		cout << "NUMBER OF BOUNCES = " << bounces << endl;
		cout << endl << endl;
	}
}

void main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool running = true;
	int choice;
	while (running == true) {
		cout << "*****RUN THE SIMULATION*****" << endl;
		cout << "1. Run The Simulation" << endl;
		cout << "2. Quit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: 
			runSimulation();
			break;
		case 2:
			running = false;
			break;
		}
	}
}
