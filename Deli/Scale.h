#ifndef SCALE_H
#define SCALE_H
#include "Product.h"
#include "Customer.h"
#include "Price_List.h"
#include <string>
using std::string;

class Scale 
{
public:
	Scale( );
	
	void addWeight( );
	void subWeight( );
	
	void setCust( Customer *cust );
	void setProduct( Product prod );

	double getWeight( ) const;
	void zero( );
	
private:
	Product product;
	Customer *custptr;
	double scaleWeight;
};

#endif
