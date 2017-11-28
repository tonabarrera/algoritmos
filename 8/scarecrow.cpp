#include <iostream>
using namespace std;
int greedy_scarecrow();
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    // Captura del numero de casos
    int T;
    cin >> T;
    int r;
    for (int i=1; i <= T; i++){
        r = greedy_scarecrow();
        // Impresion de resultados
        cout << "Case "<< i << ": " << r << "\n";
    }
}

int greedy_scarecrow() {
    int N;
    cin >> N;
    char campo[N];
    // Leemos la cadena en un arreglo
    for (int i=0; i < N; i++)
        cin >> campo[i];
    // Numero de espantapajaros necesarios
    int contador = 0;
    
    // Si decidimos tomar o no la casilla
    
    bool tomar = true;
    
    // Para contar si tomar la casilla o no
    
    int aux = 3;
    // Recorremos el arreglo
    for (int i = 0; i < N; i++) {
        // Si es un punto lo tomamos y esperamos 
        if (campo[i] == '.' && tomar){
            contador++;
            tomar = false;
            aux--;
        } else if (!tomar)
            aux--;
        /*
        * Si ya recorrimos tres casillas podemos
        * poner otro espantapajaros
        */
        if (aux == 0) {
            aux = 3;
            tomar = true;
        }
    }
    return contador;
}