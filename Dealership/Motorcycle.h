#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"
#include <string>
using std::string;

class Motorcycle: public Vehicle{

public:
	Motorcycle( int, int, const string &, int, int, int, int );
	virtual ~Motorcycle( );
	
	void setEngineSize( int );
	int getEngineSize( ) const;

	void setFrontSize( int );
	int getFrontSize( ) const;

	void setBackSize( int );
	int getBackSize( ) const;	

        virtual void report( ostream & ) const;
private:
	int engineSize;
	int frontSize;
	int backSize;
};

#endif
