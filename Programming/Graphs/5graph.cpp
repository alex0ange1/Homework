#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<vector<int>> Gr;			//Список смежности
vector<int> used;				//Список посещенных вершин
vector<int> path;				//Список вершин, которые показывают путь
queue<int> q;

ifstream in("input1.txt");

vector<int> go_in_width(int &n, int start, int end) {
    vector<int> parent(n, -1);
    used.resize(n);
 	used[start] = 1;
 	path.push_back(start);
    q.push(start);
    while (!q.empty()){
        int curel = q.front();
        q.pop();
        
        if (curel == end){
            int el = curel;
            while (el != -1){ //Восстановление пути от конечной вершины к начальной
                path.push_back(el);
                el = parent[el];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        for (int i = 0; i < Gr[curel].size(); i++){
            if (used[Gr[curel][i]] == 0){
                used[Gr[curel][i]] = 1;
                parent[i] = curel;
                q.push(i);
            }
        }
    }

    return {};
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
    vector<int> answer = go_in_width(n, 0, 1);
    cout << "The path is " << endl;
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << "->";
    }
    cout << endl;
 } 