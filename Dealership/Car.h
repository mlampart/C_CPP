#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <string>
using std::string;

class Car: public Vehicle{

public:
	Car( int, int, const string &, int, int, const string &, double );
	virtual ~Car( );
	void setEngineSize( int );	
	int getEngineSize( ) const;

	void setGas( const string& );
	string getGas( ) const;

	void setPollutionLevel( double );
	double getPollutionLevel( ) const;	

        virtual void report( ostream & ) const;

private:
	int engineSize;
	double pollutionLevel;
	string currentGas;
};

#endif
