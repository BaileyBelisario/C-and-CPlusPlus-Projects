#include<stdio.h>

int main(){
	int num,i,k,row,newnum,j;
	scanf("%d",&num);
	for(k = 0; k < num; k++){
		int sum1=0,sum2=0,sum3=0;
		scanf("%d %d",&row,&newnum);
			for(i=0; newnum--; i++)
				sum1+=i;
			for(i=1; newnum--; i+=2)
				sum2+=i;
			for(i=2; newnum--; i+=2)
				sum3+=i;
		printf("%d %d %d %d\n",row,sum1,sum2,sum3);
	}
	return 0;
}
