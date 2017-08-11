#include <stdio.h>
int valor[51][51];
int pascal (int i, int j) {
    if (j==1 || i==j)
        return 1;
    if (valor[i][j] != 0)
        return valor[i][j];

    valor[i][j] = pascal(i-1, j-1)+pascal(i-1, j);
    return valor[i][j];
}
int main(void){
    printf("%d", pascal(15, 5));
    return 0;
}
