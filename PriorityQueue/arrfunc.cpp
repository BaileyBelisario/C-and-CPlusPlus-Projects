#include "pqstart.h"

queue::queue(){
	spot = 0;
	cap = 12000;
	arr = new cargo[cap];
}

void queue::enq(cargo d){
	arr[spot] = d;
	spot++;
	_arrsort(arr,d);
}

cargo queue::deq(){
	cargo c;
	spot--;
	c = arr[spot];
	return c;
}

int queue::isEmptyq(){
	if(spot == 0)
		return 1;
	else
		return 0;
}

void queue::showq(){
	int i;

	for(i = 0; i < spot; i++)
		printf("%d :: %d\n", arr[i].pri, arr[i].idat);	

	cout << endl;
}

void queue::_arrsort(cargo arr[], cargo d){
/*	int i, swap = 1, j; 
	cargo tmp;

	for(i = 0; i < spot && swap == 1; i++){
		swap = 0;
		for(j = 0; j < (spot-1)-i; j++){
			if(arr[j].pri > arr[j+1].pri){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				swap = 1;
			}
		}
	}
*/
	int i, j,key;
	for(i = 1; i < spot; i++){
		key = arr[i].pri;
		j = i-1;
		while((key < arr[j].pri) && (j>=0)){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1].pri = key;
	}
}
