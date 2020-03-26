#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Product.h"

Product::Product()
{
	name = "";
	barCode = 0;
	price = 0.00;
	tax = 0.00;
	discount = 0.00;
}


void Product::setProduct(string newName, double newPrice)
{
	name = newName;
	price = newPrice;
}

void Product::setBarCode(int newBarCode)
{
	barCode = newBarCode;
}

void Product::setTax(double newTax)
{
	tax = newTax;
}

void Product::setDiscount(int day)
{
	if (day < 10)
		discount = 0.00;

	else if (day >= 10 && day <= 14)
		discount = 0.20;

	else if (day >= 15 && day <= 30)
		discount = 0.50;

	else
		discount = 0.80;
}

string Product::getName()
{
	return name;
}

int Product::getBarCode()
{
	return barCode;
}

double Product::getPrice()
{
	return price;
}

double Product::getTax()
{
	return tax;
}

double Product::getDiscount()
{
	return discount;
}

void Product::Update(ofstream& outFS)
{
	outFS.open("output.txt");

	outFS << name << " " << price;

	outFS.close();
}