#ifndef MLH_H
#define MLH_H
#define MAX_LEVELS 8
#include "MLH_Node.h"
#include "ML_hash.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template< typename NT >
ostream& operator<< (ostream &output, MLH< NT > &mlh);

template< typename NT >
class MLH{

	friend ostream& operator<< <>( ostream &output, MLH< NT > &mlh );	
	public:
		MLH();
		~MLH();
		int MLH_insert( const int&, NT* );
		int MLH_delete( const int& );
		NT* MLH_get( const int& );
		void incAll( );
		void decAll( );
		void MLH_set_print_option( int );
		void print( ostream&, MLH_Node< NT >& );
		MLH_Node< NT > *firstNode;
	private:
		MLH_Node< NT > *path[MAX_LEVELS];
		int level;
		MLH_Node< NT > *newNode( );
		void explode( MLH_Node<NT>& );
		void implode( MLH_Node<NT>& );
		int numObjects;
		int numNodes;
		int counter;
		int printOption;
};

#endif

template< typename NT >
MLH< NT >::MLH( ){
	numObjects = 0;
	numNodes = 0;
	counter = 0;
	printOption = 0;
	firstNode = 0;
	level = 1;
	for (int i = 0; i < MAX_LEVELS; i++){
		path[i] = 0;
	}
	
}

template< typename NT >
MLH< NT >::~MLH( ){

delete firstNode;	
/*	if( firstNode.elements > 5 ){
		for( int i = 0; i < MAX_DATA; i++ ){
			if( firstNode.childptr[i] != 0 ){
				delete firstNode.childptr[i];
			}
			else{
				continue;
			}
		}
	}
*/
}

template< typename NT >
MLH_Node< NT > *MLH< NT >::newNode( ){
	
	numNodes++;
	return new MLH_Node< NT >( );
}

template< typename NT >
void MLH< NT >::MLH_set_print_option( int option ){
	
	if( option == 0 || option == 1 ){
		printOption = option;
	}
	else{
		cout << "Invalid option." << endl;
	}
}

template< typename NT >
ostream& operator<<( ostream &output, MLH< NT > &mlh ){
		
	output << "NUMBER OF OBJECTS: " << mlh.numObjects << endl;
	output << "NUMBER OF NODES: " << mlh.numNodes << endl;
	output << "NUMBER OF STEPS: " << mlh.counter << endl;
	if ( mlh.firstNode == 0 ){
		output << "NOTHING INSERTED YET" << endl;
		return output;
	}
	mlh.print( output, *mlh.firstNode );
	return output;
}

template< typename NT >
void MLH< NT >::print( ostream &out , MLH_Node< NT > &node ){
	if ( printOption == 1 ){
		if( node.elements > 5 ){
			for( int i = 0; i < MAX_DATA; i++ ){
				if( node.childptr[i] != 0 ){
					print(out, *node.childptr[i]);
				}
				else{
					continue;
				}
			}
		}
		else{
			for( int j = 0; j < node.elements; j++ ){
//				if (node.key[j] != 0)
				out << "[" << node.key[j] << ", " << *node.data[j] << "]";
			}
			out << endl;
		}	
	}
}

template< typename NT >
int MLH< NT >::MLH_insert( const int &key, NT *object ){

	MLH_Node< NT > *ptr;
	level = 1;
	for( int i = 0; i < MAX_LEVELS; i++){
		path[i] = 0;
	}
	
	if( firstNode == 0 ){
		ptr = newNode( );
		firstNode = ptr;
		ptr->key[0] = key;
		ptr->data[0] = object;
		ptr->increment( );
		numObjects++;
		counter++;
//		cout << "INSERTED " << key << " INTO FIRST NODE" << endl;	
		return 1;
	}
	else{
		ptr = firstNode;
	}
	
	while( ptr->elements > 5){
		path[level-1] = ptr;
		if( ptr->childptr[ML_hash( level, key )-1] == 0){
			ptr->childptr[ML_hash( level, key )-1] = newNode( );
		}
		ptr = ptr->childptr[ML_hash( level, key )-1];
		level++;
	}
	
	for(int i = 0; i < ptr->elements; i++){
		if (ptr->key[i] == key){
	//		cout << "DUPLICATE " << key << " FOUND" << endl;
			counter++;
			return 0;
		}
		else{
			continue;
		}
	}
	
	while( ptr->elements == 5 ){ 
	//	cout << "EXPLOSION!" << endl;
		explode( *ptr );
		if( ptr->childptr[ML_hash( level, key )-1] == 0){
			ptr->childptr[ML_hash( level, key )-1] = newNode( );
		}
		path[level-1] = ptr;
		ptr = ptr->childptr[ML_hash( level, key )-1];
		level++;
	}
	
	ptr->key[ptr->elements] = key;
	ptr->data[ptr->elements] = object;
	ptr->increment( );
	numObjects++;

//	cout << "INSERTED " << key << endl;
	incAll( );
	level = 1;
	return 1;
}

template< typename NT >
int MLH< NT >::MLH_delete( const int &key ){

	MLH_Node< NT > *ptr;
	level = 1;
	for( int i = 0; i < MAX_LEVELS; i++){
		path[i] = 0;
	}
	
	if( firstNode == 0 ){
	//	cout << "KEY " << key << " DOESN'T EXIST IN THE FIRST NODE" << endl;	
		counter++;
		for( int i = 0; i < MAX_LEVELS; i++){
			path[i] = 0;
		}
		return 0;
	}
	else{
		ptr = firstNode;
	}
	
	while( ptr->elements > 5){
		path[level-1] = ptr;
		if( ptr->childptr[ML_hash( level, key )-1] == 0){
	//		cout << "KEY " << key << " DOESN'T EXIST" << endl;
			counter++;
			return 0;
		}
		ptr = ptr->childptr[ML_hash( level, key )-1];
		level++;
	}
	
	for(int i = 0; i < ptr->elements; i++){
		if (ptr->key[i] == key){
//			cout << "KEY " << key << " DELETED" << endl;
			numObjects--;
			delete ptr->data[i];
			ptr->key[i] = ptr->key[ptr->elements-1];
			ptr->data[i] = ptr->data[ptr->elements-1];
			ptr->key[ptr->elements-1] = 0;
			ptr->data[ptr->elements-1] = 0;
			ptr->decrement( );
			counter++;
			while( level > 1){ 
				path[level-2]->decrement( );
				if( path[level-2]->elements == 5 ){
					counter++;
//					cout << "IMPLOSION!" << endl;
					implode( *path[level-2] );
				}
				level--;
			}
			break;
		}
		else{
			continue;
		}
	}
	if( numNodes == 0 ){
		firstNode = 0;
	}
	level = 1;
	return 1;
}

template< typename NT >
void MLH< NT >::explode( MLH_Node<NT> &node ){
	
	MLH_Node< NT > *temp;

	for( int j = 0; j < MAX_DATA; j++ ){
		if( node.childptr[ML_hash( level, node.key[j] )-1] == 0 ){
			node.childptr[ML_hash( level, node.key[j] )-1] = newNode( );
		}
		temp = node.childptr[ML_hash( level, node.key[j] )-1];
		temp->key[ temp->elements ] = node.key[j];
		temp->data[ temp->elements ] = node.data[j];
		temp->increment( );
	}
	
	for ( int k = 0; k < MAX_DATA; k++ ){
		node.key[k] = 0;
		node.data[k] = 0;
	}
}

template< typename NT >
void MLH< NT >::implode( MLH_Node<NT> &node ){
	int k = 0;
	MLH_Node< NT > *temp;
	for( int i = 0; i < MAX_DATA; i++ ){
		temp = node.childptr[i];
		if ( temp != 0 ){
			for( int j = 0; j < temp->elements; j++ ){
				node.key[k] = temp->key[j];
				node.data[k] = temp->data[j];
				temp->data[j] = 0;
				k++;
			}
			delete node.childptr[i];
			node.childptr[i] = 0;
			numNodes--;
			//if( numNodes == 1 ){
			//	firstNode = &node;
			//}
		}
		else{
			continue;
		}
	}
}

template< typename NT >
void MLH< NT >::incAll( ){
	
	for (int k = 0; k < MAX_LEVELS; k++){
		if( path[k] != 0 ){
			path[k]->increment( );
			path[k] = 0;
		}
		else{
			return;
		}
	}
}

template< typename NT >
void MLH< NT >::decAll( ){
	
	for (int k = 0; k < MAX_LEVELS; k++){
		if( path[k] != 0 ){
			path[k]->decrement( );
			path[k] = 0;
		}
		else{
			return;
		}
	}
}

template< typename NT >
NT* MLH< NT >::MLH_get( const int &key ){

	MLH_Node< NT > *ptr;
	level = 1;

	if( firstNode == 0 ){
		counter++;
//		cout << key << " IS NOT IN THE FIRST NODE" << endl;
		return 0;
	}
	else{
		ptr = firstNode;
		
		while( ptr->elements > 5){
			if( ptr->childptr[ML_hash( level, key )-1] == 0){
//				cout << key << " IS NOT THERE" << endl;
				counter++;
				return 0;
			}
			ptr = ptr->childptr[ML_hash( level, key )-1];
			level++;
		}
		
		for(int i = 0; i < ptr->elements; i++){
			if (ptr->key[i] == key){
				counter++;
//				cout << "FOUND " << key << endl;
				return ptr->data[i];
			}
			else{
				continue;
			}
		}
//		cout << key << " IS NOT THERE" << endl;
	}
	
	level = 1;
}
