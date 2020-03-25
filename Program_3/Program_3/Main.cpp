#include <iostream>
//#include <fstream>
using namespace std;

#include "Food.h"
#include "Electronic.h"
#include "Product.h"

int menu();


int main()
{
	int userInput = 0;
	char keepGoing = 'n';

	cout << "Welcome to our supermarket" << endl;

	userInput = menu();

	while (userInput != 4)
	{
		cout << "----------------------------------------------------" << endl;

		if (userInput == 1)
		{
			cout << "entered in 1" << endl;
		}
		else if (userInput == 2)
		{
			cout << "entered in 2" << endl;
		}
		else if (userInput == 3)
		{
			cout << "entered in 3" << endl;
		}

		cout << "Back to main menu? [y: yes | n: no]: ";
		cin >> keepGoing;

		if (toupper(keepGoing) == 'N')
			break;

		else
			userInput = menu();
	}

	cout << "Thank you for using the supermarket application" << endl;

	return 0;
}

int menu()
{
	int choice;

	cout << "Which department do you want to check?" << endl;
	cout << "1- Food" << endl << "2- Electronic" << endl << "3- Both" << endl << "4- Exit" <<endl;
	cout << "Enter in your choice: " << endl;
	
	cin >> choice;

	return choice;
}