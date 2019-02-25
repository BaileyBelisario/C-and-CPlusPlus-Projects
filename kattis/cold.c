#include <stdio.h>

int main(){
	int num1,num2,k,count=0;
	scanf("%d",&num1);
	for(k=0;k<num1;k++){
		scanf("%d",&num2);
		if(num2<0)
			count++;
	}
	printf("%d",count);
	return 0;
}
