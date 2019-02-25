#include "pqstart.h"

queue::queue()
{
     cap = 12000;
     arr = new cargo[cap+1];
     spot = 1;
}

void queue::enq(cargo d)
{
    arr[spot]=d;
    spot++;
    upheap();
}

void queue::showq()
{
        int i;
        for (i = 1; i < spot; ++i)
			printf("%d :: %d\n",arr[i].pri,arr[i].idat);
        cout << endl;
}
int queue::isEmptyq(){
        if(spot == 1)
                return 1;
        else
                return 0;
}

cargo queue::deq()
{
    int y=spot-1;
	cargo x=arr[1];
    arr[1]=arr[y];
    downheap();
    spot--;
    return x;
}

void queue::upheap()
{
        int i = spot-1; 
		cargo tmp;

        while(i > 1){
                if(arr[i/2].pri < arr[i].pri){
                        tmp = arr[i/2];
                        arr[i/2] = arr[i];
                        arr[i] = tmp;
                        i = i/2;
                }
                else
                        i=1;
        }
}

void queue::downheap()
{
        int i = 1;
		cargo tmp;

	while ( i < spot ){
		if(arr[i].pri > arr[i*2].pri && arr[i].pri > arr[i*2+1].pri)
			return;
		else if(i*2 < spot && arr[i*2].pri > arr[i*2+1].pri){
			tmp = arr[i];
			arr[i] = arr[i*2];
			arr[i*2] = tmp;
			i = i*2;
		}
		else if(i*2+1 < spot){
			tmp = arr[i];
			arr[i*2+1] = tmp;
			i = i*2+1;
		}
		else
			i=spot;
	}
}
