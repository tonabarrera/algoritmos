#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int mayor(int, int, int);
int tomar_piedras(int, int, int **, int **);
void obtener_max_piedras();

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        obtener_max_piedras();
    }
    return 0;
}

void obtener_max_piedras() {
    int H;
    int W;

    cin >> H >> W;

    int **matriz = (int**) malloc(H * sizeof(int*));
    int **tabla = (int**) malloc(2 * sizeof(int*));
    tabla[0] = (int*) malloc(W * sizeof(int));
    tabla[1] = (int*) malloc(W * sizeof(int));
    for (int i = 0; i < H; i++){
        matriz[i] = (int*) malloc(W * sizeof(int));
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> matriz[i][j];
        }
    }
    for (int j = 0; j < W; j++)
        tabla[0][j] = matriz[H-1][j];

    short actual = 1;
    short pre = 0;
    for (int i = H-2; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            if (j == 0)
                tabla[actual][j] = mayor(tabla[pre][j], tabla[pre][j+1], -10) + matriz[i][j];
            else if (j == W-1)
                tabla[actual][j] = mayor(tabla[pre][j], tabla[pre][j-1], -10) + matriz[i][j];
            else
                tabla[actual][j] = mayor(tabla[pre][j-1], tabla[pre][j], tabla[pre][j+1]) + matriz[i][j];
        }
        actual = !actual;
        pre =!pre;
    }
    
    int maximo = tabla[pre][0];
    int aux = -1;

    for (int j = 1; j < W; j++) {
        aux = tabla[pre][j];
        if (maximo < aux)
            maximo = aux;
    }

    cout << maximo << endl;
}

int mayor(int a, int b, int c) {
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
/*
int tomar_piedras(int i, int j, int **matriz, int **tabla) {
    if (j >= W || j < 0){
        return -10000;
    }
    if (tabla[i][j] != -1)
            return tabla[i][j];
    if (i < H-1){
        tabla[i][j] = matriz[i][j] + mayor(tomar_piedras(i+1, j-1, matriz, tabla), tomar_piedras(i+1, j, matriz, tabla), tomar_piedras(i+1, j+1, matriz, tabla));
        return tabla[i][j];
    }
    return matriz[i][j];
}
*/