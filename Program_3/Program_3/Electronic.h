#pragma once

#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

// this child class of electronic is from the parent class product
class Electronic : public Product {
public:

	//defual constructor
	Electronic();

	// sets the warrenty of the prodcut based on the price
	void setWarrenty(int price);

	// gets and returns the warrenty of the product
	int getWarrenty();

	// takes the electronic txt and reads the data from and and assins it to a vector
	bool ReadData(ifstream& foodinFS);

	// takes and output file and outputs the correct info
	void Update(ofstream& outFS);

private:
	
	// uses a vector to store all the elctronics
	int warrenty;
	vector<Electronic> electronicList;
};




