
 #include <iostream>
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

 	Gr.resize(n); //задаем список смежности

 	while (in.peek() != EOF){ //Считываем попарно из файла x y
 		int x, y;
 		in >> x >> y;
 		if (x > n || y > n) {

 		}
 		else {
 			Gr[x].push_back(y);
 		}
 	}

 	for (int i = 0; i < n; i++){
 		sort(Gr[i].begin(), Gr[i].end());
 		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
 	}

 	cout << "\nСписок смежности;\n";
 	for (int i = 0; i < n; i++) {
 		cout << "x = " << i << ": ";
 		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
 			cout << *it << ' ';
 		}
 		cout << endl;
 	}


 	cout << "\nВведите вершину x = ";
 	int x;
 	cin >> x;
    int cnt;
 	for (int i = 0; i < n; i++){
        if (i == x)
            cnt+=Gr[i].size();
 		for (auto it = Gr[i].begin(); it != Gr[i].end(); it++) {
 			if (*it == x)
                cnt++;
 		}
 	}

 	cout << "\nКоличество вершин, смежных с данной: " << cnt << "\n";

 	return 0;
 } 