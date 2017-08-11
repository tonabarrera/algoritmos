#include <stdio.h>

int buscar(int v[], int a, int b, int x){
    if (a>=b){
        if (v[a]==x)
            return a;
        else
            return -1;
    }
    if (v[(a+b)/2]==x)
        return (a+b)/2;
    else if (v[(a+b)/2]>x)
        buscar(v, a, (a+b)/2-1, x);
    else
        buscar(v, (a+b)/2+1, b, x);
    return -1;
}

int buscar2(int v[], int a, int b, int x) {
    while (a<b) {
        if (v[(a+b)/2]==x)
            return (a+b)/2;
        else if (v[(a+b)/2]<x)
            a = (a+b)/2+1;
        else
            b = (a+b)/2-1;
        if (v[a]==x)
            return a;
        else
            return -1;

    }
}
