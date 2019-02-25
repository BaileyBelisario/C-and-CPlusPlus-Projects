#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int A[], int Max, int N){
	int i;
	for (i = 0; i < N; ++i)
    	A[i] = rand() % Max + 1;
}
void print(int A[], int N){
	int i;
	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");
}
void sort(int A[], int N){

	int i ,j ,temp ,swap = 1, check = 0;

	for(i = 0; i < N && swap == 1; i++){
		swap = 0;
		for(j = 0; j < (N-1)-i; j++){
			check++;
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				swap = 1;
			}
		}
	}
}
int main()
{
	int A[10];
	srand(22);
	int Max = 30;
	int N = 10;
	
	fill(A, Max, N);
	printf("Unsorted: ");
	print(A, N);
	sort(A, N);
	printf("  Sorted: ");
	print(A, N);
	
	printf("\n");

	int B[25];
	srand(19);
	Max = 400;
	N = 25;

	fill(B, Max, N);
	printf("Unsorted: ");
	print(B, N);
	sort(B, N);
	printf("  Sorted: ");
	print(B, N);

	return 0;
}
