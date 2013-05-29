#include "Scale.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Scale::Scale(){
	scaleWeight = 0;
}

void Scale::setProduct( Product prod ){
	product = prod;
	char command;
	
	for(;;){
		cout << product.name << "\n" << "Add(A), Subtract(S), or add to cart(C)" << endl;
		cin >> command;

		switch( command ){
			case 'A': addWeight();
				cout << "scale weight: " << scaleWeight << endl;
				break;
			case 'S': if( product.weight > getWeight()){
					cout << "nothing to subtract" << endl;
				  }
				else{
					subWeight();
					cout << "scale weight: " << scaleWeight << endl;
				}
				break;
			case 'C': custptr->cart.add( product.name, scaleWeight, product.price );
				zero();
				return;
			default: cout << "wrong command" << endl;
				break;
		}
	}
}

void Scale::addWeight( ){
	scaleWeight += product.weight;
}

void Scale::subWeight( ){
	
	scaleWeight -= product.weight;
	if (scaleWeight < 0){
		zero();
	}
}

void Scale::zero( ){
	scaleWeight = 0;
}

double Scale::getWeight( ) const{
	return scaleWeight;
}

void Scale::setCust( Customer *c ){
	custptr = c;
}
