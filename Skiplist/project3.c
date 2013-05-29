
/* 
 * Project 3 template: to be modified by students to incorporate 
 *                     command line arguments exclusively 
 *                     (no input while program is running)
 */

#include <stdio.h>
#include <stdlib.h>
#include "sl_repository.h"

static int  Max_range;
static int  num_op; 
static int  seed;
static int  prob;

unsigned long int next =1;

void Get_next_op( char *random_op, int *random_int, int range );
int  rand( void ); 
void srand( unsigned int seed );
void Usage (int argc, char *argv[]);

int main( int argc, char *argv[] )
{ 

	Usage ( argc, argv );

    unsigned int s;
    int	rand_key; 
    char rand_op;
    int ret; 
    int ret_data;
    int i;

    unsigned long sum_data;
    int num_get, num_delete, num_insert;

    srand( s );

    sum_data   = 0;

    num_get    = 0;
    num_delete = 0;
    num_insert = 0;

    Repository_init( prob );

    for( i = 1; i <= num_op; i++ )
    {
        Get_next_op( &rand_op, &rand_key, Max_range );

	switch( rand_op )
	{
	    case 'G':
                num_get++;
		ret = Repository_get( rand_key, &ret_data );
		if( ret < 0 ) {
			printf("\nError in Get with return value %d \n", ret );
		}
		if( ret == 1 ) sum_data = sum_data + (ret_data%100);
		break;

	    case 'I':
                num_insert++;
		ret = Repository_insert( rand_key, i );
		if( ret < 0 ) {
			printf("\nError in Insert with return value %d \n", ret );
		}
		break;

	    case 'D':
                num_delete++;
		ret = Repository_delete( rand_key );
		if( ret < 0 ) {
			printf("\nError in Delete with return value %d \n", ret );
		}
		break;

	    default:
		printf("\nError!!!, Illegal operation %c\n", rand_op );
		exit(1);
	}

        if( (i % (num_op/10)) == 0 )
	{
		printf("Printing after %d operations of %d\n", i, num_op );
		if( Max_range > 100 ) Repository_print( 0 );
		else Repository_print( 2 );
	}
    }
    printf("Operation summary: get %d, delete %d, insert %d\n", num_get, num_delete, num_insert );
    printf("Sum of all Repository_get data modulo 100 is %d\n", sum_data );

  /*  
	int c;
	char op;
	int key;
	int val;
	char buf[1024];
	int pos = 0;
	while ((c=getchar()) != EOF)
	{
		if (c == '\n')
		{
			op = buf[0];
			key = val = strtol(buf + 2, NULL, 10);
			pos = 0;
			if (op == 'i')
				Repository_insert(key,val);
			else if (op == 'd')
				Repository_delete(key);
			else
				Repository_print(2);
		}
		else
		{
			buf[pos] = c;
			pos++;
		}
	}
*/			
	/*Repository_insert(1,400);
	Repository_insert(2,100);
	Repository_insert(3,100);
	Repository_insert(4,100);
	Repository_insert(5,100);
    	Repository_delete(3);
	Repository_print(2);*/
}

void    Usage (int argc, char *argv[])
{
        /* Setting defaults */
        Max_range = 100;
        num_op = 1000000; 
        seed = 1;
	prob = 50;

       /* first argument is the name of the executable */
        while( --argc > 0 )
        {
                argv++;

                if( !strncmp( *argv, "-r", 2 ) ){
                        sscanf(argv[1], "%ld", &Max_range );
                        argc--; argv++;
                }else if( !strncmp( *argv, "-o", 2 ) ){
                        sscanf(argv[1], "%ld", &num_op );
                        argc--; argv++;
                }else if( !strncmp( *argv, "-s", 2 ) ){
                        sscanf(argv[1], "%d", &seed );
                        argc--; argv++;
                }else if( !strncmp( *argv, "-p", 2 ) ){
                        sscanf(argv[1], "%d", &prob );
                        argc--; argv++;
                }else{
			return;
                        }
	}
}
void Get_next_op( char *random_op, int *random_int, int range )
{
    int  random_number;
    int  limit;

    random_number = rand() % 4;

    switch( random_number )
    {
	case 0:
	case 1:
		*random_op = 'G';
		break;
	case 2:
		*random_op = 'D';
		break;
	case 3:
		*random_op = 'I';
    }

    limit = (32768 / range ) * range;
    while( ( random_number = rand() ) >= limit ) ;

    *random_int = random_number % range + 1;
    
}

/* Pseudo random generator on 0..32767 */
int  rand(void)
{
    next = next *1103515245 + 12345;
    return (unsigned int)(next/65536)%32768;
}

void srand( unsigned int seed )
{
    next = seed;
}

