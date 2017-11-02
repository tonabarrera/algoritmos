#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// Estructura para trabajar las coordenadas de los puntos
struct Punto {
    double x;
    double y;
};
// Definicion de nuestras funciones
double encontrar_cercano(Punto [], int, int);
double encontrar_cercano_mitad(Punto [], int, double);
double min(double, double);
double distancia(Punto, Punto);
int compararX (const void *, const void *);
int compararY (const void *, const void *);
double cercano(Punto [], int, int);

// Funcion principal que realiza la captura de los valores de entrada y los almacena en
// un arreglo para trabajarlos
int main(int argc, char const *argv[]) {
    int n;
    string s;
    getline(cin, s);
    n = atoi(s.c_str());
    Punto puntos[n];

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        stringstream is(str);
        double k;

        is >> k;
        puntos[i].x = k;

        is >> k;
        puntos[i].y = k;
    }

    // ordenar puntos
    qsort(puntos, n, sizeof(Punto), compararX);

    double punto_cercano = encontrar_cercano(puntos, 0, n-1);
    printf("%.3f", punto_cercano);
    return 0;
}

// Realiza una busqueda de los puntos mas cercanos sobre un arreglo de maximo tres elementos
double cercano(Punto P[], int inicio, int fin) {
    double min = distancia(P[inicio], P[inicio+1]);
    for (int i = inicio; i < fin; ++i)
        for (int j = i+1; j <= fin; ++j){
            if (distancia(P[i], P[j]) < min){
                min = distancia(P[i], P[j]);
            }
        }

    return min;
}

// Realiza la busqueda la distancia mas corta entre dos puntos
// de manera recursiva y recibiendo como parametro el arreglo de puntos
// ordenados por la coordenada x, el inicio del arreglo y su final
// devuelve la distancia mas corta
double encontrar_cercano(Punto puntos[], int inicio, int fin) {
    if ((fin - inicio) <3)
        return cercano(puntos, inicio, fin);
    int mitad = (fin + inicio)/2;
    Punto punto_medio = puntos[mitad];

    double cercano_izq = encontrar_cercano(puntos, inicio, mitad);
    double cercano_der = encontrar_cercano(puntos, mitad+1, fin);
    double minimo = min(cercano_izq, cercano_der);
    Punto puntos_mitad[fin+1];
    int j = 0;
    for (int i = inicio; i < fin; i++)
        if (abs(puntos[i].x - punto_medio.x) < minimo) {
            puntos_mitad[j] = puntos[i];
            j++;
        }
    // Ordenar y
    qsort(puntos_mitad, j, sizeof(Punto), compararY);

    minimo = encontrar_cercano_mitad(puntos_mitad, j, minimo);
    return minimo;
}

/* Busca la distancia mas corta de los puntos que se encuentren
*  a cierta distancia de un punto medio con relacion a los puntos
* ordenados por su coordenada y
*/
double encontrar_cercano_mitad(Punto puntos[], int fin, double min) {
    for (int i = 0; i < fin; i++)
        for (int j=i+1; j < fin && (puntos[j].y - puntos[i].y) < min; j++)
            if (distancia(puntos[i], puntos[j]) < min )
                min = distancia(puntos[i], puntos[j]);

    return min;
}
/*Calcula la distancia entre dos puntos*/
double distancia(Punto a, Punto b) {
    return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}
/*Devuelve el minimo entre dos numeros*/
double min(double x, double y) {
    if (x < y)
        return x;
    return y;
}
/*Funcion que se utiliza como auxiliar para ordenar en x*/
int compararX (const void * a, const void * b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
   return (p1->x - p2->x);
}
/*Funcion que se utiliza como auxiliar para ordenar en y*/
int compararY (const void * a, const void * b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
   return (p1->y - p2->y);
} 