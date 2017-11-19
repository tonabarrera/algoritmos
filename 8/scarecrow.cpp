#include <iostream>
using namespace std;
int greedy_scarecrow();
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int r;
    for (int i=1; i <= T; i++){
        r = greedy_scarecrow();
        cout << "Case "<<i << ": " << r << "\n";
    }
}

int greedy_scarecrow() {
    int N;
    cin >> N;
    char campo[N];
    for (int i=0; i < N; i++)
        cin >> campo[i];

    int contador = 0;
    bool tomar = true;
    int aux = 3;
    for (int i = 0; i < N; i++) {
        if (campo[i] == '.' && tomar){
            contador++;
            tomar = false;
            aux--;
        } else if (!tomar) {
            aux--;
        }
        if (aux == 0) {
            aux = 3;
            tomar = true;
        }

    }
    return contador;
}