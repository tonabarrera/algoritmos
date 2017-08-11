#include <stdio.h>
int imprime_binario(int n) {
    if (n>=2) {
        imprime_binario(n/2);
        printf("%d", n%2);
    } else {
        printf("%d", n);
    }
}
int main(void) {
    imprime_binario(5);
}
