#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define edge pair<int,int>

class graph{
	public:
		graph();
		graph( int x );
		void bfs( int x );
		void bfssp( int x );
		void dfs( int x );
		void dfssp( int x );
		void mprint();
		void fill( ifstream& file );
		void dij(int x);
		void prim(int n);
		void kruskal();
		void addEdge(int x, int y, int z);
		void unionSet(int x, int y);
		void fw();
		int findSet(int x);
		int minDis(int dis[], bool set[]);
	private:
		int **a;
		int **a2;
		int s;
		int count;
		vector<pair<int, edge>> G;
		vector<pair<int, edge>> T;
		int *parent;
};

graph::graph(){
	int k, i;
	s = 5;
	parent = new int[s+1];
	a = new int*[s+1];
	a2 = new int*[s+1];
	for( k = 0; k < s+1; k++)
		a[k] = new int[s+1], parent[k] = k, a2[k] = new int[s+1];

	a[0][0] = 0;

	for(k = 1; k < s+1; k++){
		a[0][k] = k;
		a[k][0] = k;
	}

	for(k = 1; k < s+1; k++)
		for( i = 1; i < s+1; i++)
			a[k][i] = 0, a2[k][i] = INT_MAX;

	G.clear();
	T.clear();
}

graph::graph(int x){
	int k, i;
	s = x;
	parent = new int[s+1];
	a = new int*[s+1];
	a2 = new int*[s+1];
	for( k = 0; k < s+1; k++)
		a[k] = new int[s+1], parent[k] = k, a2[k] = new int[s+1];

	a[0][0] = 0;

	for(k = 1; k < s+1; k++){
		a[0][k] = k;
		a[k][0] = k;
	}

	for(k = 1; k < s+1; k++)
		for( i = 1; i < s+1; i++)
			a[k][i] = 0, a2[k][i] = INT_MAX;

	G.clear();
	T.clear();
}

void graph::addEdge(int x, int y, int z){
	G.push_back(make_pair(z, edge(x,y)));
}

int graph::findSet(int x){
	if(x == parent[x])
		return x;
	else
		return findSet(parent[x]);
}

void graph::unionSet(int x, int y){
	parent[x] = parent[y];
}

void graph::fill( ifstream& file ){
	int k, i, n, x, y;
	file >> count;

	for(k = 0; k < count; k++){
		file >> n;
		x = n;
		file >> n;
		y = n;
		file >> n;
		a[x][y] = n;
		a[y][x] = n;
		a2[x][y] = n;
		a2[y][x] = n;
		addEdge(x,y,n);
	}
}

void graph::mprint(){
	int k, i;
	

	cout << endl << endl << "    ";
	for(k = 1; k < s+1; k++)
		cout << a[0][k] << " ";
	
	cout << endl << endl;

	for(k = 1; k < s+1; k++){
		for(i = 0; i < s+1; i++){
			if(i == 0)
				cout << a[k][i] <<"   ";
			else
				cout << a[k][i] << " ";
		}
		cout << endl;
	}
}

void graph::bfs(int x){
	queue<int> q;	

	int arr[s+1] = {0};

	arr[x] = 1;

	for(int i = 1; i < s+1; i++){
		if(a[x][i] > 0){
			q.push(i);
			arr[i] = 1;
		}
	}

	cout << "BFS: " << x << " ";

	while(!q.empty()){
		int n = q.front();
		q.pop();
		cout << n << " ";
		for(int i = 1; i < s+1; i++){
			if(a[n][i] > 0 && arr[i] != 1){
				q.push(i);
				arr[i] = 1;
			}
		}
	}

}

void graph::bfssp(int x){
	queue<int> q;	

	int arr[s+1] = {0};

	arr[x] = 1;

	cout << "BFSSP:";

	for(int i = 1; i < s+1; i++){
		if(a[x][i] > 0){
			q.push(i);
			arr[i] = 1;
		}
	}

	for(int i = 1; i < s+1; i++)
		if(arr[i] == 1 && i != x)
			cout << " " << x << "->" << i;


	while(!q.empty()){
		int arr2[s+1] = {0};
		int n = q.front();
		q.pop();
		for(int i = 1; i < s+1; i++){
			if(a[n][i] > 0 && arr2[i] != 1 && arr[i] != 1){
				q.push(i);
				arr2[i] = 1;
				arr[i] = 1;
			}
		}
		for(int i = 1; i < s+1; i++)
			if(arr2[i] == 1)
				cout << " " << n << "->" << i;
	}
}

void graph::dfs(int x){
	stack<int> mystack;
	int arr[s+1] = {0};
	int i, k, j;
	int popped;
	cout << "DFS:";
	mystack.push(x);
	while(!mystack.empty()){
		popped = mystack.top();
		mystack.pop();
		if(arr[popped] == 0){
			arr[popped] = 1;
			cout << " " << popped;
			for(i = s; i > 0; i--){
				if(a[popped][i] > 0 && arr[i] != 1){
					mystack.push(i);
				}
			}
		}
	}
}

void graph::dfssp(int x){
	int i, n;
	int u[s+1] = {0};
	cout << "DFSSP:";
	stack<int> first;
	stack<int> second;
	first.push(x);
	u[x] = 1;
	for(i = s; i > 0; i--)
		if(a[x][i] > 0)
			second.push(i);
	
	while(!second.empty()){
		if(u[second.top()] == 1)
			second.pop();
		else{
			if(a[first.top()][second.top()] == 0)
				first.pop();
			else{
				cout << " " << first.top() << "->" << second.top();
				n = second.top();
				second.pop();
				first.push(n);
				u[n] = 1;
				for(i = s; i > 0; i--)
					if(a[first.top()][i] > 0 && u[i] != 1)
						second.push(i);
			}
		}
	}
}

int graph::minDis(int dis[], bool set[]){
	int min = INT_MAX, num, i;
	for(i = 0; i < s+1; i++){
		if(set[i] == false && dis[i] <= min){
			min = dis[i];
			num = i;
		}
	}
	return num;
}

void graph::dij(int x){
	int dis[s+1], i, num, k;
	bool set[s+1];
	
	for(i = 0; i < s+1; i++){
		dis[i] = INT_MAX;
		set[i] = false;	
	}

	dis[x] = 0;
	
	for(i = 1; i < s+1; i++){
		num = minDis(dis,set);
		set[num] = true;                  
		for(k = 1; k < s+1; k++){
			if(!set[k] && a[num][k] && dis[num] != INT_MAX && dis[num] + a[num][k] < dis[k])
			dis[k] = dis[num] + a[num][k];
		}
	}
	printf("\n==Dijkstra==\n");
	for(int i = 1; i < s+1; i++)
		printf(" %2d  = %2d\n",i,dis[i]);
}

void graph::prim(int n){
	int total = 0, i, k, j, x, y, min, sum = 0;
	bool set[s+1];
	for(i = 0; i < s+1; i++)
		set[i] = false;

	set[n] = true;
	
	printf("\n==PRIM==\n");
	while(total < s-1){
		min = INT_MAX;
		x = 0;
		y = 0;
		for(i = 1; i < s+1; i++){
			if(set[i]){
				for(j = 1; j < s+1; j++){
					if(!set[j] && a[i][j]){
						if(min > a[i][j]){
							min = a[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		//if(x > 0)
		sum += a[x][y];
			printf(" %2d -> %2d  :  %2d\n",x,y,a[x][y]);
		set[y] = true;
		total++;
	}
	printf("\n Total Weight: %3d\n", sum);
}

void graph::kruskal(){
	int i, uRep, vRep;
	sort(G.begin(), G.end());
	for(i = 0; i < G.size(); i++){
		uRep = findSet(G[i].second.first);
		vRep = findSet(G[i].second.second);
		if(uRep != vRep){
			T.push_back(G[i]);
			unionSet(uRep,vRep);
		}
	}
	int sum = 0;
	printf("\n==Kruskal==\n");
	for(i = 0; i < T.size(); i++){
		printf(" %2d -> %2d  :  %2d\n",T[i].second.first,T[i].second.second,T[i].first);
		sum+=T[i].first;
	}
	printf("\n Total Weight: %2d\n",sum);
}

void graph::fw(){
	int cost[s+1][s+1], path[s+1][s+1];
	int k, i, j;
	for(k = 1; k < s+1; k++)
		for(i = 1; i < s+1; i++){
			cost[k][i] = a2[k][i];
			if(k == i)
				path[k][i] = 0;
			else if(cost[k][i] != INT_MAX)
				path[k][i] = k;
			else
				path[k][i] = -1;
		}

	for(k = 1; k < s+1; k++)
		for(i = 1; i < s+1; i++){
			for(j = 1; j < s+1; j++){
				if(cost[i][k] != INT_MAX && cost[k][j] != INT_MAX && cost[i][k] + cost[k][j] < cost [i][j] && i != j){
					cost[i][j] = cost[i][k] + cost[k][j];
					path[i][j] = path[k][j];
				}
				else if(i == j)
					cost[i][j] = 0;
			}
			if(cost[i][i] < 0){
				return;
			}
		}

	for(k = 1; k < s+1; k++){
		printf("\n Min Cost From Node %d\n", k);
		for(i = 1; i < s+1; i++)
			printf(" %2d ",cost[k][i]);
	}
}

int main( int argc, char *argv[] ){
	int size;
	int location;
	ifstream ifp;


	//checking to see if file was entered on command line
	if ( argc != 2 ){
		cout << "File was not entered\n";
		return 2;
	}

	ifp.open( argv[1] );

	// checking to see if file was opened successfully
	if( ! ifp.is_open() ){
		cout << "File could not be opened\n";
		return 3;
	}


	// reading in number of nodes
	ifp >> size;

	//create graph with an an adjadceny matrix of 
    // size = num of nodes x num of nodes
	graph g( size );

	//ask for starting location
	cout << "Enter the starting location: ";
	cin >> location;

	//fill adjacency matrix
	g.fill( ifp );

	//print the matrix
	g.mprint();
	cout << endl << endl;

	// calculate DFS
	g.dfs( location );
	cout << endl << endl;

	//calculate DFS-SP
	g.dfssp( location );
	cout << endl << endl;

	//calculate BFS
	g.bfs( location );
	cout << endl << endl;

	//calculate BFS-SP
	g.bfssp( location );
	cout << endl << endl;

//	auto start = high_resolution_clock::now();
	g.dij(location);
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stop-start);
	cout << endl << endl;
//	cout << "Total Time in Microseconds: " << duration.count() << endl;

	g.prim(location);
	cout << endl;

	g.kruskal();
	cout << endl;
	
//	auto start = high_resolution_clock::now();
 // 	g.fw();
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stop-start);
//	cout << endl << endl;
//	cout << "Total Time in Microseconds: " << duration.count() << endl;

	return 0;
}
