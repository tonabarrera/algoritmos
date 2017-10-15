#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

long int sumar_mitad(int *, long int, long int, long int);
long int maximo(long int, long int, long int);
long int maximo_sub_array(int *, long int, long int);
 
int main(int argc, char const *argv[]) {
    int inicio = 0;
    int n;
    string s;
    getline(cin, s);
    n = atoi(s.c_str());
    int *arreglo = (int*) malloc(sizeof(int) * n);
    string str;
    getline(cin, str);
    long int j = 0;
    istringstream is(str);
    long int k;
    while(is >> k) {
        arreglo[j++] = k;
    }
    long int maximo = maximo_sub_array(arreglo, inicio, n-1);
    cout << maximo;
    return 0;
}

long int maximo(long int a, long int b, long int c) {
    if (a > b)
        if (a > c)
            return a;
        else
            return c;
    else if (b > c)
        return b;
    else
        return c;        
}

long int maximo_sub_array(int *arreglo, long int inicio, long int final) {
    if (inicio == final)
        return arreglo[inicio];
    else {
        long int mitad = (inicio + final)/2;
        long int izq = maximo_sub_array(arreglo, inicio, mitad);
        long int der = maximo_sub_array(arreglo, mitad+1, final);
        long int centro = sumar_mitad(arreglo, inicio, mitad, final);

        return maximo(izq, der, centro);
    }
}

long int sumar_mitad(int *arreglo, long int inicio, long int mitad, long int final) {
    long int suma_izq = arreglo[mitad];
    long int suma_max_izq = arreglo[mitad];

    for (long int i = mitad-1; i >= inicio; i--) {
        suma_izq += arreglo[i];
        if (suma_izq > suma_max_izq)
            suma_max_izq = suma_izq;
    }

    long int suma_der = arreglo[mitad+1];
    long int suma_max_der = arreglo[mitad+1];

    for (long int i = mitad+2; i <= final; i++) {
        suma_der += arreglo[i];
        if (suma_der > suma_max_der)
            suma_max_der = suma_der;
    }

    return suma_max_der + suma_max_izq;
}