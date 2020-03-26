#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

#include "Food.h"

// defualt constructor for the child class food setting everything to null and zero
Food::Food()
{
	dateProduce = "";
	numberOfDays = 0;
}

// sets the data producced
void Food::setDateProduce(string newDateProduce)
{
	dateProduce = newDateProduce;
}

// sets how long the food has been on the shelf
void Food::setNumberOfDays(int newNumberOfDays)
{
	numberOfDays = newNumberOfDays;
}

// gets and return when it was producted
string Food::getDateProduce()
{
	return dateProduce;
}

// gets and return when it was producted
int Food::getNumberOfDays()
{
	return numberOfDays;
}

//this function takes the input file and assigns the food in the txt to the vector and store all the info it needs
bool Food::ReadData(ifstream& foodinFS)
{
	Food currFood;

	int barcode, day;
	string name, date;
	double price;

	if (!foodinFS.is_open())
		return false;

	// this while loop will read the whole file
	while (!foodinFS.eof())
	{
		// takes input from file
		foodinFS >> barcode >> name >> price >> date >> day;

		// takes the info from the txt and assisgnes them to the correct class.
		// name, price, and barcode are part of the parent class so it calls the parent class
		currFood.Product::setProduct(name, price);
		currFood.Product::setBarCode(barcode);
		currFood.setDateProduce(date);
		currFood.setNumberOfDays(day);
		currFood.setDiscount(day);

		// this is adding this info to a vector and continueing on with it reading
		foodList.push_back(currFood);
	}

	return true;
}

// this function takes an txt file and then outputs to it
void Food::Update(ofstream& outFS)
{
	Food currFood;
	unsigned int i;
	int daysOld = 0;

	outFS << "----------------Food Inventory---------------------" << endl;

	// this for loop will go though the food vector at each index
	for (i = 0; i < foodList.size() - 1; i++)
	{
		// assinging currfood for each index of the vector so i can output the info
		currFood = foodList.at(i);

		// this is just outputing simple info to the file and using getters to the the info needed.
		outFS << currFood.getName() << " with barcode: " << currFood.getBarCode() << endl;
		outFS << "It's Price = " << currFood.getPrice() << " and was produced on " << currFood.getDateProduce() << endl;

		// using days old as a variable so it does not have to get it every time when used below
		daysOld = currFood.getNumberOfDays();

		// based on how old the product is a certain discout is added and these if statment decied with discout goes for how old it is
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

