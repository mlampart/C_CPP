#include "Car.h"
#include <iostream>
using std::cout;
using std::endl;

Car::Car( int id, int year, const string &COLOR, int miles, int engSize, const string &Gas, double pollution ):Vehicle( id, year, COLOR, miles ){
	setEngineSize( engSize );
	setPollutionLevel( pollution );
	setGas( Gas );
}

Car::~Car( ){

}

void Car::setEngineSize( int size ){
	engineSize = size;
}

int Car::getEngineSize( ) const{
	return engineSize;
}

void Car::setPollutionLevel( double level ){
	pollutionLevel = level;
}

double Car::getPollutionLevel( ) const{
	return pollutionLevel;
}

void Car::setGas( const string &newgas ){
	currentGas = ( newgas.compare("Regular") == 0 || newgas.compare("Plus") == 0 || newgas.compare("Premium") == 0 ) ? newgas : "Regular";
}

string Car::getGas( ) const{
	return currentGas;
}

void Car::report( ostream &out ) const{

	out << "Car\n";
	Vehicle::report( out );
	
	out << "Additional information:" << "\nEngine size: " << getEngineSize( ) << "\nGas type: " << getGas( ) << "\nPollution level: " << getPollutionLevel( ) << endl;
}
