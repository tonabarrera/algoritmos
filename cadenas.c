#include <stdio.h>

char C[21];

void cadenas(int n, int c) {
    int i;
    if (n==0)
        printf("%s |\n", C);
    else
        for (i='a'; i<'a'+c; i++) {
            C[n] = i;
            //printf("%c", C[n]);
            cadenas(n-1, c);
        }
}

int main(void) {
    cadenas(3, 3);
    return 0;
}
