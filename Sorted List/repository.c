#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

unsigned long counter = 0;
int size = 0;

void Repository_init();
int  Repository_invert( int key, int data );
int  Repository_get   ( int key, int *data );
void Repository_print ( int print_elements );

typedef struct dummy_element{
int data;
int key;
struct dummy_element *next;
} element;

element *head;

void Repository_init(){
	
	element *pelement;
	
	pelement = malloc(sizeof(element));	
	pelement->next = NULL;
	pelement->key = -1;
	pelement->data = 0;
	head = pelement;

}

int  Repository_invert( int key, int data ){

	element *p;
	element *pelement;
	p = head;
	
	while (p->next != NULL){
		if (p->next->key >= key){
			if (p->next->key == key){
				pelement = p->next;
				p->next = p->next->next;
				free(pelement);
				counter+=2;
				size--;
				return 0;
			}
			else {
				pelement = malloc(sizeof(element));	
				pelement->next = p->next;
				p->next = pelement;
				pelement->key = key;
				pelement->data = data;
				counter+=2;
				size++;
				return 1;
			}
		}
		else
			p = p->next;
			counter++; 
	}
		
	pelement = malloc(sizeof(element));
	p->next = pelement;
	pelement->key = key;
	pelement->next = NULL;
	pelement->data = data;
	counter++;
	size++;
	return 1;	
		
}

int  Repository_get   ( int key, int *data ){
	
	element *gelement;
	gelement = head;
	
	while (gelement->next != NULL && gelement->next->key <= key ){
		if (gelement->next->key == key){
			*data = gelement->next->data;
			return 1;
		}
		else {
			gelement = gelement->next;
			counter++;
		}
	}
	return 0;
}

void Repository_print ( int print_elements ){

	element *qelement;
	qelement = head;
	
	printf("The size of the repository is: %d\n", size);
	printf("The number of 'next' steps performed is: %u\n", counter);
	if (print_elements > 0){
		printf("The elements in the repository are: \n"); 
		while (qelement->next != NULL){
			printf("(%d, %d), ", qelement->next->key, qelement->next->data);
			qelement = qelement->next;
			counter++;
		}
		printf("\n");
	}
	else 
		return;
}

