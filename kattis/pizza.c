#include <stdio.h>
int main(){
  float r,c,a,a1,a2;
  scanf("%f",&r);
  scanf("%f",&c);
  a1=3.14*(r*r);
  a2=(r-c)*(r-c)*3.14;
  a=(a2/a1)*100;
  printf("%6f",a);
  return 0;
}

