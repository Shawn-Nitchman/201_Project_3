#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

#include "Electronic.h"

// deufualt constuctor the the child class electronic
Electronic::Electronic()
{
	warrenty = 0;
}

// this sets the warrenty of the product based on price using a simple if else statments
void Electronic::setWarrenty(int price)
{
	if (price < 200)
		warrenty = 1;
	else if (price >= 200 && price <= 1000)
		warrenty = 3;
	else
		warrenty = 5;
}

// this gets and returns the warrenty
int Electronic::getWarrenty()
{
	return warrenty;
}

//this takes the electronics.txt file and reads it and assigs that info into a vector 
bool Electronic::ReadData(ifstream& foodinFS)
{
	Electronic currElectronic;

	int barcode;
	string name;
	double price;

	if (!foodinFS.is_open())
		return false;

	// uses a while loop to read the whole file
	while (!foodinFS.eof())
	{

		//inputs from the file
		foodinFS >> barcode >> name >> price;

		// name, price, and barcode are part of the parent class product so it acess them to set that info
		currElectronic.Product::setProduct(name, price);
		currElectronic.Product::setBarCode(barcode);
		currElectronic.Product::setTax(0.09);
		currElectronic.setWarrenty(price);

		// using a vector to pushback all the info 
		electronicList.push_back(currElectronic);
	}

	return true;
}

// this takes and file to ouput the correct info 
void Electronic::Update(ofstream& outFS)
{
	Electronic currElectronic;
	unsigned int i;

	outFS << "---------------Electronics Inventory---------------" << endl;

	// this for loop goes through the whole vector to ouput the info
	for (i = 0; i < electronicList.size() - 1; i++)
	{

		// assignes currElectonic for each index of the vertex
		currElectronic = electronicList.at(i);

		// using priceAfterTax as a variable since it will be used a lot and dont have to calculate it over and over
		double priceAfterTax = (currElectronic.getPrice() + (currElectronic.getTax() * currElectronic.getPrice()));

		// this ouputs to the txt file using getters 
		outFS << currElectronic.getName() << " with barcode: " << currElectronic.getBarCode() << " and Price: " << fixed << setprecision(2)
			<< currElectronic.getPrice() <<endl;
		outFS << "Will have a " << currElectronic.getWarrenty() << "  year warranty, and price after taxes is  " << fixed << setprecision(2) 
			<< priceAfterTax << endl;

		// based on the warrenty which is based off the price it determines there options to pay for it
		// for monthly payments it is using the compound intrest annually formula to dectermine payments
		if (currElectronic.getWarrenty() == 1)
		{
			outFS << currElectronic.getName() << " has 1 option for payment:" << endl;
			outFS << "1- Cash full Price" << endl;
		}
		else if (currElectronic.getWarrenty() == 3)
		{
			outFS << currElectronic.getName() << " has 2 options for payment:" << endl;
			outFS << "1- Cash full Price" << endl;
			outFS << "2- Pay over 12 months with 1% intrest of " << priceAfterTax << endl;
			outFS << "With monthly payments of $" << fixed << setprecision(2) << (priceAfterTax * (1.01)) / 12 << endl;
		}
		else
		{
			outFS << currElectronic.getName() << " has 2 options for payment:" << endl;
			outFS << "1- Cash full Price" << endl;
			outFS << "2- Pay over 24 months with 1% intrest of " << priceAfterTax << endl;
			outFS << "With monthly payments of $" << fixed << setprecision(2) << (priceAfterTax * ((1.01) * (1.01))) / 24  << endl;
		}

		outFS << "---------------------------------------------------" << endl;
	}
}