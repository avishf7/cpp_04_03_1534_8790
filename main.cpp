/*
File: main.cpp
Description:
Course: 150018 C++ Workshop, Exercise 4, Question 3
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#include <iostream>
#include <iomanip>
#include "Vector.h"




using namespace std;

// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements
enum MenuOption {
	EXIT_MENU,
	CREATE_VECTOR,
	COMPARE,
	MULTIPLY,
	INSERT,
	INSERT_SUM,
	CLEAR,
	DELETE,
	PRINT,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = PRINT
};

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.
const char* const menuOptionStrings[] = {
	"exit the program",
	"input one vector.",
	"compare v1 and v2.",
	"print the multiples of v1 and v2.",
	"insert v1 to v3.",
	"insert sum of v1 and v2 to v3.",
	"clear a vector.",
	"delete the last value of the vector.",
	"print the all vectors."
};

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;

	int result;
	Vector v1(9), v2(9), v3;

	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		//
		//           0 -- exit
		//           1 -- input one vector.
		//           2 -- compare v1 and v2.
		// etc.
		//
		// The casts are for doing the "++" as an int type since
		// they are not allowed as a MenuOption type.
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;

		int chosenInt;
		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		// After the user has input an int, it is cast to a
		//   MenuOption variable.
		chosen = (MenuOption)chosenInt;


		cout << endl;
		try
		{
			switch (chosen)
			{
			case EXIT_MENU:
				break;
			case CREATE_VECTOR:
				cout << "choose vector(press 1 for v1, press 2 for v2):";
				cin >> chosenInt;

				switch (chosenInt)
				{
				case 1:
					cout << endl;
					cin >> v1;
					break;
				case 2:
					cout << endl;
					cin >> v2;
					break;
				}
				break;
			case COMPARE:
				if (v1 == v2)
					cout << "Equal." << endl;
				else
					cout << "Not equal." << endl;
				break;
			case MULTIPLY:
				result = v1 * v2;
				cout << "v1 * v2 = " << result << endl;
				break;
			case INSERT:
				v3 = v1;
				break;
			case INSERT_SUM:
				v3 = v1 + v2;
				break;
			case CLEAR:
				cout << "choose vector(press 1 for v1, press 2 for v2):";
				cin >> chosenInt;

				switch (chosenInt)
				{
				case 1:
					v1.clear();
					break;
				case 2:
					v2.clear();
					break;
				}
				break;
			case DELETE:
				cout << "choose vector(press 1 for v1, press 2 for v2):";
				cin >> chosenInt;

				switch (chosenInt)
				{
				case 1:
					v1.delLast();
					break;
				case 2:
					v2.delLast();
					break;
				}
				break;
			case PRINT:
				cout << "v1 =" << v1 << endl;
				cout << "v2 =" << v2 << endl;
				cout << "v3 =" << v3 << endl;
				break;
			default:
				cout << "ERROR: worng choice." << endl;
				break;
			}
		}
		catch (const char* str)
		{
			cout << str << endl;
		}

	} while (chosen != EXIT_MENU);

	return 0;
}