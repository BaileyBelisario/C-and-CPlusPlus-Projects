#include <stdio.h>
int main(){
        int num,k;
        scanf("%d",&num);
        for(k=num;k>0;k--){
                int row, n;
                scanf("%d %d",&row,&n);
                int sum=n*n;
                printf("%d %d %d %d\n",row,(sum+n)/2,sum,sum+n);
        }
        return 0;
}
