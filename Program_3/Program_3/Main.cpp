#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Food.h"
#include "Electronic.h"
#include "Product.h"

int menu();


int main()
{
	int userInput = 0;
	char keepGoing = 'n';

	ofstream outFS;
	ifstream inFS;
	

	Food allFood;
	Electronic allElectronic;

	cout << "Welcome to our supermarket" << endl;

	userInput = menu();

	while (userInput != 4)
	{
		cout << "----------------------------------------------------" << endl;

		if (userInput == 1)
		{
			inFS.open("Food.txt");
			outFS.open("output.txt");

			allFood.ReadData(inFS);
			allFood.Update(outFS);

			inFS.close();
			outFS.close();
		}

		else if (userInput == 2)
		{
			inFS.open("Electronics.txt");
			outFS.open("output.txt");

			allElectronic.ReadData(inFS);
			allElectronic.Update(outFS);

			inFS.close();
			outFS.close();
		}

		else if (userInput == 3)
		{
			inFS.open("Food.txt");
			outFS.open("output.txt");

			allFood.ReadData(inFS);
			allFood.Update(outFS);

			inFS.close();
			inFS.open("Electronics.txt");

			allElectronic.ReadData(inFS);
			allElectronic.Update(outFS);

			inFS.close();
			outFS.close();
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