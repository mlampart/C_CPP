#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Vehicle{
	friend ostream &operator<<( ostream &, const Vehicle & );

public:
	typedef struct dummytask{
		string name;
		double costParts;
		double costLabor;
		dummytask *next;
	}task;
	

	Vehicle( int , int , const string & , int );
	virtual ~Vehicle( );

	void setID( int );
	int getID( ) const;

	void setModelYear( int );
	int getModelYear( ) const;

	void setColor( const string & );
	string getColor( ) const;
	
	void setMileage( int );
	int getMileage( ) const;
	
	void assignTask( int );
	
	void checkOut( );

	virtual void report( ostream & ) const;

	void displayBill( ) const;
private:
	int ID;
	int modelYear;
	string color;
	int mileage;
	task *taskList;
	task *firstTask;
	string name;	
};

#endif
