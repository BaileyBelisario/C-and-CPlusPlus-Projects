#include "pqstart.h"

int main()
{
 queue pq, gp;
 cargo c;
 int i, rep;
 int op, n;

 c.pri = 33;
 gp.enq( c);
 c = gp.deq();

 srand(44);
 n = rand() % 20;
 printf("N: %d\n", n);
 for (i = 0; i < 5; ++i)
 {
   	c.pri = rand() % 43 ;
   	c.idat = -i;
   	c.cdat = -i;
   	printf("Inserting (%d)::%d--%d\n", i, c.pri, c.idat);
   	pq.enq( c);
 }

    c.pri = 33;
    c.idat = i;
    c.cdat = i;
    printf("Inserting (%d)::%d--%d\n", i, c.pri, c.idat);
    pq.enq( c);

for (i = 0; i < 11; ++i)
 {
  	op = rand() % 4;
  	if (op  % 2)
   	{
    	c = pq.deq();
    	printf("Removed (%d)::%d--%d\n", i, c.pri, c.idat);
   	}
  	else
   	{
    	c.pri = rand() % 91;
    	c.idat = i;
    	c.cdat = i;
		if ( !c.pri ) c.pri = 872;
    	printf("Inserting (%d)::%d--%d\n", i, c.pri, c.idat);
    	pq.enq( c);
   } 
 }
 //if ( rep < 500)
 //{
 printf("------------\n");
 i = 0;
 while ( !pq.isEmptyq() )
  {
   c = pq.deq();
printf("Removed: %d\n", c.pri);
   i++;
  }
 printf("   .. %d\n", i);
 //}

// pq.showq( );
 return 0; 
}
