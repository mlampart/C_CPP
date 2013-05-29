#include "Product.h"
#include <iostream>
using std::cout;
using std::endl;

Product::Product(){
	revenue = 0;
	amtSold = 0;
}

void Product::deFault( ){
	revenue = 0;
	amtSold = 0;
}

void Product::setPrice( double p ){
		price = p;
}

string Product::getName( ) const{
	return name;
}

double Product::getPrice( ) const{
	return price;
}

double Product::getRevenue( ) const{
	return revenue;
}

double Product::getAmtSold( ) const{
	return amtSold;
}
