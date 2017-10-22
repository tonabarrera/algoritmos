#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
struct Punto {
    float x;
    float y;
};

float encontrar_cercano(Punto [], int, int);
float encontrar_cercano_mitad(Punto [], int, int);
float min(float, float);
float distancia(Punto, Punto);
int compararX (const void *, const void *);
int compararY (const void *, const void *);
float cercano(Punto [], int, int);

int main(int argc, char const *argv[]) {
    int n;
    string s;
    getline(cin, s);
    n = atoi(s.c_str());
    Punto puntos[n];

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        istringstream is(str);
        float k;

        is >> k;
        puntos[i].x = k;

        is >> k;
        puntos[i].y = k;
    }

    for (int i = 0; i < n; i++)
        printf("%f %f", puntos[i].x, puntos[i].y);

    // ordenar puntos
    qsort(puntos, n, sizeof(Punto), compararX);

    float punto_cercano = encontrar_cercano(puntos, 0, n-1);
    printf("%.3f\n", punto_cercano);
    return 0;
}

float cercano(Punto P[], int inicio, int fin) {
    float min = distancia(P[inicio], P[inicio+1]);
    for (int i = inicio; i < fin; ++i)
        for (int j = i+1; j <= fin; ++j){
            if (distancia(P[i], P[j]) < min){
                min = distancia(P[i], P[j]);
            }
        }

    return min;
}

float encontrar_cercano(Punto puntos[], int inicio, int fin) {
    if ((fin - inicio) <=3)
        return cercano(puntos, inicio, fin);
    int mitad = (fin + inicio)/2;
    Punto punto_medio = puntos[mitad];


    float cercano_izq = encontrar_cercano(puntos, inicio, mitad);
    float cercano_der = encontrar_cercano(puntos, mitad+1, fin);
    float minimo = min(cercano_izq, cercano_der);
    Punto puntos_mitad[fin+1];
    int j = 0;
    for (int i = inicio; i < fin; i++)
        if (abs(puntos[i].x - punto_medio.x) < minimo) {
            puntos_mitad[j] = puntos[i];
            j++;
        }
    // Ordenar y
    qsort(puntos_mitad, j, sizeof(Punto), compararY);

    float minimo_mitad = encontrar_cercano_mitad(puntos_mitad, j, minimo);
    return minimo_mitad;
}

float encontrar_cercano_mitad(Punto puntos[], int fin, int min) {
    for (int i = 0; i < fin; i++)
        for (int j=i+1; j <= fin && (puntos[j].y - puntos[i].y) < min; j++)
            if (distancia(puntos[i], puntos[j]) < min )
                min = distancia(puntos[i], puntos[j]);

    return min;
}

float distancia(Punto a, Punto b) {
    return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}

float min(float x, float y) {
    if (x < y)
        return x;
    return y;
}

int compararX (const void * a, const void * b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
   return (p1->x - p2->x);
}

int compararY (const void * a, const void * b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
   return (p1->y - p2->y);
} 