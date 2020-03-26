#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

// this is a child class of food from the parent class product
class Food : public Product {
public:

	// defualt contsructor
	Food();

	// this sets the new viaralbe for food of when it was produced
	void setDateProduce(string newDateProduce);

	// this sets the new viaralbe for how long it has been on the shelf
	void setNumberOfDays(int newNumberOfDays);

	// this gets for when the food was produced
	string getDateProduce();

	// this gets for how long it has been on the shelf
	int getNumberOfDays();

	// this function reads from the food.txt file and assigns the new items with the class data
	bool ReadData(ifstream& foodinFS);

	// this function outputs the correct data for food into a txt file
	void Update(ofstream& outFS);

private:
	// datePrpduce is a string since it is a mix of number and charcters. also there is a vector to store all the food
	string dateProduce;
	int numberOfDays;
	vector<Food> foodList;
};


