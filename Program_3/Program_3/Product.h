#pragma once
#ifndef PRODUCT_H
#define PRODCUT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Product {
	public:

		Product();

		void setProduct(string newName, double newPrice);

		void setBarCode(int newbarCode);

		void setTax(double newTax);

		void setDiscount(int day);

		string getName();

		int getBarCode();

		double getPrice();

		double getTax();

		double getDiscount();

		void Update(ofstream& outFS);


	private:
		string name;
		int barCode;
		double price;
		double tax;
		double discount;
};

#endif

