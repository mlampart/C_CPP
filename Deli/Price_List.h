#ifndef PRICELIST_H
#define PRICELIST_H
#include "Product.h"
#include <string>
using std::string;

#define MAX_PRODUCT 6

class Price_List{
public:
	Price_List( void );
	
	void setPrice( string name, double price );
	double getPrice( string name ) const;

	void deFault( );
	Product* getProduct( string name );
	void printList( ) const;
	Product products[MAX_PRODUCT];
private:
};

#endif
