#include <iostream> 
#include <map>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream in("input1.txt");

int main() {
 	vector<vector<int>> Gr;	
 	int n, m;

 	cout << "Количество вершин = n = ";
 	in >> n;
 	cout << n << endl;

 	cout << "Количество ребер = m = ";
 	in >> m;
 	cout << m << endl;

 	Gr.resize(n);	//задаем список смежности

 	while (in.peek() != EOF) {	//Считываем попарно из файла x y
 		int x, y;
 		in >> x >> y;
 		//ne orient
 		if (x > n || y > n) {

 		}
 		else {
 			Gr[x].push_back(y);		//Граф неориентированный, поэтому в список смежности x добавляем y
 			Gr[y].push_back(x);		//Граф неориентированный, поэтому в список смежности y добавляем x
 		}
 	}

 	for (int i = 0; i < n; i++) {	//Удаляем повторяющиеся эл-ты (если есть)
 		sort(Gr[i].begin(), Gr[i].end());
 		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
 	}

 	cout << "\nСписок смежности:\n";
 	for (int i = 0; i < n; i++) {
 		cout << "x = " << i << ": ";
 		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
 			cout << *it << ' ';
 		}
 		cout << endl;
 	}

 	int a, b;
 	cout << "\nВведите вершину a = ";
 	cin >> a;
 	if (a>n-1){
        cout << "Такой вершины нет!" << endl;
        return 0;
    }

 	cout << "Введите вершину b = ";
 	cin >> b;
 	if (b>n-1){
        cout << "Такой вершины нет!" << endl;
        return 0;
    }
    if (a != b) {
        if (find(Gr[a].begin(), Gr[a].end(), b) == Gr[a].end()) {
            Gr[a].push_back(b); //Создаем ребро ab (тк граф ориентированный, то дополняем оба списка смежности, а не только один)
            sort(Gr[a].begin(), Gr[a].end());
        }
        if (find(Gr[b].begin(), Gr[b].end(), a) == Gr[b].end()) {
            Gr[b].push_back(a);
            sort(Gr[b].begin(), Gr[b].end());
        }
    }

    cout << "\nСписок смежности:\n"; 
    for (int i = 0; i < n; i++) { 
        cout << "x = " << i << ": ";
        for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
            cout << *it << ' ';
        }
        cout << endl;
    }
    cout << endl;
 	return 0;
}