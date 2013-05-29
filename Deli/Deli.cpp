#include "Deli.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include<sstream>

Deli::Deli():scale(Scale()){

	count = 0;
	day = 0;
	numCust = 0;
	numSold = 0;
	revenue = 0;
	int i;
	
	for (i = 0; i < MAX_CUSTOMERS; i++){
		customers[i].setID(11);
	}
}
void Deli::listPrice( ) const{
	priceList.printList( );
}

void Deli::newCustomer(){
	int j;

	if(numCust == MAX_CUSTOMERS){
		cout << "The store is full, wait for someone to leave." << endl;
	}
	else{
		for(j = 1; j < 11; j++){
			if (customers[j-1].getID() == 11){
				customers[j-1].setID(j);
				numCust++;
				cout << "Customer added with assigned ID [" << customers[j-1].getID() << "]" << endl;
				break;
			}
			else {
				continue;
			}
		}
	}	
}
void Deli::setCustomer( int num ){
	char command;
	
	if (customers[num-1].getID() == 11 || num < 1 || num > 10){
		cout << "Customer does not exist.\n\n" << endl;
		return;
	}
	else{
		scale.setCust( &customers[num-1] );
		cout << "Now Serving Customer " << num << endl;
	}
	
	served = num;
	for(;;){
		cout << "What would you like to do Customer " << num << "?" << endl;
		cout << "Buy (R)oast Beef\nBuy (P)astrami\nBuy (S)alami\nBuy Pic(K)les\nBuy (B)lack Olives\nBuy (G)reen Olives\nPrint (I)nvoice\nCheck (O)ut\n(C)ancel/Deselect Customer" << endl;
		cin >> command;
	
		switch ( command ){
			case 'R': product = priceList.getProduct("Roast Beef");
				scale.setProduct( *product );
				break;
			case 'P': product = priceList.getProduct("Pastrami");
				scale.setProduct( *product );
				break;
			case 'S': product = priceList.getProduct("Salami");
				scale.setProduct( *product );
				break;
			case 'K': product = priceList.getProduct("Pickles");
				scale.setProduct( *product );
				break;
			case 'B': product = priceList.getProduct("Black Olives");
				scale.setProduct( *product );
				break;
			case 'G': product = priceList.getProduct("Green Olives");
				scale.setProduct( *product );
				break;
			case 'I': customers[served-1].cart.invoice();
				break;
			case 'O': customers[served-1].cart.checkOut( &priceList );
				return;
			case 'C': customers[served-1].cart.cartFix();
				return;
			default: cout << "Wrong command." << endl;
		}
	}
}

void Deli::listCustomers( ) const{
	int k;
	cout << "Customers in the Deli: " << endl;

	for(k = 0; k < 10; k++){
		if (customers[k].getID() != 11){
			cout << "Customer " << customers[k].getID() << endl;
		}
		else {
			continue;
		}
	}
}

void Deli::checkOut(){
	if (served == 11){
		cout << "No customer." << endl;
	}
	else{
		customers[served-1].cart.cartFix();
		customers[served-1].setID(11);
		cout << "Customer " << served << " has left." << endl;
		served = 11;
		numCust--;
	}
}

void Deli::changePrice( ){
	string name;
	double newPrice;

	cout << "Enter product name: ";
	std::cin.ignore(999999,'\n');
	getline(cin,name);
        
	cout << "Enter new price: ";
        cin >> newPrice;
	if (newPrice < 0){
		cout << "Invalid price." << endl;
	}
	else {
		priceList.setPrice( name, newPrice );
	}
}

void Deli::report( ){
	
	if ( day != count){
		product = priceList.getProduct("Roast Beef");
		cout << "Roast Beef" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();

		product = priceList.getProduct("Pastrami");
		cout << "Pastrami" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();
	
		product = priceList.getProduct("Salami");
		cout << "Salami" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();
		
		product = priceList.getProduct("Pickles");
		cout << "Pickles" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();
		
		product = priceList.getProduct("Black Olives");
		cout << "Black Olives" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();
	
		product = priceList.getProduct("Green Olives");
		cout << "Green Olives" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
		numSold += product->getAmtSold();
		revenue += product->getRevenue();
	
		count++;
		cout << "Total revenue for the day: " << revenue << endl;
	}
	else{
		product = priceList.getProduct("Roast Beef");
		cout << "Roast Beef" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;

		product = priceList.getProduct("Pastrami");
		cout << "Pastrami" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
	
		product = priceList.getProduct("Salami");
		cout << "Salami" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
	
		product = priceList.getProduct("Pickles");
		cout << "Pickles" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
	
		product = priceList.getProduct("Black Olives");
		cout << "Black Olives" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
	
		product = priceList.getProduct("Green Olives");
		cout << "Green Olives" << endl;
		cout << "Weight Sold: " << product->getAmtSold() << "lbs." << endl;
		cout << "Product Revenue: " << product->getRevenue() << endl;
	
		cout << "Total product sold: " << numSold << endl;
		cout << "Total revenue for the day: " << revenue << endl;
	}
}

void Deli::newDay( ){
	int l;

	for(l = 0; l < MAX_CUSTOMERS; l++){
		customers[l].cart.checkOut(&priceList);
		customers[l].cart.cartFix();
		customers[l].setID(11);
	}
	report();
	day++;
	cout << "Day " << day << endl;
	
	count = day - 1;
	numCust = 0;
	numSold = 0;
	revenue = 0;
	served = 11;
	priceList.deFault();
	for(l = 0; l < MAX_PRODUCT; l++){
		priceList.products[l].deFault();
	}
}
