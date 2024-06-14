#include<iostream>
#include<math.h>
#define maxT 10



using namespace std;

void lerVetor(float vetor[], int tamanho) {
    cout << endl;
    for(int i=0;i<tamanho;i++) {
        cout <<"vetor("<<i<<"): ";
        cin >> vetor[i];
    }
}

void imprimir_mat(float mat[][maxT], int ordem){
    cout << endl;
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

float determinante_metodo_gauus(float mat[][maxT], int ordem){

    float submat[maxT][maxT];
    int i, j, k;
    float pivote1, pivote2;
    float det, aux;
    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            submat[i][j] = mat[i][j];
        }
    }
    for(i=0; i<ordem;i++){
        pivote1 = submat[i][i];
        for(j=i+1;j<ordem;j++){
            pivote2 = submat[j][i];
            aux = pivote2/pivote1;
            for(k=0;k<ordem;k++){
                submat[j][k] = submat[j][k] - (aux * submat[i][k]);
            }
        }
    }
    det = 1;
    for(i=0;i<ordem;i++){
        det *=submat[i][i];
    }

    return det;
}

int main(){

    int op;

    int tamanho = 0;

    do{
    cout << "Digite o numero da quantidade de elementos da matiz: ";
    cin >> tamanho;
    }while(tamanho > maxT);

    float mat[maxT][maxT];

    do {

        for(int i = 0; i<tamanho; i++) {
            cout << "\nLeitura do vetorV"<<(i+1);
            lerVetor(mat[i], tamanho);
        }

        float det = determinante_metodo_gauus(mat, tamanho);

        if(det != 0){
            float vetLI[tamanho];
            cout << "\nLeitura do vetor linear";
            lerVetor(vetLI,tamanho);
            float cA[maxT][maxT];
            for(int i=0;i<tamanho;i++){
                for(int j=0;j<tamanho;j++){
                    cA[i][j] = mat[j][i];
                }
            }
            cout << "passei da troca";
            imprimir_mat(cA, tamanho);

        }else{
            cout << "\nDeterminante e igual a zero os vetores nao formam base, sendo LD :(";
        }


        cout << "\nSair(0 = SIM): ";
        cin >> op;
    }while(op != 0);
    return 0;
}
