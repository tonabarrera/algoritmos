#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *, int, int);
void merge(int *, int, int, int);
long long int inversiones = 0;

long long int obtener_inversiones() {
    inversiones = 0;
    long int n;
    scanf("%ld", &n);
    long int dato;
    int *arreglo = (int*)malloc(sizeof(int)*n);
    for (long int i = 0; i < n; i++) {
        scanf("%ld", &dato);
        arreglo[i] = dato;
    }
    merge_sort(arreglo, 0, n-1);
    return inversiones;
}

int main(void){
    int pruebas;
    int i;
    scanf("%d", &pruebas);
    char c;
    scanf("%c", &c);
    long long int resultados[pruebas];

    for (i = 0; i < pruebas; i++) {
        resultados[i] = obtener_inversiones();
        scanf("%c", &c);
    }
    
    scanf("%c", &c);
    for (i = 0; i < pruebas; i++)
        printf("%lld\n", resultados[i]);

    
    return 0;
}

void merge_sort(int *arreglo, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        merge_sort(arreglo, inicio, mitad);
        merge_sort(arreglo, mitad+1, fin);
        merge(arreglo, inicio, mitad, fin);
    }
}

void merge(int *arreglo, int inicio, int mitad, int fin) {
    int n = mitad - inicio;
    int n2 = fin - mitad;
    int izq[n];
    int der[n2];
    for (int i=0; i<=n; i++){
        izq[i] = arreglo[inicio+i];
    }
    for (int i=0; i<n2; i++){
        der[i] = arreglo[mitad+i+1];
    }
    int i = n;
    int j = n2-1;
    int k = fin;
    while (i > -1 || j >-1) {
        if (i > -1 && j >-1) {
            if (izq[i] < der[j]) {
                arreglo[k--] = der[j--];
            } else {
                inversiones += j + 1;
                arreglo[k--] = izq[i--];
            }
        } else if (i > -1) {
            arreglo[k--] = izq[i--];
        } else {
            arreglo[k--] = der[j--];
        }
    }
}