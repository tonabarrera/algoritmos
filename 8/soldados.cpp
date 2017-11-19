#include <iostream>
#include <string>
using namespace std;

long greedy_soldados();
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cout << greedy_soldados() << "\n";
    }
    return 0;
}

long greedy_soldados() {
    string soldados;
    cin >> soldados;
    long tam = soldados.size();
    long movimientos = 0;
    bool grupo = true;
    long total = 0;
    for (long i = tam-1; i > -1; i--) {
        if (soldados[i] == '0' && grupo) {
            movimientos++;
            grupo = false;
        } else if (soldados[i] == '1' && !grupo) {
            grupo = true;
        }
        if (soldados[i] == '1'){
            total += movimientos + (tam - 1 - i);
            tam--;
        }
    }
    return total;
}