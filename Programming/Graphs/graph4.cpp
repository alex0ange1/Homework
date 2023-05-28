#include <iostream>   //ïîäêëþ÷åíèå áèáëèîòåê
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<vector<int>> Gr;			//Список смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин, которые показывают путь

ifstream in("input1.txt");

void go_in_depth(int x, int &n) {
    used.resize(n);
 	used[x] = 1;
 	path.push_back(x);

    for (int i = 0; i < Gr[x].size(); i++){
        if (used[Gr[x][i]] == 0)
            go_in_depth(Gr[x][i], n);
    }
 }


void componet_svyaz(int x, int &n) {
 	used.clear();
 	while (used.empty()){
 		path.clear();
 		go_in_depth(x, n);
 		for (auto it = path.begin(); it != path.end(); it++) {
 			cout << *it << ' ';
 		}
 		cout << endl;
 	}
 }


int main() {
 	int n, m;

 	cout << "Количество вершин = n = ";
 	in >> n;
 	cout << n << endl;

 	cout << "Количество ребер = m = ";
 	in >> m;
 	cout << m << endl;

 	Gr.resize(n);					//Задаем список смежности

 	while (in.peek() != EOF) {		//Идем по файлу и считываем попарно x и y
 		int x, y;
 		in >> x >> y;
 		//orient
 		if (x > n || y > n) {

 		}
 		else {
 			Gr[x].push_back(y);		//Т.к. граф неориентированный, то в список смежности x добавляем y
 		}
 	}

 	for (int i = 0; i < n; i++) {	//Удаляем повторяющиеся элементы
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
    componet_svyaz(0, n);
    int cnt = 1;
    for (int i = 0; i < n; i++){
        if (used[i] == 0){
            componet_svyaz(i, n);
            cnt++;
        }
    }
    if (cnt > 1)
        cout << "Граф не является связным" << endl;
    else
        cout << "Граф является связным!" << endl;
 	return 0;
 } 