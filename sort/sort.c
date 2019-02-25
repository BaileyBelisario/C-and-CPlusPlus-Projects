#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main(){
	FILE *fp;
	fp = fopen("testnum","r");
	int a[100] = {0};
	int i = 0;
	while(!feof(fp)){
		i++;
		fscanf(fp,"%d", &a[i]);
	}

	for(int k = 1; k < i; k++)
		printf("%d ",a[k]);

	puts("");

	qsort(a,i,sizeof(int),cmpfunc);

	for(int k = 1; k < i; k++)
		printf("%d ",a[k]);

	fclose(fp);
	return 0;
}
