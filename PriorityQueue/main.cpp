#include "pqstart.h"

int main()
{
	queue pq;
	cargo c;
	int i, rep;
	int op;

// repeat 500 times for timing purposed
// adjust this constant if needed when testing
	for (rep = 0; rep <= 500; ++rep)
	{
		printf("--%4d--\n", rep);
		for (i = 0; i < 10; ++i)
		{
			c.pri = (i + 7)  % 10;
			c.idat = -i;
			c.cdat = -i;
	//		printf("Inserting (%d)::%d--%d\n", i, c.pri, c.idat);
			pq.enq( c);
		}
	
		//   MODIFFY THIS VALUE FOR LIST SIZE
		for (i = 0; i < 3000; ++i)
		{
			op = rand() % 4;
			if (op == 3)
			{
				c = pq.deq();
	//			printf("Removed (%d)::%d--%d\n", i, c.pri, c.idat);
			}
			else
			{
				c.pri = i * 2 % 10;
				c.idat = i;
				c.cdat = i;
	//			printf("Inserting (%d)::%d--%d\n", i, c.pri, c.idat);
				pq.enq( c);
			} 
		}
	//	if ( rep < 500)
	//	{
		i = 0; 
		while ( !pq.isEmptyq() )
		{
			c = pq.deq();
			i++;
		}
		printf("   .. %d\n", i);
	//	}
	}
//	pq.showq( );
	return 0; 
}
