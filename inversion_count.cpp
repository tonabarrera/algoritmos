#include <stdio.h>
#include <stdlib.h>

/*Definicion de funciones auxiliares*/
long long merge_sort(long *, long, long);
long long merge(long *, long, long, long);

/*Caputra los elementos de cada caso de prueba*/
long long obtener_inversiones() {
    long n;
    scanf("%ld", &n);
    long dato;
    long *arreglo = (long*)malloc(sizeof(long)*n);
    for (long i = 0; i < n; i++) {
        scanf("%ld", &dato);
        arreglo[i] = dato;
    }

    return merge_sort(arreglo, 0, n-1);
}

/*Funcion principal para capturar los datos y mostar los resultados*/
int main(void){
    int pruebas;
    int i;
    scanf("%d", &pruebas);
    char c;
    scanf("%c", &c);
    long long resultados[pruebas];

    for (i = 0; i < pruebas; i++) {
        resultados[i] = obtener_inversiones();
        scanf("%c", &c);
    }
    scanf("%c", &c);
    for (i = 0; i < pruebas; i++)
        printf("%lld\n", resultados[i]);

    
    return 0;
}

/*Funcion que se encarga de dividir el array de numeros
* y obtener el total de inversiones*/
long long merge_sort(long *arreglo, long inicio, long fin) {
    long long total = 0;
    if (inicio < fin) {
        long mitad = (inicio + fin) / 2;
        total += merge_sort(arreglo, inicio, mitad);
        total += merge_sort(arreglo, mitad+1, fin);
        total += merge(arreglo, inicio, mitad, fin);
    }
    return total;
}

/*Funcion que cuenta el total de inversiones con base al algoritmo de
* ordenamiento merge-sort*/
long long merge(long *arreglo, long inicio, long mitad, long fin) {
    long n = mitad - inicio;
    long n2 = fin - mitad;
    long izq[n];
    long der[n2];
    for (long i=0; i<=n; i++){
        izq[i] = arreglo[inicio+i];
    }
    for (long i=0; i<n2; i++){
        der[i] = arreglo[mitad+i+1];
    }
    long i = n;
    long j = n2-1;
    long k = fin;
    long long total = 0;
    while (i > -1 || j >-1) {
        if (i > -1 && j >-1) {
            if (izq[i] < der[j]) {
                arreglo[k--] = der[j--];
            } else {
                total += j+1;
                arreglo[k--] = izq[i--];
            }
        } else if (i > -1) {
            arreglo[k--] = izq[i--];
        } else {
            arreglo[k--] = der[j--];
        }
    }
    return total;
}