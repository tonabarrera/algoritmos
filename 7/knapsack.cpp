#include <iostream>
#include <sstream>
using namespace std;

int objetos[2][2000];
int cantidad;
int capacidad;

int max_valor(int, int, int **);
int mayor(int, int);

int main(int argc, char const *argv[]) {
    string str;
    getline(cin, str);
    stringstream is(str);
    is >> capacidad;
    
    is >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        string str2;
        getline(cin, str2);
        stringstream is(str2);
        int k;

        is >> k;
        objetos[0][i] = k;

        is >> k;
        objetos[1][i] = k;
    }
    int **tabla = (int**) malloc((capacidad+1) * sizeof(int*));
    for (int i = 0; i < capacidad+1; i++){
        tabla[i] = (int*)malloc((cantidad+1) * sizeof(int));
        for (int j =0; j < cantidad+1; j++)
            tabla[i][j] = -1;
    }
    cout << max_valor(capacidad, 0, tabla);
    return 0;
}

int max_valor(int j, int i, int **tabla) {
    if (tabla[j][i] != -1)
        return tabla[j][i];
    if (j < objetos[0][i]){
        if (tabla[j][i] == -1)
            tabla[j][i] = max_valor(j, i+1, tabla);
        return tabla[j][i];
    } else if (j <= 0 || i >=cantidad){
        if (tabla[j][i] == -1)
            tabla[j][i] = 0;
        return 0;
    } else{
        if (tabla[j][i] == -1)
            tabla[j][i] = mayor(max_valor(j-objetos[0][i], i+1, tabla)+objetos[1][i], max_valor(j, i+1, tabla));
        return tabla[j][i];
    }
}

int mayor(int a, int b) {
    if (a > b)
        return a;
    return b;
}