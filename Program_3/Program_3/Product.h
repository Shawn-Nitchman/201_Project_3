#pragma once
#ifndef PRODUCT_H
#define PRODCUT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
	public:

		Product();

		void setProduct(string newName, double newPrice);

		void setBarCode(int newbarCode);

		void setTax(double newTax);

		void setDiscount(double discount);


	private:
		string name;
		int barCode;
		double price;
		double tax;
		double discount;
};

#endif

