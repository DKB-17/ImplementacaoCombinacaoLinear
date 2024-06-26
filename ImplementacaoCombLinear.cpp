#include<iostream>
#include<math.h>
#define maxT 10



using namespace std;

void lerVetor(double vetor[], int tamanho) {
    cout << endl;
    for(int i=0;i<tamanho;i++) {
        cout <<"vetor("<<i<<"): ";
        cin >> vetor[i];
    }
}

void imprimir_mat(double mat[][maxT], int ordem){
    cout << endl;
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

double determinante_metodo_gauus(double mat[][maxT], int ordem){

    cout << endl;
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            cout << mat[i][j] << "\t";
            if(j<(ordem-1)){
                cout << "|";
            }
        }
        cout << endl;
    }


    double submat[maxT][maxT];
    int i, j, k;
    double pivote1, pivote2;
    double det, aux;
    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            submat[i][j] = mat[i][j];

        }
    }
    double auxV[ordem];
    for(i=0; i<ordem;i++){
        pivote1 = submat[i][i];
        if(pivote1 == 0){
            for(int j=0;j<ordem;j++){
                auxV[j] = submat[i][j];
                submat[i][j] = submat[i+1][j];
                submat[i+1][j] = auxV[j];
            }
            pivote1 = submat[i][i];
        }
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

    cout << endl;
    for(int i=0;i<ordem;i++){
        for(int j=0;j<ordem;j++){
            cout << submat[i][j] << "\t";
            if(j<(ordem-1)){
                cout << "|";
            }
        }
        if(i<(ordem-1)){
            cout << endl;
        }else{
            cout << "\tDet: " << det;
        }
    }
    cout << endl;

    return det;
}

void calculaCombinacaoLinear(double matI[][maxT], double vetR[], int ordem, double solucao[]){
    double subMat[maxT][maxT];
    for(int j=0;j<ordem;j++){
        for(int k=0;k<ordem;k++){
                subMat[k][j] = matI[j][k];
        }
    }
    double detMI = determinante_metodo_gauus(subMat,ordem);
    for(int i= 0; i<ordem;i++){
        double mtAux[maxT][maxT];
        for(int j=0;j<ordem;j++){
            for(int k=0;k<ordem;k++){
                    mtAux[k][j] = matI[j][k];
            }
        }
        for(int j=0;j<ordem;j++){
            mtAux[j][i] = vetR[j];
        }
        double detL = determinante_metodo_gauus(mtAux,ordem);

        solucao[i] = detL/detMI ;
    }
}

int main(){

    int op;

    int tamanho = 0;

    double mat[maxT][maxT];

    do {

        do{
            cout << "Digite o numero da quantidade de elementos da matiz: ";
            cin >> tamanho;
        }while(tamanho > maxT);

        for(int i = 0; i<tamanho; i++) {
            cout << "\nLeitura do vetorV"<<(i+1);
            lerVetor(mat[i], tamanho);
        }

        double det = determinante_metodo_gauus(mat, tamanho);

        if(det != 0){
            double vetLI[tamanho];
            cout << "\nLeitura do vetor linear";
            lerVetor(vetLI,tamanho);
            double solucao[tamanho];
            calculaCombinacaoLinear(mat, vetLI, tamanho, solucao);
            cout << "\nSolucao: (";
            for(int i=0;i<tamanho;i++){
                cout << solucao[i];
                if(i<(tamanho-1)){
                    cout << "|";
                }
            }
            cout << ")";
        }else{
            cout << "\nDeterminante e igual a zero os vetores nao formam base, sendo LD :(";
        }


        cout << "\nSair(1 = SIM): ";
        cin >> op;
    }while(op != 1);
    return 0;
}
