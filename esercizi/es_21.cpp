/*# Esercizio 2

Scrivere una funzione 

__int *selezionaDispari(int dati[], int ndati, int& nodd)__ 

che, preso in ingresso un vettore __dati__ di interi e il numero di dati presenti nel vettore, crei dinamicamente un nuovo vettore di interi che contiene 
solo i numeri dispari in __dati__ e restituisca:

-il vettore contenente i primi (__int *__) e la sua dimensione (ovvero il numero di interi dispari in __dati__) usando il riferimento  __int& nprimi__.
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int *selezionaDispari(int dati[], int ndati, int& nodd){
    int cont = 0;
    int *v = new int[nodd];
    for (int i = 0; i < ndati; i ++){
        if(dati[i]%2 != 0){
            cont ++;
            v[i] = dati[i];
        }
    }
    nodd = cont;
    for (int i = 0; i < cont; i ++){
        cout << v[i] << endl;
    }
    delete []v;
    v = NULL;
    return &nodd;
}

int main(){
    int dim, v[dim], nodd;
    cin >> dim;
    for (int i = 0; i < dim; i ++){
        cin >> v[i];
    }
    selezionaDispari(v, dim, nodd);
}