#ifndef HYBRID_H
#define HYBRID_H
#include "Car.h"
#include <string>
using std::string;

class Hybrid: public Car{

public:
	Hybrid( int, int, const string &, int, int, const string &, double, double, double, double );
	virtual ~Hybrid( );

	void setMotorPower( double );
	double getMotorPower( ) const;

	void setMotorUsage( double );
	double getMotorUsage( ) const;

	void setBattery( double );
	double getBattery( ) const;	

        virtual void report( ostream & ) const;

private:
	double motorPower;
	double motorUsage;
	double battery;
};

#endif
