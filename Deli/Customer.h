#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Cart.h"

class Customer
{
friend class Scale;
friend class Deli;

public:
	Customer( void );
	void setID( int );
	int getID( ) const;
	
private:
	int ID;
	Cart cart;
};

#endif
