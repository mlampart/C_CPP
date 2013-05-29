#include "Bus.h"
#include <iostream>
using std::cout;
using std::endl;

Bus::Bus( int id, int year, const string &COLOR, int miles, int Capacity ):Vehicle( id, year, COLOR, miles ){
	setCapacity( Capacity );
}

Bus::~Bus( ){ 

}

void Bus::setCapacity( int cap ){
	capacity = cap;
}

int Bus::getCapacity( ) const{
	return capacity;
}

void Bus::report( ostream &out ) const{
	
	out << "Bus\n";
	Vehicle::report( out );
	out << "Additional information" << "\nBus capacity: " << getCapacity( ) << endl;
}
