#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

#include "Food.h"

Food::Food()
{
	dateProduce = "";
	numberOfDays = 0;
}

void Food::setDateProduce(string newDateProduce)
{
	dateProduce = newDateProduce;
}

void Food::setNumberOfDays(int newNumberOfDays)
{
	numberOfDays = newNumberOfDays;
}

string Food::getDateProduce()
{
	return dateProduce;
}

int Food::getNumberOfDays()
{
	return numberOfDays;
}

bool Food::ReadData(ifstream& foodinFS)
{
	Food currFood;

	int barcode, day;
	string name, date;
	double price;

	if (!foodinFS.is_open())
		return false;

	while (!foodinFS.eof())
	{
		foodinFS >> barcode >> name >> price >> date >> day;

		currFood.Product::setProduct(name, price);
		currFood.Product::setBarCode(barcode);
		currFood.setDateProduce(date);
		currFood.setNumberOfDays(day);
		currFood.setDiscount(day);

		foodList.push_back(currFood);
	}

	return true;
}

void Food::Update(ofstream& outFS)
{
	Food currFood;
	unsigned int i;
	int daysOld = 0;

	outFS << "----------------Food Inventory---------------------" << endl;

	for (i = 0; i < foodList.size() - 1; i++)
	{
		currFood = foodList.at(i);

		outFS << currFood.getName() << " with barcode: " << currFood.getBarCode() << endl;
		outFS << "It's Price = " << currFood.getPrice() << " and was produced on " << currFood.getDateProduce() << endl;

		daysOld = currFood.getNumberOfDays();

		if (daysOld < 10)
			outFS << currFood.getName() << " is not on sale" << endl;
		else if (daysOld >= 10 && daysOld <= 14)
			outFS << currFood.getName() << " is 20% off, current price is " << fixed << setprecision(2) << (currFood.getPrice() - (currFood.getPrice() * currFood.getDiscount())) <<endl;
		else if (daysOld >= 15 && daysOld <= 30)
			outFS << currFood.getName() << " is 50% off, current price is " << fixed << setprecision(2) << (currFood.getPrice() - (currFood.getPrice() * currFood.getDiscount())) << endl;
		else 
			outFS << currFood.getName() << " is 80% off, current price is " << fixed << setprecision(2) << (currFood.getPrice() - (currFood.getPrice() * currFood.getDiscount())) << endl;

		outFS << "---------------------------------------------------" << endl;
	}

}

