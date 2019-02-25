#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int k = 0;
	char s[50];
	fgets(s, 50, stdin);
	do{
		k++;
		fgets(s, 50, stdin);
	}while(s[0]!=EOF);
	

	return 0;
}
