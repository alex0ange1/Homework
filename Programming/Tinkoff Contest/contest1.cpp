#include <iostream>
using namespace std;

int main(){
    int tarif, mgb, dopst, trafic;
    cin >> tarif >> mgb >> dopst >> trafic;
    int summa = tarif;
    if (trafic > mgb)
        summa += (trafic - mgb) * dopst;
    else
        summa = tarif;
    cout << summa << endl;
    return 0;
}