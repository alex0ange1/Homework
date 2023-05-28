
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
 	setlocale(LC_ALL, "RUS");	

 	vector<vector<int>> Gr;
 	int n, m;

 	cout << "Количество вершин = n = ";
 	in >> n;
 	cout << n << endl;

 	cout << "Количество ребер = m = ";
 	in >> m;
 	cout << m << endl;

 	Gr.resize(n); //Задаем список смежности

 	while (in.peek() != EOF) {	//Считываем попарно из файла x y
 		int x, y;
 		in >> x >> y;
 		//orient
 		if (x > n || y > n) {

 		}
 		else {
 			Gr[x].push_back(y);		//Граф ориентированный, поэтому в список смежности x добавляем y
 		}
 	}

 	for (int i = 0; i < n; i++) {	//Удаляем повторяющиеся эл-ты
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

 	cout << endl;
 	cout << "\nОтвет:\n\n";
 	for (int i = 0; i < n; i++) {
 		int count_zahod = 0;

 		for (int j = 0; j < n; j++) {
 			count_zahod += count(Gr[j].begin(), Gr[j].end(), i); //счётчик count_zahod увеличиваем, если можно ли попасть
                                                                //из данной вершины в вершину i, и так делаем с каждой вершиной
        }
 		cout << "Полустепень захода вершины " << i << " равна " << count_zahod << endl;
 	}
 	cout << endl;
 	return 0;
 }