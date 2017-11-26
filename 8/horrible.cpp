#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[]) {
    unsigned long long N, M, K;
    cin >> N >> M >> K;
    unsigned long long salida[K];
    unsigned long long indices[K];
    unsigned long long entrada[M];
    unsigned long long tipo, A, B;
    for (unsigned long long i = 0; i < N; i++)
        cin >> tipo >> A >> B;
    for (unsigned long long i=0; i < M; i++)
        cin >> entrada[i];
    unsigned long long j = 0;
    salida[0] = entrada[0];
    indices[0] = 1;
    for (unsigned long long i=1; i < M; i++) {
        if (entrada[i] >= salida[j]) {
            printf("%llu\n", entrada[i]);
            unsigned long long aux = salida[j];
            unsigned long long aux2 = indices[j];
            salida[j] = entrada[i];
            indices[j] = i+1;
            if (j < K) {
                salida[++j] = aux;
                indices[j] = aux2;
            }
        } else {
            if (j < K-1) {
                salida[++j] = entrada[i];
                indices[j] = i+1;
            }
        }
    }
    if (K != 0){
    sort(indices, indices+K);
    for (unsigned long long i = 0; i < K-1; i++)
        printf("%llu ", indices[i]);
    printf("%llu", indices[K-1]);
    }
    return 0;
}