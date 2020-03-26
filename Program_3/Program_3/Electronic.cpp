#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

#include "Electronic.h"

Electronic::Electronic()
{
	warrenty = 0;
}

void Electronic::setWarrenty(int price)
{
	if (price < 200)
		warrenty = 1;
	else if (price >= 200 && price <= 1000)
		warrenty = 3;
	else
		warrenty = 5;
}

int Electronic::getWarrenty()
{
	return warrenty;
}

bool Electronic::ReadData(ifstream& foodinFS)
{
	Electronic currElectronic;

	int barcode;
	string name;
	double price;

	if (!foodinFS.is_open())
		return false;

	while (!foodinFS.eof())
	{
		foodinFS >> barcode >> name >> price;

		currElectronic.Product::setProduct(name, price);
		currElectronic.Product::setBarCode(barcode);
		currElectronic.Product::setTax(0.09);
		currElectronic.setWarrenty(price);

		electronicList.push_back(currElectronic);
	}

	return true;
}

void Electronic::Update(ofstream& outFS)
{
	Electronic currElectronic;
	unsigned int i;

	outFS << "---------------Electronics Inventory---------------" << endl;

	for (i = 0; i < electronicList.size() - 1; i++)
	{
		currElectronic = electronicList.at(i);

		double priceAfterTax = (currElectronic.getPrice() + (currElectronic.getTax() * currElectronic.getPrice()));

		outFS << currElectronic.getName() << " with barcode: " << currElectronic.getBarCode() << " and Price: " << fixed << setprecision(2)
			<< currElectronic.getPrice() <<endl;
		outFS << "Will have a " << currElectronic.getWarrenty() << "  year warranty, and price after taxes is  " << fixed << setprecision(2) 
			<< priceAfterTax << endl;

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