#ifndef CART_H
#define CART_H
#include "Product.h"
#include "Price_List.h"

#include <string>
using std::string;

class Cart
{
public:
	typedef struct dummybag{
		string name;
		double weight;
		double price;
		double total;
		dummybag *next;
	}bag;

	Cart( void );
	
	
	void add( string name, double weight, double price );
	void cartFix( );
	void invoice( ) const;
	
	void checkOut( Price_List* p );
		
private:
	bag *firstBag;
};

#endif
