// Shawn Nitchman
// 3/26/2020
// smng47@mail.umkc.edu
// Program 3

#include <iostream>
#include <fstream>
using namespace std;

#include "Food.h"
#include "Electronic.h"
#include "Product.h"

// this function will dispay the menu and return with an int of the user input
int menu();

// this is the main function it displays beginning and ending text it also takes the return of the menu function to go into a loop for the user to choose
// what part of the supermarket they are printing out
int main()
{
	// variables too stay in loops to keep repeating menu
	int userInput = 0;
	char keepGoing = 'n';

	// the program uses three files 2 from input and one output one
	ofstream outFS;
	ifstream inFS;
	
	// Declaring the two groups that are two child classes of parent. since all product is either food or electronic 
	// there is no need declare the parent class of Product
	Food allFood;
	Electronic allElectronic;

	cout << "Welcome to our supermarket" << endl;

	// this goes into the menu function and takes the user input
	userInput = menu();

	// this loop will repeat until the user enters in 4 so that can print off the data they need as many times as possible
	while (userInput != 4)
	{
		cout << "----------------------------------------------------" << endl;

		// if the user enters in 1 it will read the food.txt and display the correct info to an output.txt
		if (userInput == 1)
		{
			// opening both the files
			inFS.open("Food.txt");
			outFS.open("output.txt");

			// ReadData is to read the food document and Update is to print out the correct info
			allFood.ReadData(inFS);
			allFood.Update(outFS);

			// closing both the files
			inFS.close();
			outFS.close();
		}

		// if the user enters in 2 it will read the electronic.txt and display the correct info to an output.txt
		else if (userInput == 2)
		{
			// opening both the files
			inFS.open("Electronics.txt");
			outFS.open("output.txt");

			// ReadData is to read the electroinc document and Update is to print out the correct info
			allElectronic.ReadData(inFS);
			allElectronic.Update(outFS);

			// closing both the files
			inFS.close();
			outFS.close();
		}

		// if the user enters in 3 it will read both the food and electronic files and display the correct info for both
		else if (userInput == 3)
		{
			// opeing the food text and the ouput file
			inFS.open("Food.txt");
			outFS.open("output.txt");

			// reading and outputing the food first
			allFood.ReadData(inFS);
			allFood.Update(outFS);

			// it is now closing the food txt and opening the electronic txt
			inFS.close();
			inFS.open("Electronics.txt");

			//reading and outputing the electronic second
			allElectronic.ReadData(inFS);
			allElectronic.Update(outFS);

			// closing the electronic txt and the output txt
			inFS.close();
			outFS.close();
		}

		// the next few lines are just asking if the user wants to continue and using there input
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

// this funtction display a part of the menu that is outputted. it takes the input and return it to be used in main
int menu()
{
	int choice;

	cout << "Which department do you want to check?" << endl;
	cout << "1- Food" << endl << "2- Electronic" << endl << "3- Both" << endl << "4- Exit" <<endl;
	cout << "Enter in your choice: " << endl;
	
	cin >> choice;

	return choice;
}