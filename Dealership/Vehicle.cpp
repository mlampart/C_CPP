#include "Vehicle.h"
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::fixed;

Vehicle::Vehicle( int id, int year, const string &COLOR, int miles ){
	setID( id );
	setModelYear( year );
	setColor( COLOR );
	setMileage( miles );
	firstTask = 0;

	taskList = new task[6];	
	
	taskList[0].name = "TuneUp";
	taskList[0].costParts = 6.00;
	taskList[0].costLabor = 15.00;
	taskList[0].next = 0;
	
	taskList[1].name = "OilChange";
	taskList[1].costParts = 20.00;
	taskList[1].costLabor = 7.00;
	taskList[1].next = 0;
	
	taskList[2].name = "WheelAlignment";
	taskList[2].costParts = 10.00;
	taskList[2].costLabor = 30.00;
	taskList[2].next = 0;
	
	taskList[3].name = "TireChange";
	taskList[3].costParts = 30.00;
	taskList[3].costLabor = 10.00;
	taskList[3].next = 0;
	
	taskList[4].name = "WashandVacuum";
	taskList[4].costParts = 6.00;
	taskList[4].costLabor = 17.00;
	taskList[4].next = 0;

	taskList[5].name = "WindowTint";
	taskList[5].costParts = 20.00;
	taskList[5].costLabor = 15.00;
	taskList[5].next = 0;
}

Vehicle::~Vehicle( ){        

	if (firstTask != 0){
		task *t;
		task *ptask;
		t = firstTask;
		while ( t->next != 0 ){
			ptask = t->next;
			delete t;
			t = ptask;
		}
	delete t;
	firstTask = 0;
	}
}

ostream &operator<<( ostream &out, const Vehicle &v ){
	v.report( out );
	return out;
}

void Vehicle::setID( int num ){
	ID = num;
}

int Vehicle::getID( ) const{
	return ID;
}

void Vehicle::setModelYear( int year ){
	modelYear = ( 1990 <= year <= 2012) ? year : 1991;
}

int Vehicle::getModelYear( ) const{
	return modelYear;
}

void Vehicle::setColor( const string &newcolor ){
	color = newcolor;
}

string Vehicle::getColor( ) const{
	return color;
}

void Vehicle::setMileage( int miles ){
	mileage = ( miles <= 0 ) ? miles : 0;
}

int Vehicle::getMileage( ) const{
	return mileage;
}

void Vehicle::assignTask( int num ){
	
	task *ptask = new task;
	ptask->name = taskList[num].name;
	ptask->costParts = taskList[num].costParts;
	ptask->costLabor = taskList[num].costLabor;
	ptask->next = 0;
	
	if( firstTask == 0){
		firstTask = ptask;
	}
	else{
		ptask->next = firstTask;
		firstTask = ptask;
	}
	cout << ptask->name << " HAS BEEN ASSIGNED" << endl;
}

void Vehicle::checkOut( ){
	displayBill( );
}

void Vehicle::report( ostream &out ) const{

	task *ptr;
	ptr = firstTask;
	
	out << "Vehicle ID: " << getID( ) << "\nModel Year: " << getModelYear( ) << "\nColor: " << getColor( ) << "\nMileage: " << getMileage( ) << "\n\nTasks being performed:\n";
	while( ptr != 0 ){
		out << ptr->name << "\n";
		ptr = ptr->next;
	}
}

void Vehicle::displayBill( ) const{

	double cost;
	task *ptr;
	ptr = firstTask;
		
	while( ptr != 0 ){
		cout << ptr->name << "\nCost of parts: " << setprecision(2) << fixed <<  ptr->costParts << "\nCost of labor: " << setprecision(2) << fixed << ptr->costLabor << endl;
		cost = cost + ptr->costParts + ptr->costLabor;
		ptr = ptr->next;
	}
	cout << "Total cost: " << setprecision(2) << fixed << cost << endl;
}
