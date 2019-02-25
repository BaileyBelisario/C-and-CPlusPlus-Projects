#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct box{
    char name[20];
    char code[10];
    int cat;
    struct box *next;
};

struct box *makeNode( struct box add);
int extrasearch(struct box *A[], int k, struct box name, char choice);
void menu();
void view(char letter, struct box *A[]);
void readFile(char *argv[],  struct box *A[]);
void makeList( struct box *A[],  struct box newdata);
void printList( struct box *A[]);
void removeList(char *argv[], struct box *A[]);
void addList(char *argv[], struct box *A[]);
void scanadd(char name[], char code[], int *cat);
void search(struct box *A[]);
void printCat(struct box *A[], int i);
void changeCat(char *argv[], struct box *A[]);
