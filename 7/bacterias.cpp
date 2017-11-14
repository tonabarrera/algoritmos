#include <iostream>
#include <sstream>
using namespace std;

int minimo(int, int);
int minimo_quimico(int, int, int **, int **);
int fila;
int col;
int main(int argc, char const *argv[]) {
    string str;
    getline(cin, str);
    stringstream is(str);
    is >> fila;
    is >> col;

    int **quimicos = (int**) malloc(fila * sizeof(int*));
    int **tabla = (int**) malloc(fila * sizeof(int*));
    for (int i = 0; i < fila; i++){
        quimicos[i] = (int*) malloc(col * sizeof(int));
        tabla[i] = (int*) malloc(col * sizeof(int));            
    }

    for (int i = 0; i < fila; i++){
        string str2;
        getline(cin, str2);
        stringstream is(str2);
        for (int j = 0; j < col; j++){
            int k;
            is >> k;
            quimicos[i][j] = k;
            tabla[i][j] = -1;
        }
    }
    tabla[fila-1][col-1] = quimicos[fila-1][col-1];

    cout << minimo_quimico(0, 0, quimicos, tabla);
    return 0;
}

int minimo_quimico(int i, int j, int **quimicos, int **tabla) {
    if (tabla[i][j] != -1)
        return tabla[i][j];
    if (i == fila-1 && j == col-1){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = quimicos[i][j];
        return tabla[i][j];
    }
    else if (i == fila-1 && j < col){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = minimo_quimico(i, j+1, quimicos, tabla) + quimicos[i][j];
        return tabla[i][j];
    }
    else if (i < fila && j == col-1){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = minimo_quimico(i+1, j, quimicos, tabla) + quimicos[i][j];
        return tabla[i][j];
    }
    else{
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = minimo(minimo_quimico(i+1, j, quimicos, tabla), minimo_quimico(i, j+1, quimicos, tabla)) + quimicos[i][j];
        return tabla[i][j];
    }
}

int minimo(int a, int b) {
    if (a < b)
        return a;
    else return b;
}