#include "Motorcycle.h"
#include <iostream>
using std::cout;
using std::endl;

Motorcycle::Motorcycle( int id, int year, const string &COLOR, int miles, int size, int front, int back ):Vehicle( id, year, COLOR, miles ){

	setEngineSize( size );
	setFrontSize( front );
	setBackSize( back );
}

Motorcycle::~Motorcycle( ){
	
}

void Motorcycle::setEngineSize( int size ){
	engineSize = size;
}

int Motorcycle::getEngineSize( ) const{
	return engineSize;
}

void Motorcycle::setFrontSize( int front ){
	frontSize = front;
}

int Motorcycle::getFrontSize( ) const{
	return frontSize;
}

void Motorcycle::setBackSize( int back ){
	backSize = back;
}

int Motorcycle::getBackSize( ) const{
	return backSize;
}

void Motorcycle::report( ostream &out ) const{
	
	out << "Motorcycle\n";
	Vehicle::report( out );
	out << "Additional information:" << "\nEngine size: " << getEngineSize( ) << "\nFront wheel size: " << getFrontSize( ) << "\nBack wheel size: " << getBackSize( ) << endl;
}
