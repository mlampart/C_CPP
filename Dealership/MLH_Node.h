#ifndef MLHNODE_H
#define MLHNODE_H
#define MAX_DATA 5
#include "ML_hash.h"

template< typename NT > class MLH;

//template< typename NT >
//ostream& operator<< (ostream &output, const MLH_Node< NT > &node);


template< typename NT >
class MLH_Node{
	friend class MLH< NT >;
//	friend ostream& operator<< <>( ostream &output, const MLH_Node< NT > &node );
	public:
		MLH_Node( );
		~MLH_Node( );
		void increment( );
		void decrement( );
	private:
		int elements;
		int key[MAX_DATA];
		NT *data[MAX_DATA];
		MLH_Node<NT> *childptr[MAX_DATA];
};

template< typename NT >
MLH_Node< NT >::MLH_Node( ){
	
	elements = 0;
	for (int i = 0; i < MAX_DATA; i++){
		key[i] = 0;
		data[i] = 0;
		childptr[i] = 0;
	}
}

template< typename NT >
MLH_Node< NT >::~MLH_Node( ){
	
	for (int i = 0; i < MAX_DATA; i++){
		if( data[i] != 0 ){
			delete data[i];
			data[i] = 0;
		}
		if( childptr[i] != 0 ){
			delete childptr[i];
			childptr[i] = 0;
		}
	}
}

template< typename NT >
void MLH_Node< NT >::increment( ){
	elements++;
}

template< typename NT >
void MLH_Node< NT >::decrement( ){
	elements--;
}
#endif
