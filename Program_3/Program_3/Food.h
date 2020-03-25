#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class Food : public Product {
public:
	Food();

private:
	string dateProduce;
	int numberOfDays;
};


#endif

