#ifndef DELI_H
#define DELI_H

#include "Customer.h"
#include "Scale.h"
#include "Product.h"
#include "Cart.h"
#include "Price_List.h"
#include <string>
using std::string;

#define MAX_CUSTOMERS 10

class Deli{

	public:
		Deli( void );
		
		void newCustomer( );
		void setCustomer( int position );
		void checkOut( );
		void changePrice( );
		void report( );
		void newDay( );
		void listCustomers( ) const;
		void listPrice( ) const;
	
	private:
		int count;
		int day;
		int served;
		int numCust;
		int numSold;
		double revenue;
		Customer customers[MAX_CUSTOMERS];
		Scale scale;
		Product *product;
		Price_List priceList;
};

#endif
