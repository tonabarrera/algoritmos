#include <iostream>
#include <string>
using namespace std;

long greedy_soldados();
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    // Capturamos el numero de casos
    int T;
    cin >> T;
    while (T--) {
        cout << greedy_soldados() << "\n";
    }
    return 0;
}

long greedy_soldados() {
    string soldados;
    // Leemos la cadena
    cin >> soldados;
    long tam = soldados.size();
    long movimientos = 0;
    /* 
    * Para contar grupos de ceros que maximicen
    * el numero de movimientos
    */
    bool grupo = true;
    long total = 0;
    // Leemos la cadena del final al inicio
    for (long i = tam-1; i > -1; i--) {
        /*
        * Si vemos un cero contamos un grupo y cuando
        * encontremos un uno termina ese grupo
        */
        if (soldados[i] == '0' && grupo) {
            movimientos++;
            grupo = false;
        } else if (soldados[i] == '1' && !grupo) {
            grupo = true;
        }
        /*
        * Encontramos un soldado y tenemos que calcular
        * sus movimientos
        */
        if (soldados[i] == '1'){
            total += movimientos + (tam - 1 - i);
            tam--;
        }
    }
    return total;
}