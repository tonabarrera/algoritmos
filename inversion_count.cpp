#include <iostream>
using namespace std;

struct Nodo {
    long int valor;
    struct Nodo *izq;
    struct Nodo *der;
    long long int hijos;
};

void insertar(struct Nodo **, long int);
void crear_arbol(struct Nodo **, long int);

long long int numero_inversiones = 0;

long long int obtener_inversiones();

int main() {
    int pruebas;
    int i;
    scanf("%d", &pruebas);
    //printf("\n");
    char c;
    scanf("%c", &c);
    long long int resultados[pruebas];
    for (i = 0; i < pruebas; i++) {
        resultados[i] = obtener_inversiones();
        scanf("%c", &c);
    }
    scanf("%c", &c);
    for (i = 0; i < pruebas; i++)
        printf("%lld\n", resultados[i]);
    return 0;
}

long long int obtener_inversiones() {
    numero_inversiones = 0;
    long int n;
    scanf("%ld", &n);
    long int dato;
    struct Nodo *arbol = NULL;
    for (long int i = 0; i < n; i++) {
        scanf("%ld", &dato);
        insertar(&arbol, dato);
    }
    return numero_inversiones;
}


void insertar(struct Nodo **arbol, long int dato) {
    if (*arbol == NULL) {
        crear_arbol(arbol, dato);
    } else if (dato <= ((*arbol)->valor)){
        ++numero_inversiones;
        numero_inversiones += (*arbol)->hijos;
        insertar(&((*arbol)->izq), dato);
    } else{
        insertar(&((*arbol)->der), dato);
        (*arbol)->hijos = (*arbol)->hijos + 1;
    }
}

void crear_arbol(struct Nodo **nuevo, long int dato) {
    (*nuevo) = (struct Nodo*)malloc(sizeof(struct Nodo));

    (*nuevo)->izq = NULL;
    (*nuevo)->der = NULL;
    (*nuevo)->hijos = 0;
    (*nuevo)->valor = dato;
}