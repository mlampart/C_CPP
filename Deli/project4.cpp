#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
using std::setfill;
using std::setprecision;
#include <string>
using std::string;

#include "Deli.h"
#include "Customer.h"
#include "Product.h"
#include "Price_List.h"
#include "Cart.h"
#include "Scale.h"

int main(){
	char command;
	Deli deli;
	int custID;
	string name;
	double newPrice;

	cout << "Welcome to Mike's Deli Simulator" << endl;
	deli.newDay();
	cout << endl;
	
	for(;;){
	 deli.listPrice( );
	 cout << "(Q)uit\n(A)dd Customer\n(S)erve Customer\n(C)hange Price\nCheck(O)ut\n(R)eport\n(N)ew Day" << endl;
	 cout << "What would you like to do?  ";
	 cin >> command;
	 switch( command ){
		case 'Q': cout << "end" << endl;
			return 0;
		case 'A': deli.newCustomer();
			break;
		case 'S': deli.listCustomers();
			cout << "Enter customer ID: " << endl;
			cin >> custID;
			deli.setCustomer( custID );
			break;
		case 'C': deli.changePrice();
			break;
		case 'O': deli.checkOut();
			break;
		case 'R': deli.report();
			break;
		case 'N': deli.newDay();
			break;
		default: cout << "Wrong command, try again" << endl;
	 }
	}
}

