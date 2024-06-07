#include<iostream>
#include<math.h>

using namespace std;

void lerVetor(int vetor[], int tamanho) {
    cout << endl;
    for(int i=0;i<tamanho;i++) {
        cout <<"vetor("<<i<<"): ";
        cin >> vetor[i];
    }
}

bool verificaLI(int vetor1[], int vetor2[], int tamanho) {
    int det = 0;
        if(det != 0) {
            return true;
        }
    return false;
}

int main(){

    int op;

    int tamanho = 2;
    int matriz[tamanho][tamanho];

    do {

        for(int i = 0; i<tamanho; i++) {
            cout << "\nLeitura do vetorV"<<(i+1);
            lerVetor(matriz[i], tamanho);
        }

        cout << "\nSair(0 = SIM): ";
        cin >> op;
    }while(op != 0);
    return 0;
}