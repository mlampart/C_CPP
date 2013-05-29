#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"
#include <string>
using std::string;

class Bus: public Vehicle{

public:
	Bus( int, int, const string &, int, int );
	virtual ~Bus( );

	void setCapacity( int );
	int getCapacity( ) const;

        virtual void report( ostream & ) const;
private:
	int capacity;
};

#endif
