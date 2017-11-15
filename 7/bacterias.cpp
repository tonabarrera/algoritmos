#include <iostream>
#include <stdlib.h>
using namespace std;

int minimo(int, int);
int minimo_quimico(int, int, int **, int **);
// Dimensiones de la matriz
int fila;
int col;

int main(int argc, char const *argv[]) {
    cin >> fila >> col;
    // matriz de los datos de entrada
    int **quimicos = (int**) malloc(fila * sizeof(int*));
    // Tabla para guardar datos ya calculados
    int **tabla = (int**) malloc(fila * sizeof(int*));
    for (int i = 0; i < fila; i++){
        quimicos[i] = (int*) malloc(col * sizeof(int));
        tabla[i] = (int*) malloc(col * sizeof(int));
    }
    // Entrada de datos
    for (int i = 0; i < fila; i++)
        for (int j = 0; j < col; j++){
            cin >> quimicos[i][j];
            tabla[i][j] = -1;
        }
    // Inicializacion de la tabla auxiliar
    tabla[fila-1][col-1] = quimicos[fila-1][col-1];

    for (int j = col-2; j > -1; j--)
        tabla[fila-1][j] = tabla[fila-1][j+1] + quimicos[fila-1][j];

    for (int i = fila-2; i > -1; i--)
        tabla[i][col-1] = tabla[i+1][col-1] + quimicos[i][col-1];

    // Imprimimos el resultado
    cout << minimo_quimico(0, 0, quimicos, tabla);
    return 0;
}
// BUscamos el menor quimico por top-down
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
// Obtiene el minimo de dos numeros
int minimo(int a, int b) {
    if (a < b)
        return a;
    else return b;
}