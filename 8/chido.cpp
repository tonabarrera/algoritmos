#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Elemento {
    long T;
    int D;
};

long total = 0;

bool condicion(struct Elemento a, struct Elemento b) {
    return a.T*(total-a.D) < b.T*(total-b.D);
}

int main(int argc, char const *argv[]) {
    long N;
    scanf("%ld", &N);
    struct Elemento *arreglo = (struct Elemento *)malloc(N * sizeof(struct Elemento));
    for (long i = 0; i < N; i++) {
        scanf("%ld %d", &(arreglo[i].T), &(arreglo[i].D));
        total += arreglo[i].D;
    }
    sort(arreglo, arreglo+N, condicion);
    long salida = 0;
    for (long i = 0; i < N; i++) {
        salida += 2*arreglo[i].T* (total-arreglo[i].D);
        total = total-arreglo[i].D;
    }
    printf("%ld", salida);

    return 0;
}

/*
* 7 * 2 *2
* 4 * 2 * 2
* 2 * 2 * 3

*/