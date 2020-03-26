#pragma once
#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Electronic : public Product {
public:
	Electronic();

	void setWarrenty(int price);

	int getWarrenty();

	bool ReadData(ifstream& foodinFS);

	void Update(ofstream& outFS);

private:
	int warrenty;
	vector<Electronic> electronicList;
};

#endif



