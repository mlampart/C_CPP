#include "MLH.h"
#include "MLH_Node.h"
#include "Vehicle.h"
#include "Car.h"
#include "Hybrid.h"
#include "Bus.h"
#include "Motorcycle.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::fixed;

#include <string>
using std::string;

int main(){

	MLH<Vehicle> *center;
	center = new MLH<Vehicle>;
	Vehicle *v;
	char command, option, tasknum;
	int id, year, miles, size, front, back, cap;
	string color, gas;
	double level, power, usage, battery;
	center->MLH_set_print_option( 1 );

	cout << "WELCOME TO MIKE'S SERVICE CENTER" << endl;
	for(;;) {
		cout << "MAIN MENU\n\n[1] Enter a vehicle\n[2] Check out a vehicle\n[3] Print a vehicle's record\n[4] Report\n[5] Access an existing vehicle\n[Q]Quit\nWhat would you like to do?  ";
	cin >> command;
         switch( command ){
		case '1': cout << "Which vehicle would you like to add?\n[1]Car\n[2]Hybrid\n[3]Motorcycle\n[4]Bus\n[B]Back\nEnter choice:  ";
			  cout << *center;

			  cin >> option;
			  switch( option ){
				case '1': cout << "Enter vehicle ID:  ";
					cin >> id;
					while( center->MLH_get( id ) != 0 ){
						cout << "VEHICLE WITH THIS ID EXISTS ALREADY, AUTO CHANGE ID TO ID+1" << endl;
						id++;
					}
					cout << "Enter model year (1990-2012):  ";
					cin >> year;
					cout << "Enter color:  ";
					cin >> color;
					cout << "Enter current mileage:  ";
					cin >> miles;
					cout << "Enter engine size (cc):  ";
					cin >> size;
					cout << "Enter gas type (Regular, Plus, Premium):  ";
					cin >> gas;
					cout << "Enter pollution level:  ";
					cin >> level;
					v = new Car( id, year, color, miles, size, gas, level );
					
					cout << "What task should we perform on your vehicle?\n[0]TuneUp\n[1]OilChange\n[2]WheelAlignment\n[3]TireChange\n[4]WashandVacuum\n[5]WindowTint\n[B]ack\n";
					while( tasknum != 'B' ){
					cin >> tasknum;
					switch( tasknum ){
						case '0': v->assignTask( 0 );
							break;
						case '1': v->assignTask( 1 );
							break;
						case '2': v->assignTask( 2 );
							break;
						case '3': v->assignTask( 3 );
							break;
						case '4': v->assignTask( 4 );
							break;
						case '5': v->assignTask( 5 );
							break;
						case 'B':
							break;
        				        default: cout << "Wrong command, try again" << endl;
					}
					}
					tasknum = ' ';
					center->MLH_insert( id, v );
					cout << "Inserted a Car with ID [" << id << "]" << endl;
					break;
				case '2': cout << "Enter vehicle ID:  ";
					cin >> id;
					while( center->MLH_get( id ) != 0 ){
						cout << "VEHICLE WITH THIS ID EXISTS ALREADY, AUTO CHANGE ID TO ID+1" << endl;
						id++;
					}
					cout << "Enter model year (1990-2012):  ";
					cin >> year;
					cout << "Enter color:  ";
					cin >> color;
					cout << "Enter current mileage:  ";
					cin >> miles;
					cout << "Enter engine size (cc):  ";
					cin >> size;
					cout << "Enter gas type (Regular, Plus, Premium):  ";
					cin >> gas;
					cout << "Enter pollution level:  ";
					cin >> level;
					cout << "Enter motor power:  ";
					cin >> power;
					cout << "Enter motor usage:  ";
					cin >> usage;
					cout << "Enter battery power (%):  ";
					cin >> battery;
					v = new Hybrid( id, year, color, miles, size, gas, level, power, usage, battery );
					
					cout << "What task should we perform on your vehicle?\n[0]TuneUp\n[1]OilChange\n[2]WheelAlignment\n[3]TireChange\n[4]WashandVacuum\n[5]WindowTint\n[B]ack\n";
					while( tasknum != 'B' ){
					cin >> tasknum;
					switch( tasknum ){
						case '0': v->assignTask( 0 );
							break;
						case '1': v->assignTask( 1 );
							break;
						case '2': v->assignTask( 2 );
							break;
						case '3': v->assignTask( 3 );
							break;
						case '4': v->assignTask( 4 );
							break;
						case '5': v->assignTask( 5 );
							break;
						case 'B':
							break;
        				        default: cout << "Wrong command, try again" << endl;
					}
					}
					tasknum = ' ';
					center->MLH_insert( id, v );
					cout << "Inserted a Hybrid with ID [" << id << "]" << endl;
					break;
				case '3': cout << "Enter vehicle ID:  "; 
					cin >> id;
					while( center->MLH_get( id ) != 0 ){
						cout << "VEHICLE WITH THIS ID EXISTS ALREADY, AUTO CHANGE ID TO ID+1" << endl;
						id++;
					}
					cout << "Enter model year (1990-2012):  ";
					cin >> year;
					cout << "Enter color:  ";
					cin >> color;
					cout << "Enter current mileage:  ";
					cin >> miles;
					cout << "Enter engine size (cc):  ";
					cin >> size;
					cout << "Enter front wheel size:  ";
					cin >> front;
					cout << "Enter back wheel size:  ";
					cin >> back;
					v = new Motorcycle( id, year, color, miles, size, front, back );
					
					cout << "What task should we perform on your vehicle?\n[0]TuneUp\n[1]OilChange\n[2]WheelAlignment\n[3]TireChange\n[4]WashandVacuum\n[5]WindowTint\n[B]ack\n";
					while( tasknum != 'B' ){
					cin >> tasknum;
					switch( tasknum ){
						case '0': v->assignTask( 0 );
							break;
						case '1': v->assignTask( 1 );
							break;
						case '2': v->assignTask( 2 );
							break;
						case '3': v->assignTask( 3 );
							break;
						case '4': v->assignTask( 4 );
							break;
						case '5': v->assignTask( 5 );
							break;
						case 'B':
							break;
        				        default: cout << "Wrong command, try again" << endl;
					}
					}
					center->MLH_insert( id, v );
					cout << "Inserted a Motorcycle with ID [" << id << "]" << endl;
					break;
				case '4': cout << "Enter vehicle ID:  ";
					cin >> id;
					while( center->MLH_get( id ) != 0 ){
						cout << "VEHICLE WITH THIS ID EXISTS ALREADY, AUTO CHANGE ID TO ID+1" << endl;
						id++;
					}
					cout << "Enter model year (1990-2012):  ";
					cin >> year;
					cout << "Enter color:  ";
					cin >> color;
					cout << "Enter current mileage:  ";
					cin >> miles;
					cout << "Enter capacity:  ";
					cin >> cap;
					v = new Bus( id, year, color, miles, cap );
					
					cout << "What task should we perform on your vehicle?\n[0]TuneUp\n[1]OilChange\n[2]WheelAlignment\n[3]TireChange\n[4]WashandVacuum\n[5]WindowTint\n[B]ack\n";
					while( tasknum != 'B' ){
					cin >> tasknum;
					switch( tasknum ){
						case '0': v->assignTask( 0 );
							break;
						case '1': v->assignTask( 1 );
							break;
						case '2': v->assignTask( 2 );
							break;
						case '3': v->assignTask( 3 );
							break;
						case '4': v->assignTask( 4 );
							break;
						case '5': v->assignTask( 5 );
							break;
						case 'B':
							break;
        				        default: cout << "Wrong command, try again" << endl;
					}
					}
					break;
				case 'B':
					break;
                		default: cout << "Wrong command, try again" << endl;
			  }
			break;
		case '2':
			cout << "Which vehicle would you like to check out?(Enter ID number):  ";
			cin >> id;
			if( center->MLH_get( id ) != 0 ){
				cout << "VEHICLE WITH THIS ID EXISTS ALREADY, GOING BACK TO MAIN" << endl;
				break;
			}
			center->MLH_get( id )->checkOut( );
			center->MLH_delete( id );
			break;
		case '3':
			cout << "Which vehicle would you like to view?(Enter ID number):  ";
			cin >> id;
			if( center->MLH_get( id ) == 0 ){
				cout << "VEHICLE WITH THIS ID DOESN'T EXIST, GOING BACK TO MAIN" << endl;
				break;
			}
			cout << center->MLH_get( id );
			break; 
		case '4': cout << *center; 
			break;
		case '5': 
			cout << "Which vehicle would you like to add more tasks to?(Enter ID number):  ";
			cin >> id;
			if( center->MLH_get( id ) == 0 ){
				cout << "VEHICLE WITH THIS ID DOESN'T EXIST, GOING BACK TO MAIN" << endl;
				break;
			}
			v = center->MLH_get( id );
			cout << "What task should we perform on your vehicle?\n[0]TuneUp\n[1]OilChange\n[2]WheelAlignment\n[3]TireChange\n[4]WashandVacuum\n[5]WindowTint\n[B]ack\n";
				while( tasknum != 'B' ){
				cin >> tasknum;
				switch( tasknum ){
					case '0': v->assignTask( 0 );
						break;
					case '1': v->assignTask( 1 );
						break;
					case '2': v->assignTask( 2 );
						break;
					case '3': v->assignTask( 3 );
						break;
					case '4': v->assignTask( 4 );
						break;
					case '5': v->assignTask( 5 );
						break;
					case 'B':
						break;
        			        default: cout << "Wrong command, try again" << endl;
				}
				}
			break;
                case 'Q': delete center;
			cout << "bye!" << endl;
                        return 0;
                default: cout << "Wrong command, try again" << endl;
       	}
}
}
