#include "pqstart.h"

queue::queue(){
	head = NULL;
	tail = NULL;
}
void queue::enq(cargo d){
	node *tmp = new node;
	tmp->dat = d;
	if(head == NULL){
		head = tmp;
		tail = tmp;
	}
	else if(tmp->dat.pri > head->dat.pri){
		tmp->next = head;
		head = tmp;
	}
	else if(tmp->dat.pri < tail->dat.pri){
		tail->next = tmp;
		tail = tmp;
	}
	else{
	/*	node *walk = head;
		node *loc;
			while(walk->next !=NULL && tmp->dat.pri <= walk->next->dat.pri)
				walk = walk->next;
		loc = walk->next;	
		walk->next = tmp;
		tmp->next = loc;*/
		node *walk = head;
		while(walk->next != NULL && tmp->dat.pri <= walk->next->dat.pri)
				walk = walk->next;
		node *tmp2 = walk->next;
		walk->next = tmp;
		tmp->next = tmp2;
	}
}

cargo queue::deq(){
	node *r = head;
	head = head->next;
	return r->dat;
}

int queue::isEmptyq(){
	if(head == NULL)
		return 1;
	else
		return 0;
}

void queue::showq(){
	node *mov = head;
	while(mov != NULL){
		printf("%d :: %d\n", mov->dat.pri, mov->dat.idat);
		mov = mov->next;
	}
	cout << endl;
}

