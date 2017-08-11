#include <stdio.h>
/*Dado un array de enteros v y dados dos enteros a & b, regrese
 * el número más grande en v[a...b]*/

int maximo(int v[], int a, int b) {
    int max1, max2;
    if (a<b) {
        max1 = maximo(v, a, (a+b)/2);
        max2 = maximo(v, (a+b)/2+1, b);
        if (max1>max2)
            return max1;
        else
            return max2;
    } else
        return v[a];
}
