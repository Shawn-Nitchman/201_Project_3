#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class Food : public Product {
public:
	Food();

	void setDateProduce(string newDateProduce);

	void setNumberOfDays(int newNumberOfDays);

	string getDateProduce();

	int getNumberOfDays();

	bool ReadData(ifstream& foodinFS);

	void Update(ofstream& outFS);

private:
	string dateProduce;
	int numberOfDays;
	vector<Food> foodList;
};


#endif

