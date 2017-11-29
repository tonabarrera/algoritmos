#include <stdio.h>
int main(int argc, char const *argv[]) {
    int N, K;
    scanf("%d %d", &N, &K);
    if (K>=N){
        printf("%d", -1);
        return 0;
    }
    if (K == N-1)
        printf("%d ", 1);
    else
        printf("%d ", N);
    int i;
    for (i = 2; i<=K+1; i++)
        printf("%d ", i);
    if (K != N-1){
        printf("%d ", 1);
        for (int j = i; j<N; j++)
            printf("%d ", j);
    }
    return 0;
}

// 1 2 3 4 5
//