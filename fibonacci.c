#include <stdio.h>
#include <stdlib.h>

unsigned int call = 0;
unsigned int F[100] = {0,1,1};

unsigned int fib(unsigned int k){
	call++;
	
	if(F[k] > 0)
		return F[k];

	if(k==1){
		F[k] = 1;
		return 1;
	}
	else if(k==2){
		F[k] = 1;
		return 1;
	}
	
	unsigned int c = fib(k-1) + fib(k-2);
	
	F[k] = c;
	
	return c;
}

int main(int argc, char *argv[]){
	
	unsigned int n,N;
	
	if (argc == 1){
		printf("No argument, Using default size, 5\n");
		N = 5;
	}
	else{
		N = atoi( argv[1] );
		if ( N <= 0 )
		{
			printf("Bad argument %s, Using default size 5\n", argv[1]);
			N = 5;
		}
	}

	n = fib(N);

	printf("%3d  --  %3d\n",n,call);

	return 0;
}
