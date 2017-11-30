#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


struct Nodo {
    unsigned long long valor;
    int indice;
};

bool comparacion(struct Nodo a, struct Nodo b) {
    return (a.valor < b.valor);
}

int main(int argc, char const *argv[]) {
    int N, M, K;
    cin >> N >> M >> K;
    struct Nodo *entrada = (struct Nodo*)malloc(M * sizeof(struct Nodo));
    unsigned long long tipo, A, B;

    for (int i = 0; i < N; i++)
        cin >> tipo >> A >> B;
    
    for (int i = 0; i < M; i++){
        cin >> entrada[i].valor;
        entrada[i].indice = i+1;
    }
    if (K != 0){
        int salida[K];
        sort(entrada, entrada+M, comparacion);
        int j = 0;
        for (int i = M-K; i < M; i++)
            salida[j++] = entrada[i].indice;

        sort(salida, salida+K);
        for (int i = 0; i < K; i++)
            cout << salida[i] << " ";
    }
    
    return 0;
}