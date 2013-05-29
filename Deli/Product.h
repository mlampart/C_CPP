#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>
using std::string;

class Product{

friend class Scale;
friend class Cart;
friend class Price_List;

public:
	Product( void );

	string getName( ) const;	
	double getWeight( ) const;
	double getRevenue( ) const;
	double getPrice( ) const;
	double getAmtSold( ) const;

	void setPrice( double );
	void deFault( );	
private:
	string name;
	double weight;
	double price;
	double revenue;
	double amtSold;
};

#endif
