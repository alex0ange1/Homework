//Дано дерево. Вывести путь от корня до узла X.

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


tree *find(tree *tr, int x){//поиск
    if (!tr || x == tr->inf)//нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);//ищем по левой ветке 
    else
        return find(tr->right, x);//ищем по правой ветке 
}

void Path(tree *tr, int x){//поиск пути
    while (tr->inf != x){
        if (x < tr->inf){
            cout << tr->inf << endl;
            tr = tr->left;
        }
        if (x > tr->inf){
            cout << tr->inf << endl;
            tr = tr->right;
        }
    }
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
    Path(tr, el);

	return 0;
}

//5 3 7 1 9 4 2 8 6 0
//4 5 3 7 8 6 9 1 2 0