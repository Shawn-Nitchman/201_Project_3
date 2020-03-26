#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Product.h"

// defualt constructor for the class product and sets all varialbes to null or zero
Product::Product()
{
	name = "";
	barCode = 0;
	price = 0.00;
	tax = 0.00;
	discount = 0.00;
}

// this sets both the name and price since every object has to have a name and price
void Product::setProduct(string newName, double newPrice)
{
	name = newName;
	price = newPrice;
}

// this set the barcode for the product
void Product::setBarCode(int newBarCode)
{
	barCode = newBarCode;
}

// this sets the tax for the product
void Product::setTax(double newTax)
{
	tax = newTax;
}

// this sets the discout for the product this takes in how long the item has ben siting on the shelf
// it then sets the discount for how long it has been there. discount is a percentage
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

// this getter returns the name
string Product::getName()
{
	return name;
}

// this getter return the barcode
int Product::getBarCode()
{
	return barCode;
}

// this getter return the price
double Product::getPrice()
{
	return price;
}

// this getter returns the tax
double Product::getTax()
{
	return tax;
}

// this getter returnt the discount
double Product::getDiscount()
{
	return discount;
}

// this method is used to output to a txt file. no product in the stor uses this update since they 
// fit into a child class but if there is a reason to call this it outputs the name, price nad barcode.
void Product::Update(ofstream& outFS)
{
	outFS.open("output.txt");

	outFS << "name: " << name << " price: " << price << " barcode: " << barCode << endl;

	outFS.close();
}