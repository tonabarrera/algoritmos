#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int H;
int W;

long mayor(long, long, long);
long tomar_piedras(int, int, int **, long **);
long obtener_max_piedras();

int main(int argc, char const *argv[]) {
    int T;
    string str;
    getline(cin, str);
    stringstream is(str);
    is >> T;
    long resultados[T];
    for (int k = 0; k < T; k++) {
        resultados[k] = obtener_max_piedras();
    }
    for (int k = 0; k < T-1; k++)
        printf("%ld\n", resultados[k]);
    printf("%ld", resultados[T-1]);
    return 0;
}

long obtener_max_piedras() {
    string str;
    getline(cin, str);
    stringstream is(str);
    is >> H;
    is >> W;

    int **matriz = (int**) malloc(H * sizeof(int*));
    long **tabla = (long**) malloc(H * sizeof(long*));
    for (int i = 0; i < H; i++){
        matriz[i] = (int*) malloc(W * sizeof(int));
        tabla[i] = (long*) malloc(W * sizeof(long));            
    }

    for (int i = 0; i < H; i++){
        string str2;
        getline(cin, str2);
        stringstream iss(str2);
        int k;
        int j = 0;
        while (iss >> k && j < W){
            is >> k;
            matriz[i][j] = k;
            tabla[i][j] = -1;
            j++;
        }
        if (j < W){
            for (; j < W; j++) {
                matriz[i][j] = 0;
                tabla[i][j] = -1;
            }
        }
    }

    long maximo = tomar_piedras(0, 0, matriz, tabla);
    long aux = -1;

    for (int i = 1; i < W; i++) {
        aux = tomar_piedras(0, i, matriz, tabla);
        if (maximo < aux)
            maximo = aux;
    }

    return maximo;
}

long tomar_piedras(int i, int j, int **matriz, long **tabla) {
    if (tabla[i][j] != -1)
        return tabla[i][j];
    if (j >= W || j < 0){
        return -10000;
    }
    if (i < H-1){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = mayor(tomar_piedras(i+1, j-1, matriz, tabla), tomar_piedras(i+1, j, matriz, tabla), tomar_piedras(i+1, j+1, matriz, tabla)) + matriz[i][j];
        return tabla[i][j];
    }
    else{
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = matriz[i][j];
        return tabla[i][j];
    }
}

long mayor(long a, long b, long c) {
    if (a > b)
        if (a > c)
            return a;
        else
            return c;
    else if (b > c)
        return b;
    else
        return c;
}