#include "pqstart.h"

int main()
{
 queue r, s, t;
 cargo c;
 int i, rep;
 int op, n;

 if ( t.isEmptyq() ) {
 c.pri = 33;
 r.enq( c);
 c.pri++;
 c = r.deq();
 t.enq(c);
 }

 srand(88);
 n = rand() % 201;
 //printf("%d iterations\n", n);
 for (i = 0; i < n; ++i)
 {
   c.pri = rand() % 437 + n ;
   c.idat = -i;
   c.cdat = -i;
   switch(c.pri%9)
   {
   case 8:
   case 0: if ( 1  ) r.enq(c); break;
   case 7:
   case 1: if ( 1  ) s.enq(c); break;
   case 6:
   case 2: if ( 1  ) t.enq(c); break;
   case 3: if ( !r.isEmptyq() ) c = r.deq(); break;
   case 4: if ( !s.isEmptyq() ) c = s.deq(); break;
   case 5: if ( !t.isEmptyq() ) c = t.deq(); break;
   }
 }
 printf("-----------\n");
 i = 0; 
 c = r.deq();
 printf("%d ", c.pri);
 while ( !r.isEmptyq() )
  {
   c = r.deq();
   //printf("Removed: %d\n", c.pri);
   i++;
  }
 printf(" ..  %d\n", i);

 i = 0; 
 c = s.deq();
 printf("%d ", c.pri);
 while ( !s.isEmptyq() )
  {
   c = s.deq();
   //printf("Removed: %d\n", c.pri);
   i++;
  }
 printf(" ..  %d\n", i);


 i = 0; 
 c = t.deq();
 printf("%d ", c.pri);
 while ( !t.isEmptyq() )
  {
   c = t.deq();
   //printf("Removed: %d\n", c.pri);
   i++;
  }
 printf(" ..  %d\n", i);
 printf("-----------\n");
 return 0; 
}
