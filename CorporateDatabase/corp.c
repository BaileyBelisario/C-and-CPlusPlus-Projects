#include "corp.h"


struct box *makeNode(struct box add){
    struct box *tmp;
    tmp = malloc(sizeof(struct box));
    strcpy(tmp->name,add.name);
    strcpy(tmp->code,add.code);
    tmp->cat=add.cat;
    tmp->next=NULL;
    return tmp;
}
void makeList(struct box *A[], struct box newdata){
    struct box *tmp=makeNode(newdata);
    tmp->next=A[newdata.cat];
    A[newdata.cat]=tmp;
}
void printList(struct box *A[]){
    FILE *fp = fopen("CorporateData", "w+");
    for(int i=1; i<11;i++) {
        struct box *tmp=A[i];
        fprintf(fp,"      ==== Category %2d ====\n",i);
        while(tmp){
            fprintf(fp,"Name: %10s || Code: #%6s\n", tmp->name, tmp->code);
            tmp = tmp->next;
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
void readFile(char *argv[], struct box *A[]){
    int cat, i;
    char code[10];
	char name[20];
    char choice;
    struct box new;
    for(i = 0; i < 11; i++)
        A[i] = NULL;
    FILE *fp = fopen(argv [1], "r");

	if(fp == NULL){
		printf("File %s not found\n",argv[1]);
		exit(1);
	}

    fscanf(fp,"%s %s %d", new.name, new.code, &new.cat);
    while(!feof(fp)){
        makeList(A, new);
        fscanf(fp,"%s %s %d", new.name, new.code, &new.cat);
    }
}
void scanadd(char name[], char code[], int *cat){
    int newcat;
    system("tput cup 24 40");
    printf("Enter Name of Person:\n");
    system("tput cup 25 40");
    printf("Enter Code of Person:\n");
    system("tput cup 26 40");
    printf("      Enter Category:\n");
    system("tput cup 24 62");
    scanf("%s", name);
    system("tput cup 25 62");
    scanf("%s", code);
    system("tput cup 26 62");
    scanf("%d", &newcat);
    *cat = newcat;
}
void addList(char *argv[], struct box *A[]){
	FILE *fp = fopen(argv[1], "a");
    char choice;
    int cat;
	char code[10];
    char name[20];
    system("clear");
    system("tput cup 20 40");
    printf("========================\n");
    system("tput cup 21 40");
    printf("|        Add Menu      |\n");
    system("tput cup 22 40");
    printf("========================\n");
    scanadd(name, code, &cat);
    system("tput cup 28 40");
    printf("Press: E to exit\n");
    system("tput cup 29 40");
	printf("       - to redo mistakes\n");
	system("tput cup 30 40");
	printf("       A to add again\n");
	system("tput cup 32 40");
	printf("User Input: ");
    scanf("%c",&choice);
    while(choice != EOF){
        if(choice == 'e' || choice == 'E'){
			fprintf(fp,"%s %s %d\n",name,code,cat);
          	fclose(fp);
            readFile(argv,A);
            system("clear");
            break;
        }
        if(choice == '-'){
        	system("tput cup 24 62");
            printf("                     \n");
            system("tput cup 25 62");
            printf("                     \n");
            system("tput cup 26 62");
            printf("                     \n");
            system("tput cup 28 40");
            printf("                     \n");
			system("tput cup 29 40");
            printf("                         \n");	
			system("tput cup 30 40");
            printf("                     \n");	
			system("tput cup 32 40");
            printf("                     \n");	
            scanadd(name, code, &cat);
		   	system("tput cup 28 40");
		    printf("Press: E to exit\n");
		    system("tput cup 29 40");
			printf("       - to redo mistakes\n");
			system("tput cup 30 40");
			printf("       A to add again\n");
			system("tput cup 32 40");
			printf("User Input: ");
        }
		if(choice == 'a'){
			fprintf(fp,"%s %s %d\n",name,code,cat);
        	system("tput cup 24 62");
            printf("                     \n");
            system("tput cup 25 62");
            printf("                     \n");
            system("tput cup 26 62");
            printf("                     \n");
            system("tput cup 28 40");
            printf("                     \n");
			system("tput cup 29 40");
            printf("                         \n");	
			system("tput cup 30 40");
            printf("                     \n");	
			system("tput cup 32 40");
            printf("                     \n");	
            scanadd(name, code, &cat);
    		system("tput cup 28 40");
    		printf("Press: E to exit\n");
    		system("tput cup 29 40");
			printf("       - to redo mistakes\n");
			system("tput cup 30 40");
			printf("       A to add again\n");
			system("tput cup 32 40");
			printf("User Input: ");	
		}
        scanf("%c", &choice);
    }
}
int extrasearch(struct box *A[], int k, struct box name, char choice){	
	int x;
	struct box *tmp;
	tmp = A[k];
	printf("%c", &choice);
	if(choice == 'n' || choice == 'N'){
		while(tmp!=NULL){
			x = strcmp(name.name,tmp->name);
			if(x == 0){
				system("tput cup 26 40");
	            printf("Successfully found in Category %d!\n", k);
				break;
	        }
			tmp = tmp->next;
		}
		if(x==0){
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(choice == 'c' || choice == 'C'){
		while(tmp!=NULL){
			x = strcmp(name.code,tmp->code);
			if(x == 0){
				system("tput cup 26 40");
	            printf("Successfully found in Category %d!\n", k);
				break;
	        }
			tmp = tmp->next;
		}
		if(x==0){
			return 0;
		}
		else{
			return 1;
		}
	}
	return 1;
}
void search(struct box *A[]) {
        struct box tmp;
		int k;
		int x, nl;
        char choice, ch;
		for(k=0;k<20;k++)
			tmp.name[k] = '\0';
		for(k=0;k<10;k++)
			tmp.code[k] = '\0';
    	system("clear");
	    system("tput cup 20 40");
	    printf("=======================\n");
	    system("tput cup 21 40");
	    printf("|      Search Menu    |\n");
	    system("tput cup 22 40");
	    printf("=======================\n");
	    system("tput cup 24 40");
		printf("Press C to search by Code...\n");
	    system("tput cup 25 40");
		printf("Press N to search by Name...\n");
		system("tput cup 26 40");
		scanf("%d",&nl);
		scanf("%c",&ch);
		if(ch == 'n' || ch == 'N'){
			system("tput cup 24 40");
			printf("                             \n");
			system("tput cup 25 40");
			printf("                             \n");
			system("tput cup 26 40");
			printf("                             \n");
			system("tput cup 24 40");
        	printf("Enter Name to Search: ");
        	scanf("%s", tmp.name);
		}
		if(ch == 'c' || ch == 'C'){
			system("tput cup 24 40");
			printf("                             \n");
			system("tput cup 25 40");
			printf("                             \n");
			system("tput cup 26 40");
			printf("                             \n");
			system("tput cup 24 40");
        	printf("Enter Code to Search: ");
        	scanf("%s", tmp.code);
		}
        for(k = 1; k < 11; k++){
			x = extrasearch(A,k,tmp,ch);
			if(x == 0)
				break;
        }
		if(x==1){
			system("tput cup 26 40");
			printf("Invalid Name or Code...Please Exit and Search Again...\n");
		}
		system("tput cup 28 40");
        printf("Press E to exit...  ");
        scanf("%c",&choice);
        while(choice != EOF){
        	if(choice == 'e' || choice == 'E'){
            	system("clear");
                break;
            }
            scanf("%c",&choice);
        }
}
void menu(){
    system("clear");
    system("tput cup 20 40");
    printf("========================\n");
    system("tput cup 21 40");
    printf("|    Company Database  |\n");
    system("tput cup 22 40");
    printf("========================\n");
    system("tput cup 24 40");
    printf("      ---OPTIONS---     \n");
    system("tput cup 26 40");
    printf("    View Database: V    \n");
    system("tput cup 27 40");
    printf("       Add Person: A    \n");
    system("tput cup 28 40");
    printf("    Remove Person: R    \n");
    system("tput cup 29 40");
    printf("Search for Person: S    \n");
    system("tput cup 30 40");
    printf("   Print Category: P    \n");
    system("tput cup 31 40");
    printf("  Change Category: C    \n");
    system("tput cup 32 40");
    printf("             Exit: E    \n");
    system("tput cup 34 40");
    printf("       User Input: ");
}
void view(char letter,struct box *A[]){
    char choice;
    int i;
    if(letter == 'v' || letter == 'V'){
        printList(A);
        system("clear");
        system("more CorporateData");
    }
    if(letter == 'p' || letter == 'P'){
        system("clear");
	    system("tput cup 20 40");
	    printf("========================\n");
	    system("tput cup 21 40");
	    printf("|  Print Category Menu  |\n");
	    system("tput cup 22 40");
	    printf("========================\n");
	    system("tput cup 24 40");
        printf("Enter a Category to Print: ");
        scanf("%d", &i);
        system("clear");
        printCat(A,i);
    }
    printf("\n\nPress 'Q' to Exit... ");
    scanf("%c", &choice);
    while(choice){
        if(choice == 'q' || choice == 'Q'){
            system("clear");
            break;
        }
        scanf("%c", &choice);
    }
}
void printCat(struct box *A[], int i){
    struct box *tmp = A[i];
    printf("      ==== Category %2d ====\n");
    while(tmp){
        printf("Name: %10s || Code: #%6s\n",tmp->name,tmp->code);
        tmp = tmp->next;
    }
}
void removeList(char *argv[],struct box *A[]){
    system("clear");
    system("tput cup 20 40");
    printf("========================\n");
    system("tput cup 21 40");
    printf("|       Remove Menu     |\n");
    system("tput cup 22 40");
    printf("========================\n");
    system("tput cup 24 40");
    printf("   Name of Person: ");
	char name[20];
    scanf("%s", name);
    system("tput cup 40");
	char code[10];
	char namein[20];
    int cat, i, x;
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen("newtest", "w+");

    fscanf(fp,"%s %s %d", namein, code, &cat);
    while(!feof(fp)){
    	x = strcmp(namein, name);
    	if( x != 0 ){
        	fprintf(fp2,"%s %s %d\n", namein, code, cat);
        }
        fscanf(fp,"%s %s %d",namein, code, &cat);
    }
    fclose(fp);
    fclose(fp2);

	remove(argv[1]);
	rename("newtest", argv[1]);
	readFile(argv,A);
}
void changeCat(char *argv[], struct box *A[]){
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen("newtest", "w+");
	int newcat, cat;
	int x;
	char name[20], name2[20];
	char code[10];
	system("clear");
    system("tput cup 20 40");
    printf("========================\n");
    system("tput cup 21 40");
    printf("| Change Category Menu |\n");
    system("tput cup 22 40");
    printf("========================\n");
    system("tput cup 24 40");
	printf("        Enter name: ");
	scanf("%s", name);
	system("tput cup 25 40");
	printf("Change to Category: ");
	scanf("%d",&newcat);
	fscanf(fp,"%s %s %d",name2,code,&cat);
    while(!feof(fp)){
    	x = strcmp(name, name2);
    	if( x != 0 ){
        	fprintf(fp2,"%s %s %d\n", name2, code, cat);
        }
		else{
			fprintf(fp2,"%s %s %d\n", name, code, newcat);
		}
        fscanf(fp,"%s %s %d",name2, code, &cat);
    }
    fclose(fp);
    fclose(fp2);

	remove(argv[1]);
	rename("newtest", argv[1]);
	readFile(argv,A);
}
