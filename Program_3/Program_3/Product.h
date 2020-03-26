#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// this is the parent class for all items in the supermarket. this holds the basic info for all products
// all items in the super market will fall into a sub cateagori but all will use this parent class
class Product {
	public:

		// defualt constructor
		Product();

		// sets the product name and price
		void setProduct(string newName, double newPrice);

		// sets the product barcode
		void setBarCode(int newbarCode);

		// sets the tax for the product
		void setTax(double newTax);

		// sets the discount for the product
		void setDiscount(int day);

		// this getter return the name of the product
		string getName();

		// this getter return the barcode of the product
		int getBarCode();

		// this getter returns the price of the product
		double getPrice();

		// this getter returns the tax of the product
		double getTax();

		// this getter returns the discount of the product
		double getDiscount();

		// this function outputs the data from the class into a output.txt file
		void Update(ofstream& outFS);

	// all the descptions of a basic product in a supermarket
	private:
		string name;
		int barCode;
		double price;
		double tax;
		double discount;
};


