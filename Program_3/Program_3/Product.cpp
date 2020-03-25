#include <iostream>
#include <string>
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

void Product::setDiscount(double newDiscount)
{
	discount = newDiscount;
}
