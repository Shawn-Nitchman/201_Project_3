#pragma once
#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class Electronic : public Product {
public:
	Electronic();

private:
	int warrenty;
};


#endif



