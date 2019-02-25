#include <stdio.h>
#include <string.h>

int posC(char A1[], char A2[]){
	int k, i;
	int count = 0;
	int len=strlen(A1);
	
	if(strlen(A2)<len)
		len=strlen(A2);

	for(k = 0; k < len; k++)
		if(A1[k] == A2[k])
			count++;

	return count;
}
int posNC(char A1[], char A2[]){
	int k, i;
	int count = 0;
	int len=strlen(A1);

	if(strlen(A2)<len)
		len=strlen(A2);

	for(k = 0; k < len; k++){
		if(((A1[k] >= 'a' && A1[k] <= 'z') && (A2[k] >= 'A' && A2[k] <= 'Z')) || 
		((A1[k] >= 'A' && A1[k] <= 'Z') && (A2[k] >= 'a' && A2[k] <= 'z'))){
			if((A1[k]+32 == A2[k]) || (A2[k]+32 == A1[k]))
				count++;
		}
		else if((A1[k] == A2[k]))
			count++;
	}
	return count;
}
int CM(char A1[], char A2[], int len1, int len2){
	int k, i;
	int count = 0;
	for(k = 0; k < len1; k++)
		for(i = 0; i < len2; i++)
			if(A1[k] == A2[i])
				count++;

	return count;
}
int NCM(char A1[], char A2[], int len1, int len2){
	int k, i;
	int count = 0;
	for(k = 0; k < len1; k++)
		for(i = 0; i < len2; i++)
			if(((A1[k] >= 'a' && A1[k] <= 'z') && (A2[i] >= 'A' && A2[i] <= 'Z')) || 
			((A1[k] >= 'A' && A1[k] <= 'Z') && (A2[i] >= 'a' && A2[i] <= 'z'))){
				if((A1[k]+32 == A2[i]) || (A2[i]+32 == A1[k]))
					count++;
			}
			else if(A1[k] == A2[i])
				count++;
	
	return count;
}
int main(){
	char str1[1000];
	char str2[1000];
	int poscase = 0, posnocase = 0, casematch = 0, nocasematch = 0;
	int len1, len2;
	
	printf("\n");

	fgets(str1, 1000, stdin);
	fgets(str2, 1000, stdin);
	
	len1 = strlen(str1);
	len1--;
	str1[len1] = '\0';

	len2 = strlen(str2);
	len2--;
	str2[len2] = '\0';

	poscase = posC(str1, str2);
	posnocase = posNC(str1, str2);
	casematch = CM(str1, str2, len1, len2);
	nocasematch = NCM(str1, str2, len1, len2);

	printf("\n%2d: %s\n%2d: %s\n\n", len1, str1, len2, str2);
	printf("Position | Case: %2d  Nocase: %2d\n", poscase, posnocase);
	printf("Contains | Case: %2d  Nocase: %2d\n\n", casematch, nocasematch);

	return 0;
}
