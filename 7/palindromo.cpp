#include <iostream>
#include <string.h>
using namespace std;

int palindromo(char *, int, int, int**);
int minimo(int, int);
int tam;
int main(int argc, char const *argv[]) {    
    // Captura del numero de casos
    int t;
    cin >> t;
    while (t--) {
        // Captura de los datos
        char palabra[6100];
        cin >> palabra;
        tam = strlen(palabra);
        // Tabla para utilizar el modelo top down
        int **tabla = (int**) malloc(tam* sizeof(int*));
        for (int i = 0; i < tam; i++){
            tabla[i] = (int*) malloc(tam * sizeof(int));
            for (int j = 0; j < tam; j++)
                tabla[i][j] = -1;
        }
        // Impresion del resultado
        int k = palindromo(palabra, 0, tam-1, tabla);

        for (int i = 0; i < tam;  i++){
            for (int j = 0; j < tam;  j++)
                printf("%d ", tabla[i][j]);
        printf("\n");
        }

        printf("%d\n", k);

    }

    return 0;
}
// Encuentra el numero de cambios minimos para volver una palabra palindromo
int palindromo(char *palabra, int i, int j, int **tabla) {
    printf("%s\n", "MATRIZ");
    for (int k=0; k<tam; k++){
            for(int l=0;l<tam; l++){
                printf("%d ", tabla[k][l]);
            }
            printf("\n");
    }
    // Los extremos de la palabra no coinciden
    if (i < j && (palabra[i] != palabra[j])){
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = minimo(palindromo(palabra, i, j-1, tabla), 
            palindromo(palabra, i+1, j, tabla)) + 1;
        return tabla[i][j];
    // Coincidencia entre los extremos de la palabra
    } else if (palabra[i] == palabra[j] && (i < j)) {
        if (tabla[i][j] != -1)
            return tabla[i][j];
        tabla[i][j] = palindromo(palabra, i+1, j-1, tabla);
        return tabla[i][j];
    }
    // Caso en el que no tenemos mas caracteres que analizar en la palabra
    return 0;
}

int minimo(int a, int b) {
    if (a < b)
        return a;
    return b;
}