#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

struct tree
{
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

tree *node(int x){ 
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL; 
    n->parent = NULL;
    return n;
}

void create(tree *&tr, int n){ 
    int x;
    if(n>0){
        cin >> x;
        tr = node(x);
        int nl = n/2;
        int nr = n - nl - 1; 
        create(tr->left, nl); 
        create(tr ->right,nr);
    } 
}

void preorder(tree *tr){
    if (tr) {
        if (!tr->right && !tr->left){
            cout << tr->inf << " ";
        }
        preorder(tr->left); 
        preorder(tr->right);
    }
}

int lefth(tree *tr){ 
    int k=0;
    tree *x = tr; 
    while (x){
        k++;
        x = x->left; 
    }
    return k - 1; 
}

int righth(tree *tr){ 
    int k=0;
    tree *x = tr; 
    while (x){
        k++;
        x = x->right; 
    }
    return k - 1; 
}

void print(tree* tr, int k) {
	if (!tr) {
		cout << "Ответ: дерево - пустое\n";
	}

	else {
		queue<tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;

		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
					cout << ' ';
			}

			tree* buf = cur.front();
			cur.pop();
			j++;

			if (buf) {
				cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';
			}

			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
					cout << ' ';

				cout << ' ';

			}

			if (cur.empty()) {
				cout << endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}

void add(tree *&tr, int x){ 
    tree *n = node(x);
    tree *y = tr;
    if (lefth(tr) == righth(tr)){
        do{
            y = y->left;
        }
        while (y->left);
        if (!y->left) 
            y->left = n; 
        else y->right = n;
        } 
    else{
        do{
            y = y->right;
        }
        while (y->right);
        if (!y->left) 
        y->left = n; 
        else 
            y->right = n;
    } 
}

void find(tree *tr, int x, tree *&res){ 
    if (tr){
        if (tr->inf == x){ 
            res = tr;
        }
        else {
            find(tr->left, x, res);
            find(tr->right, x, res); 
        }
    } 
}

int main() {

	int n;
	cout << "n = ";
	cin >> n;

	cout << endl << "Введите числовые данные для дерева: " << endl;
	tree* tr = NULL;
	create(tr, n);
	int k = int(log((float)n) / log((float)2.0));
	print(tr, k);

    cout << "Answer: " << endl;
	preorder(tr);
    cout << endl;
	return 0;
}

//5 3 7 1 9 4 2 8 6 0
//4 5 3 7 8 6 9 1 2 0
