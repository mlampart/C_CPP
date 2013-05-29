#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "MLH_Node.h"
#include "MLH.h"
#include "ML_hash.h"
#include "random_op.h"

int main( ){

	MLH<int> *mlh; 
	mlh = new MLH<int>;
	int *k;
	
	int num_op;
	unsigned int seed;
	int range;
	cout << "Enter number of operations: " << endl;
	cin >> num_op;
	cout << "Enter range: " << endl;
	cin >> range;
	cout << "Enter seed: " << endl;
	cin >> seed;
	Random_operation rand(seed, range);
	
	for( int i = 1; i <= num_op; i++ ){
		rand.Randomize_next_op( );

		switch( rand.Get_op() ){
			case 'G': mlh->MLH_get( rand.Get_key() );
			break;
			case 'I': k = new int;
				  *k = 1;
				  if ( mlh->MLH_insert( rand.Get_key(), k ) == 0 ){
					delete k;
				  }
			break;
			case 'D': mlh->MLH_delete( rand.Get_key());
			break;
			default: cout << "ERROR" << endl;
			
		}
		if( (i % (num_op/10)) == 0 ){
			cout << "Printing after " << i << " operations" << endl;
			if( range > 100 ){
				mlh->MLH_set_print_option( 0 );
				cout << *mlh;
			}
			else{
				mlh->MLH_set_print_option( 1 );
				cout << *mlh;
			}
        	}
	}
	/*
	mlh->MLH_set_print_option( 1 );

	mlh->MLH_insert(40,new int(26));
	cout << *mlh;
	mlh->MLH_insert(35,new int(26));
	cout << *mlh;
	mlh->MLH_insert(30,new int(26));
	cout << *mlh;
	mlh->MLH_insert(25,new int(21));
	cout << *mlh;
	mlh->MLH_insert(20,new int(16));
	cout << *mlh;
	mlh->MLH_insert(15,new int(11));
	cout << *mlh;
	mlh->MLH_insert(10,new int(6));
	cout << *mlh;
	mlh->MLH_insert(5,new int(1));
	cout << *mlh;
	mlh->MLH_delete(15);
	cout << *mlh;
	mlh->MLH_delete(10);
	cout << *mlh;
	mlh->MLH_delete(5);
	cout << *mlh;*/
}
