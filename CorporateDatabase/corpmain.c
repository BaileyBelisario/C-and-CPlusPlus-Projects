#include "corp.h"

int main(int argc,char *argv[]){

	if(!argv[0]){
		printf("[ERROR]: FILE not found\n");
		exit(1);
	}
	struct box *A[11];
	char choice;
	readFile(argv,A);
	menu();
	scanf("%c",&choice);
	printf("\n");
	while(choice){
		if(choice=='v'||choice=='V')
			view(choice,A);
		if(choice=='a'||choice=='A')
			addList(argv,A);
		if(choice=='r'||choice=='R')
			removeList(argv,A);
		if(choice=='e'||choice=='E'){
			system("clear");
			break;
		}
		if(choice=='s'||choice=='S')
			search(A);
		if(choice=='p'||choice=='P')
			view(choice,A);
		if(choice=='c'||choice=='C')
			changeCat(argv,A);
	menu();
	scanf("%c",&choice);
	printf("\n");
	}
	return 0;
}
