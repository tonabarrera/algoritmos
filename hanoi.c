#include <stdio.h>

void move(int n, char src, char aux, char dest) {
    if (n>1) {
        move(n-1, src, dest, aux);
        printf("Mover de %c a %c\n", src, dest);
        move(n-1, aux, src, dest);
    }
    if (n==1){
        printf("Mover de %c a %c\n", src, dest);
        return;
    }
    return;
}

int hanoi(int n){
    move(n, 'A', 'B', 'C');
    return 0;
}
