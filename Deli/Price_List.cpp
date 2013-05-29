#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;

#include "Price_List.h"


Price_List::Price_List( void ){

    products[0].setPrice(9.95);
    products[0].weight = .15;
    products[0].name = "Roast Beef";
    products[1].setPrice(10.25);
    products[1].weight = .15;
    products[1].name = "Pastrami";
    products[2].setPrice(8.75);
    products[2].weight = .15;
    products[2].name = "Salami";
    products[3].setPrice(4.95);
    products[3].weight = .1;
    products[3].name = "Pickles";
    products[4].setPrice(4.49);
    products[4].weight = .1;
    products[4].name = "Black Olives";
    products[5].setPrice(4.55);
    products[5].weight = .1;
    products[5].name = "Green Olives";

}

void Price_List::deFault(){
    products[0].setPrice(9.95);
    products[1].setPrice(10.25);
    products[2].setPrice(8.75);
    products[3].setPrice(4.95);
    products[4].setPrice(4.49);
    products[5].setPrice(4.55);
}

void Price_List::printList() const{
	int m;

	for ( m = 0; m < MAX_PRODUCT; m++){
		cout << products[m].getName() << " " << fixed << setprecision(2) <<  products[m].getPrice() << "\n" << endl;
	}
}
	
void Price_List::setPrice( string name, double d ){

	if( name.compare("Roast Beef") == 0 ){
		products[0].setPrice( d );
	}
	else if( name.compare("Pastrami") == 0 ){
		products[1].setPrice( d );
	}
	else if( name.compare("Salami") == 0 ){
		products[2].setPrice( d );
	}
	else if( name.compare("Pickles") == 0 ){
		products[3].setPrice( d );
	}
	else if( name.compare("Black Olives") == 0 ){
		products[4].setPrice( d );
	}
	else if( name.compare("Green Olives") == 0){
		products[5].setPrice( d );
	}
	else{
		cout << "Wrong item name" << endl;
	}	
}

double Price_List::getPrice( string name ) const{

	if( name.compare("Roast Beef") == 0 ){
		return products[0].getPrice( );
	}
	else if( name.compare("Pastrami") == 0 ){
		return products[1].getPrice( );
	}
	else if( name.compare("Salami") == 0 ){
		return products[2].getPrice( );
	}
	else if( name.compare("Pickles") == 0 ){
		return products[3].getPrice( );
	}
	else if( name.compare("Black Olives") == 0 ){
		return products[4].getPrice( );
	}
	else if( name.compare("Green Olives") == 0){
		return products[5].getPrice( );
	}
}

Product* Price_List::getProduct( string name ){

	if( name.compare( "Roast Beef" ) == 0 ){
		return &products[0];
	}
	else if( name.compare("Pastrami") ==0 ){
		return &products[1];
	}
	else if( name.compare("Salami") ==0 ){
		return &products[2];
	}
	else if( name.compare("Pickles") ==0 ){
		return &products[3];
	}
	else if( name.compare("Black Olives") ==0 ){
		return &products[4];
	}
	else if( name.compare("Green Olives") ==0 ){
		return &products[5];
	}
}
