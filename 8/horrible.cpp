#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


struct Nodo {
    unsigned long long valor;
    unsigned long long indice;
};

bool comparacion(struct Nodo a, struct Nodo b)
{
    return (a.valor < b.valor);
}

int main(int argc, char const *argv[]) {
    unsigned long long N, M, K;
    cin >> N >> M >> K;
    struct Nodo *entrada = (struct Nodo*)malloc(M * sizeof(struct Nodo));
    unsigned long long tipo, A, B;
    for (unsigned long long i = 0; i < N; i++)
        cin >> tipo >> A >> B;
    for (unsigned long long i=0; i < M; i++){
        cin >> entrada[i].valor;
        entrada[i].indice = i+1;
    }
    if (K != 0){
        sort(entrada, entrada+M, comparacion);
        for (unsigned long long i = M-K; i < M-1; i++)
            cout << entrada[i].indice << " ";
        cout << entrada[M-1].indice; 
    }
    
    return 0;
}