#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct cargo{
	int idat;
	int cdat;
	int pri;	//thisisthepriority!
};

struct node{
	cargo dat;
	node *next;
};

class queue{
	public:
		queue();
		void enq(cargo d);
		cargo deq();
		void showq();
		int isEmptyq();
	private:
		node *head;
		node *tail;
		cargo *arr;
		int spot;
		int cap;
		void _arrsort(cargo arr[],cargo d);
		void upheap();
		void downheap();
};
