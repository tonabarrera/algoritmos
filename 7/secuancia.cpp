#include <iostream>
#include <string.h>
using namespace std;

int LCS(char *, char *);
int max_numeros(int, int, int, int);

int main(int argc, char const *argv[]){
    char cadena1[1000];
    char cadena2[1000];
    cin >> cadena1;
    cin >> cadena2;
    int longitud = LCS(cadena1, cadena2);
    cout << longitud;
    return 0;
}
// Encuentra la longitud de la secuencia comun mas larga entre dos cadenas
int LCS(char *cadena1, char *cadena2) {
    // Longitud de la cadena
    int longitud1 = strlen(cadena1);
    int longitud2 = strlen(cadena2);
    // Tabla para guardar datos ya calculados
    int tabla[2][longitud2+1];
    // Alternar entre las dos filas de la tabla
    int actual = 1;
    int anterior = 0;
    // Inicializamos nuestra tabla
    for (int i = 0; i < 2; i++)
        for(int j = 0; j<=longitud2; j++)
            tabla[i][j] = 0;
    // Implementacion bottom up
    for (int i = 1; i <= longitud1; ++i){
        for (int j = 1; j <= longitud2; j++){
            if (cadena1[i-1] == cadena2[j-1])
                tabla[actual][j] = tabla[anterior][j-1] + 1;
            else if (tabla[anterior][j] >= tabla[actual][j-1])
                tabla[actual][j] = tabla[anterior][j];
            else
                tabla[actual][j] = tabla[actual][j-1];

        }
        actual = !actual;
        anterior = !anterior;
    }

    return tabla[anterior][longitud2];
    //return max_numeros(tabla[actual][longitud2], tabla[actual][longitud2-1], tabla[anterior][longitud2], tabla[anterior][longitud2-1]);
}

int max_numeros(int a, int b, int c, int d) {
    if (a > b)
        if (a > c)
            if (a > d)
                return a;
            else
                return d;
        else if (c > d)
            return c;
        else
            return d;
    else
        if (b > c)
            if (b > d)
                return b;
            else
                return d;
        else
            if (c > d)
                return c;
            else
                return d;
}