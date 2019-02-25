#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char firstchar,newchar;
	scanf("%c",&firstchar);
	
	while(firstchar!=EOF){
		char *a=NULL;
		char *b=NULL;
		int tmp[100]={0},printlen=1,k=0,len=0,i=0,num=0;
		char tmp2[100]={0};
		
		if(firstchar=='e'){
			
			scanf("%ms",&a);
			len=strlen(a);
			
			for(k=0;k<len-1;k++){
				if(a[len-1]!=a[len-2]&&k==len-2){	
					i++;
					printlen++;
					tmp2[i]=a[len-1];
				}
				if(a[k]==a[k+1]){
					tmp[i]++;
					tmp2[i]=a[k];
				}
				else{
					tmp2[i]=a[k];
					i++;
					printlen++;
				}
			}

			if(len==1)
				tmp2[0]=a[k];
			
			for(k=0;k<printlen;k++)
				printf("%%%d$%c",tmp[k]+1,tmp2[k]);
		
			printf("\n");
		}
		if(firstchar=='d'){
			scanf("%ms",&b);
			len=strlen(b);
			for(k=0;k<len;k++){
				if(b[k]=='%'){
				}
				if(b[k]=='$'){
				}
				for(i=0;i<num;i++)
					printf("%c",firstchar);
			}
			printf("\n");
		}
		scanf("%c",&firstchar);
		free(a);
		free(b);
	}
	return 0;
}
