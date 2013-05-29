#include <new>
using namespace::std;
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setprecision;
using std::fixed;
#include "Cart.h"
#include "Price_List.h"

Cart::Cart( ){
	firstBag = NULL;
}

void Cart::add(string name, double weight, double price){
	if ( weight == 0 ){
		cout << "Empty bag, not added." << endl;
	}
	else{
		bag *pbag = new (nothrow) bag;
		if (pbag == NULL){
			cout << "Out of Memory" << endl;
			return;
		}
		pbag->name = name;
		pbag->weight = weight;
		pbag->price = price;
		pbag->total = (weight * price);
		pbag->next = NULL;
	
		if (firstBag == NULL){
			firstBag = pbag;
		}
		else {
			pbag->next = firstBag;
			firstBag = pbag;
		}
		cout << name << " has been added to your cart." << endl;
	}
}

void Cart::cartFix( ){
	if (firstBag != NULL){
	bag *p;
	bag *pbag;
	p = firstBag;
	while ( p->next != NULL ){
		pbag = p->next;
		delete p;
		p = pbag;
	}
	delete p;
	firstBag = NULL;
	}
}

void Cart::invoice( ) const{
	double youPay;
	youPay = 0;
	bag *pbag;
	pbag  = firstBag;

	while ( pbag != NULL ){
		cout << pbag->name << " Cost per pound: " << pbag->price << " Weight bought: " << pbag->weight << " Cost for item: " << fixed << setprecision(2) <<  pbag->total << endl;
		youPay += pbag->total;
		pbag = pbag->next;
	}
	cout << "Your total: " << fixed << setprecision(2) << youPay << endl;
}

void Cart::checkOut( Price_List* list ){
	bag *qbag;
	qbag = firstBag;

	while ( qbag != NULL ){
		list->getProduct(qbag->name)->amtSold += qbag->weight;
		list->getProduct(qbag->name)->revenue += qbag->total;
		qbag = qbag->next;
	}
	invoice();
	
}
