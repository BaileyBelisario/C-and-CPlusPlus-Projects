#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  char c[40];
  char d[20][40]={0};
  char e[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
  char f[40];
  int rot,k,len,len2;
  int i,j,l=0;
  scanf("%d",&rot);
  while (rot!=0) {
    i = 0;
	scanf("%s",c);
	len=strlen(c);
    len2=strlen(e);
	for(k=len;k>=0;k--){
      for(j = 0; j < len2; j++){
		if (c[k]==e[j]){
		  if(j+rot>=len2)
            d[l][k]=e[(rot+j)-(len2)];
		  else
            d[l][k]=e[j+rot];
			printf("%c",d[l][k]);
			break;
        }
      }
    }
	printf("\n");
	l++;
    scanf("%d",&rot);
  }
  return 0;
}

