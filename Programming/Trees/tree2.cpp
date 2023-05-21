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

void inorder(tree* tr, int &count) {		//Симметричный - Л-К-П
	if (tr) {
		inorder(tr->left, count);
		inorder(tr->right, count);
	}
	
}

void insert(tree*& tr, int x) {			//функция вставки
	tree* n = node(x);

	if (!tr) {
		tr = n;	
	}

	else {
		tree* y = tr;
		
		while (y) {	
			if (n->inf > y->inf) {
				if (y->right) {
					y = y->right;
				}

				else {
					n->parent = y;
					y->right = n;
					break;
				}
			}

			else if (n->inf < y->inf) {
				if (y->left) {
					y = y->left;
				}

				else {
					n->parent = y;
					y->left = n;
					break;
				}
			}
		}
	}
}

tree *Min(tree *tr){//поиск min
    if (!tr->left) return tr;
    else return Min(tr->left);
}
tree *Max(tree *tr){//поиск max
    if (!tr->right) return tr;
    else return Max(tr->right);
}

tree *find(tree *tr, int x){//поиск
    if (!tr || x == tr->inf){
        cout << tr->inf << endl;
        return tr;
    }
    if (x < tr->inf){
        cout << tr->inf << endl;
        return find(tr->left, x);

    }
    else{
        cout << tr->inf << endl;
        return find(tr->right, x);
    }
}

tree* Path(tree *tr, int x){//поиск предыдущего 
    tree *n = find(tr, x);
    if (n->left)
        return Max(n->left);
    tree *y = n->parent;
    while(y && n == y->left){
        n = y;
        y = y ->parent; 
    }
    return y;
}

void print(tree *tr, int k){//вывод дерева
    if (! tr ) cout << "Empty tree\n"; 
    else{
        queue<tree*> cur, next; 
        tree *r = tr;
        cur.push(r) ;
        int j = 0;
        
        while (cur.size()){ 
            if(j==0){
                for (int i = 0; i < (int)pow(2.0, k) - 1; i++) 
                    cout << " ";
            }
            tree *buf = cur.front(); 
            cur.pop();
            j++;
            if (buf){
                cout << buf->inf;
                next.push(buf->left);
                next.push(buf->right); 
                for(int i=0;i<(int)pow(2.0,k+1)-1;i++)
                    cout << " "; 
            }
            if (!buf){
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << " "; 
                cout << " ";
            } 
            if(cur.empty()){
                cout << endl; 
                swap(cur, next); 
                j = 0;
                k--;
            } 
        }
    }
}

int main() {

	int n, x, el;
	cout << "n = ";
	cin >> n;

	cout << "Заполните дерево:" << endl;
	tree* tr = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(tr, x);
	}
    int k = int(log((float)n) / log((float)2.0));	
    print(tr, k);
    cout << "Введите элемент X" << endl;
    cin >> el;
	cout << "Ответ: " << endl;
    tree* tr1 = Path(tr, el);

	return 0;
}

//5 3 7 1 9 4 2 8 6 0
//4 5 3 7 8 6 9 1 2 0
