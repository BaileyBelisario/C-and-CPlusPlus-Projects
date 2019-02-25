#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define DBP 0

struct treenode
{
	int dat;
	treenode *lchild;
	treenode *rchild;
};

class bstree
{
	public:
		bstree();
		void in( );
		void pre( );
		void post( );
		void paren( );
		void insert( int x );
		void remove(int remdat );
		void search( int x ); 
		int numnodes();
		int height();
	private:
		treenode *root;
		void in( treenode *t );
		void pre( treenode *t );
		void post( treenode *t );
		void paren( treenode *t );
		void insert( treenode *t, treenode *n );
		void search( treenode *t, int x );
		int _numnodes(treenode *t);
		int _height(treenode *t);
		treenode *findmin(treenode *t);
		treenode *remove(treenode *t, int remdat);
		treenode *findval( int x, treenode *t);
};

bstree::bstree()
{  
		root = NULL;
}

void bstree::in(treenode * t)
{
	if ( t == NULL )
		 return;

	in(t->lchild);
	printf("%2d ", t->dat);
	in(t->rchild);
}

void bstree::pre(treenode * t)
{
	if ( t == NULL )
		 return;

	printf("%2d ", t->dat);
	pre(t->lchild);
	pre(t->rchild);
}

void bstree::post(treenode * t)
{
	if(t == NULL)
		return;
	post(t->lchild);
	post(t->rchild);
	printf("%2d ", t->dat);
}

void bstree::paren(treenode * t)
{
	if(t==NULL)
		return;
	printf("(%2d ",t->dat);
	if(t->lchild == NULL && t->rchild == NULL)
		printf("()()");
	else if(t->rchild == NULL){
		printf("()");
		paren(t->lchild);
	}
	else if(t->lchild == NULL){
		printf("()");
		paren(t->rchild);
	}
	else{
		paren(t->lchild);
		paren(t->rchild);
	}
	printf(")");
}

void bstree::in()
{
	in(root);
}

void bstree::pre()
{
	pre(root);
}

void bstree::post()
{
	post(root);
}

void bstree::paren()
{
	paren(root);
}

void bstree::insert( int x )
{
	treenode *t1;

	t1 = new treenode();
	t1->dat = x;
	t1->lchild = NULL;
	t1->rchild = NULL;

	if(root == NULL)
		root = t1;
	else
		insert(root,t1);
}

void bstree::insert( treenode *t, treenode *n )
{
	if(n->dat > t->dat){
		if(t->rchild == NULL)
			t->rchild = n;
		else
			insert(t->rchild,n);
	}
	else if(n->dat < t->dat){
		if(t->lchild == NULL)
			t->lchild = n;
		else
			insert(t->lchild,n);
	}
}
void bstree::search( int x ){
	search(root, x);
}
void bstree::search( treenode *t, int x){
	if(t == NULL){
		printf("%d is not in the tree\n", x);
		return;
	}
	if(t->dat == x)
		printf("%d is in the tree\n", x);
	else if(x < t->dat)
		search(t->lchild, x);
	else if(x > t->dat)
		search(t->rchild, x);
}
treenode *bstree::findval( int x, treenode *t)
{
	if(t == NULL)
		return NULL;
	else{
		if(t->dat < x)
			return findval(x,t->lchild);
		else if(t->dat > x)
			return findval(x,t->rchild);
	}
	return t;
}

void bstree::remove(int remdat){
	root = remove(root, remdat);
}

treenode *bstree::remove(treenode *t, int remdat) {
  
  if (t == NULL)
     return NULL;

  if (remdat < t->dat)  // data is in the left sub tree.
      t->lchild = remove(t->lchild, remdat);

  else if (remdat > t->dat) // data is in the right sub tree.
      t->rchild = remove(t->rchild, remdat);

  else {
     // no children
     if (t->lchild == NULL && t->rchild == NULL) {
        delete(t); // delete the tree and set it to NULL or remove the leaf
        t = NULL;
     }
     // one child (rchild)
     else if (t->lchild == NULL) 
        t = t->rchild;
     // one child (lchild)
     else if (t->rchild == NULL) 
        t = t->lchild;
     // two children
     else {
        treenode *temp = findmin(t->rchild); // find minimum value of right sub tree
        t->dat = temp->dat; // copy the data to be inserted to remove
        t->rchild = remove(t->rchild, temp->dat); // delete the duplicate node
     }
  }
  return t; // return the tree
}

treenode *bstree::findmin(treenode *t) {
   if (t == NULL)
      return NULL;

   if (t->lchild != NULL)
      return findmin(t->lchild); // only need to search the left tree for the min node

   return t;
}

int bstree::_numnodes(treenode * t)
{
	int lc, rc;
	if(t == NULL)
		return 0;

	lc = _numnodes(t->lchild);
	rc = _numnodes(t->rchild);
	return 1 + lc + rc;
}

int bstree::numnodes()
{
	int ans;
	ans = _numnodes(root);
	return ans;
}

int bstree::_height(treenode * t)
{
	int lh, rh;
	if(t == NULL)
		return 0;
	lh = _height(t->lchild);
	rh = _height(t->rchild);
	if(lh > rh)
		return lh + 1;
	else
		return rh + 1;
}

int bstree::height()
{
	int ans;
	ans = _height(root);
	return ans;
}


int main(int argc, char *argv[])
{
	bstree * t;
	int i, x, cmd, val;
	ifstream ifp;

	if (argc != 2)
	{
		cout << "ERROR:  no BST CMD file " << endl;
		return 2;
	}

	ifp.open( argv[1] );

	if ( ! ifp.is_open() )
	{
		 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
		 return 3;
	}

	t = new bstree();
	// read the command file
	
	ifp >> cmd;
	while(cmd!=0){
		switch(cmd){
			case -1:
					ifp >> val;
					t->remove(val);
					break;
			case 1: ifp >> val;
					t->insert(val);
					break;
			case 2: ifp >> val;
					cout << "Searching...";
					cout << endl;
					t->search(val);
					break;
			case 3: cout << "Preorder: ";
					t->pre();
					cout << endl;
					break;
			case 4: cout << "In Order: ";
					t->in();
					cout << endl;
					break;
			case 5: cout << "Postorder: ";
					t->post();
					cout << endl;
					break;
			case 6:
					cout << "Parenthesis: ";
					t->paren();
					cout << endl;
					break;
			case 7:
					cout<<t->numnodes();
					break;
			case 8: cout<<t->height();
					break;
		}
		ifp >> cmd;
	}

	return 0;
}


