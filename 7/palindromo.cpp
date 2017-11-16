#include <iostream>
#include <string.h>
using namespace std;

int palindromo(char *, int, int, int**);
int minimo(int, int);

int main(int argc, char const *argv[]) {    
    int t;
    cin >> t;
    while (t--) {
        char palabra[6100];
        cin >> palabra;
        int tam = strlen(palabra);
        int **tabla = (int**) malloc(tam* sizeof(int*));
        for (int i = 0; i < tam; i++){
            tabla[i] = (int*) malloc(tam * sizeof(int));
            for (int j = 0; j < tam; j++)
                tabla[i][j] = -1;
        }
        cout << palindromo(palabra, 0, tam-1, tabla) << endl;
    }

    return 0;
}

int palindromo(char *palabra, int i, int j, int **tabla) {
    if (i < j && (palabra[i] != palabra[j])){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = minimo(palindromo(palabra, i, j-1, tabla), 
            palindromo(palabra, i+1, j, tabla)) + 1;
        return tabla[i][j];
    } else if (palabra[i] == palabra[j] && (i < j)) {
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = palindromo(palabra, i+1, j-1, tabla);
        return tabla[i][j];
    }
    return 0;
}

int minimo(int a, int b) {
    if (a < b)
        return a;
    return b;
}