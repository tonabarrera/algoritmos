#include <stdio.h>
int v[50];
int fibo(int n){
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}
int fibo_memoria(int n) {
    if (v[n]!=0)
        return v[n];
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    v[n] = fibo_memoria(n-1)+fibo_memoria(n-2);
    return v[n];
}

int main(void){
    printf("Fibonacci %lld\n", fibo_memoria(45));
    printf("Fibonnaci %lld", fibo(45));
    return 0;
}
