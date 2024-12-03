
/*# Esercizio 1
Il file __interi.dat__  contiene un numero non precisato di interi positivi. Scrivere una funzione 

__int * caricaInteriFile(char nomefile[], int& quanti)__

preso in ingresso il nome del file, carichi in un vettore di interi allocato dinamicamente i dati registrati sul file. 
La funzione deve restituire l'idirizzo dell'array allocato dinamicamente (__int *__) e il numero di interi caricati (ovvero la dimensione del vettore) 
per _side effect_, ovvero registrando il numero dei dati in __quanti__. In caso di errore di apertura dello stream la funzione  dovrà restituire 
il valore __NULL__ e registrare -1 in quanti. In caso di errore di allocazione dinamica dell'array, la funzione dovrà restituire ancora __NULL__ e registrare il valore -2 in __quanti__.

NOTA: il parametro attuale assegnato al parametro formale __quanti__ dovrà essere una variabile (di tipo __int__) della funzione chiamante  (ad esempio __main__). 
Se nella funzione usate __quanti__ direttamente come contatore, sinceratevi di aver fatto l'opportuna inizializzazione a zero del contatore....*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int * caricaInteriFile(const char nomefile[], int& quanti){
    ifstream file;
    int cont = 0;
    file.open(nomefile);
    if(file.fail()){
        return NULL;
        quanti = -1;
    }
    while(!file.eof()){
        cont ++;
        cout << cont << ' ';
    }
    int *v;
    v = new int[quanti];
    for (int i = 0; i<quanti; i ++){
        file >> v[i];
    }
    for (int i = 0; i < quanti; i ++){
        cout << v[i] << endl;
    }
    cout << v;
    return v;
}

int main(){
    int quanti;
    caricaInteriFile("/home/studenti/niccolo.orabona/lab02/LabInfo_2024_25/Laboratorio09/interi.dat", quanti);
    return 0;
}