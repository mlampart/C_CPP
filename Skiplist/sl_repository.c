#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "rand100.h"

unsigned long counter = 0;
int size = 0;

void init_stack();
void init_stack2();
void Repository_init( int p );
int  Repository_insert ( int key, int data );
int  Repository_delete (int key );
int  Repository_get   ( int key, int *data );
void Repository_print ( int print_elements );
void newlevel ();
int prob;

typedef struct dummy_element{
    int *data;
    int key;
    struct dummy_element *next;
    struct dummy_element *down;
} element;

	element *sentinel;

typedef struct dummy_element2 {
    element* val;
    struct dummy_element2 *next;
} stackelement;

	stackelement *Stack_head, *Stack_head2;

void clear();
void push( element *pelement ); 
element* pop(); 
void clear2();
void push2( element *pelement ); 
element* pop2(); 




void Repository_init( int p){

prob = p;
element *pelement;
element *qelement;

init_stack();
init_stack2();

        pelement = malloc(sizeof(element));
        pelement->next = NULL;
	pelement->down = NULL;
        pelement->key = 0;
	pelement->data = malloc(sizeof(int));
	*pelement->data = 0;
        
       	qelement = malloc(sizeof(element));
        qelement->next = NULL;
	qelement->down = pelement;
	counter++;
        qelement->key = 0;
	qelement->data = malloc(sizeof(int));
	*qelement->data = 0;
        sentinel = qelement;
}

void newlevel(){

element *pelement;
int* datatemp;

        pelement = malloc(sizeof(element));
        pelement->next = NULL;
	pelement->down = sentinel;
	pelement->key = 0;
	datatemp = malloc(sizeof(int));
	*datatemp = 0;
	pelement->data = datatemp;
	counter+=2;
	sentinel = pelement;
}

int  Repository_insert ( int key, int data ){

element *pelement;
element *p, *q;
p = sentinel->down;
q = sentinel->down;
int* datatemp;

	while (p != NULL){
		while (p->next != NULL && p->next->key <= key){
			if (p->next->key == key){
				clear();
				clear2();
				return 0;
			}
		p = p->next;
		}
	push(p);
	push2(q);
	q = q->down;
	p = p->down;
	}

	q = pop2();
	p = pop();

	pelement = malloc(sizeof(element));
	pelement->next = p->next;
	p->next = pelement;
	pelement->down = NULL;
	pelement->key = key;
	datatemp = malloc(sizeof(int));
	*datatemp = data;
	pelement->data = datatemp;
	counter+=2;
	size++;
	*(q->data) += 1;
	
	while (Stack_head != NULL){
		if (rand100() <= prob){
			element *levelelement;

			p = pop();
			levelelement = malloc(sizeof(element));
			levelelement->next = p->next;
			p->next = levelelement;
			levelelement->down = pelement;
			levelelement->key = key;
			levelelement->data = datatemp;
			counter+=3;
			pelement = levelelement;

			q = pop2();
			*(q->data) += 1;
		}
		else { 
			clear();
			clear2();
			return 1;
		}
	}	
	while (rand100() <= prob){
		element *nelement;
		
		newlevel();
		p = sentinel->down;
		nelement = malloc(sizeof(element));
		nelement->next = p->next;
		p->next = nelement;
		nelement->key = key;
		nelement->down = pelement;
		nelement->data = datatemp;
		counter+=3;
		pelement = nelement;
		*(p->data) += 1;
		
	}

	clear();
	clear2();
	return 1;
}

int  Repository_delete (int key ){

element *pelement, *delement;
element *p, *q, *r;
p = sentinel->down;
q = sentinel->down;	
	
	while (p != NULL){
		while (p->next != NULL && p->next->key <= key){
			if (p->next->key == key){
				push(p);
				break;
			}
			p = p->next;			
		}
		p = p->down;
		push2(q);
		q = q->down;
	}

	if (Stack_head == NULL){
		clear();
		clear2();
		return 0;
	}
	else {
		p = pop();
		q = pop2();
		
		free(p->next->data);
 
		while(p != NULL){
			
			pelement = p->next;
			p->next = p->next->next;
			counter++;
			free(pelement);
			pelement = NULL;
			p = pop();
			
			*(q->data) -= 1;
			
			if (*(q->data) == 0){
				r = sentinel;
				while(r->down != q){
					r = r->down;
				}
				delement = q;
				r->down = r->down->down;
				counter++;
					if(sentinel->down == NULL){
						Repository_init(prob);
					}
				free(delement->data);
				free(delement);
				delement = NULL;
				q = r;
			}
			else {
				q = pop2();
			}
		}
	}
	size--;
	clear();
	clear2();
	return 1;
}

int  Repository_get   ( int key, int *data ){

element *p;
p = sentinel->down;	
	
	while (p != NULL){
		while (p->next != NULL){
			if (p->next->key >= key){
				if (p->next->key == key){
					*data = *p->next->data; 
					return 1;
				}
				else {
					break;
				}
			}
			p = p->next;
		}
	p = p->down;
	}
	return 0;
}

void Repository_print ( int print_elements ){

element *p, *q;
int level = 0;
int level_;
p = sentinel;
q = sentinel;

	while(q->down != NULL){
		q = q->down;
		level++;
	}
	
	level_ = level;
	printf("The number of unique records is %d\n", size);
	printf("The number of 'next' steps performed is %u\n", counter);
	
	while(p->down != NULL ){
		p = p->down;
		printf("Level %d has %d records\n", level, *p->data);
		level--;
	}
		
	printf("The repository has %d levels\n", level_);

	if (print_elements == 1){
		printf("The unique records in the repository are: ");
		while(p->next != NULL){
			printf("<%d, %d> ", p->next->key, *p->next->data);
			p = p->next;
		}
		printf("\n\n");
		
	}
	if (print_elements == 2){
		
		p = sentinel->down;
		q = sentinel->down;
		while (p != NULL){
			printf("Level %d: ", level_);
			while (p->next != NULL){
				printf("<%d, %d> ", p->next->key, *p->next->data);
				p = p->next;
			}
		printf("\n");
		level_--;
		q = q->down;
		p = q;
		}
		printf("\n");
		

	}
	else {
		return;
	}
}



void init_stack(){

	Stack_head = NULL;
}

void clear(){
	
	while (Stack_head != NULL){
		pop();
	}
}
	

element* pop(){

	element *pelement;
	stackelement *temp;
	if( Stack_head == NULL ) return NULL;
	pelement = Stack_head->val;
	temp = Stack_head;
	Stack_head = Stack_head->next;
	free( temp );
	return pelement;
}

void push( element *pelement ){

	stackelement* temp = malloc( sizeof(stackelement) );
	temp->next = Stack_head;
	temp->val = pelement;
	Stack_head = temp;
}

void init_stack2(){

        Stack_head2 = NULL;
}

void clear2(){

        while (Stack_head2 != NULL){
                pop2();
        }
}


element* pop2(){

        element *pelement;
        stackelement *temp;
        if( Stack_head2 == NULL ) return NULL;
        pelement = Stack_head2->val;
        temp = Stack_head2;
        Stack_head2 = Stack_head2->next;
        free( temp );
        return pelement;
}

void push2( element *pelement ){

        stackelement *temp;
	temp = malloc( sizeof(stackelement) );
       	temp->next = Stack_head2;
        temp->val = pelement;
       	Stack_head2 = temp;
}

