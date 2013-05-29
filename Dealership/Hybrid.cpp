#include "Hybrid.h"
#include <iostream>
using std::cout;
using std::endl;

Hybrid::Hybrid( int id, int year, const string &COLOR, int miles, int size, const string &Gas, double pollution, double power, double usage, double bat ):Car( id, year, COLOR, miles, size, Gas, pollution ){
	setMotorPower( power );
	setMotorUsage( usage );
	setBattery( bat );
}

Hybrid::~Hybrid( ){

}

void Hybrid::setMotorPower( double power ){
	motorPower = power;
}

double Hybrid::getMotorPower( ) const{
	return motorPower;
}

void Hybrid::setMotorUsage( double usage ){
	motorUsage = usage;
}

double Hybrid::getMotorUsage( ) const{
	return motorUsage;
}

void Hybrid::setBattery( double bat ){
	battery = ( 0 <= bat <=100 ) ? bat : 100;
}

double Hybrid::getBattery( ) const{
	return battery;
}

void Hybrid::report( ostream &out ) const{

	out << "Hybrid\n";
	Car::report( out );
	out << "Motor power: " << getMotorPower( ) << "\nMotor usage: " << getMotorUsage( ) << "\nBattery power: " << getBattery( ) << endl;
}
