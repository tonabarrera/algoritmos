#include <algorithm>
#include <stdio.h>
using namespace std;
/*
* Funcion que calcula el maximo de viajes por
* cada caso
*/
int greedy_viaje();

int main(int argc, char const *argv[]) {
    int T;
    // Captura del numero de casos
    scanf("%d", &T);
    // Calculo e impresion de los resultados
    for (int i=1; i<=T; i++) {
        printf("Case #%d: %d\n", i, greedy_viaje());
    }
    return 0;
}

int greedy_viaje() {
    int N;
    // Numero de viajes que se realizan
    int viajes = 0;
    // Captura del numero de objetos
    scanf("%d", &N);
    int objetos[N];
    // Capturamos el peso de los N objetos
    for (int i=0; i < N; i++)
        scanf("%d", &objetos[i]);
    // Ordenamos los numeros de menor a mayor
    sort(objetos, objetos+N);
    // Final del arreglo
    int final = N-1;
    // Peso de la bolsa
    int peso = 0;
    // Numero de objetos en la bolsa
    int num_objetos = 1;
    for (int inicio = -1; inicio < final;) {
        // Calcula el peso de la bolsa
        peso = objetos[final] * num_objetos;
        if (peso >= 50) {
            /*
            * Reiniciamos nuestros valores
            */
            peso = 0;
            num_objetos = 1;
            /*
            * Menos uno para tomar el siguiente objeto
            * mas pesado que queda por mover
            */
            final -= 1;
            /*
            * Sumamos un viaje
            */
            viajes += 1;
        } else {
            /*
            * Agregamos un objeto a la bolsa y nos
            * desplazamos en el arreglo de objetos
            * que faltan por llevar
            */
            num_objetos++;
            inicio++;
        }
    }
    // Regresamos el numero de viajes
    return viajes;
}