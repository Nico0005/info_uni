/*Il file __data.dat__ contiene, riga per riga, un numero non precisato di valori razionali in singola precisione. Scrivere una funzione 

__int contaDati(const char nomefile[])__

che, ricevuto in ingresso il nome di un file come "stringa" (ovvero array di caratteri), restituisca il numero di dati presenti su file o -1 se si incontra qualche condizione di errore.

Verificato il corretto funzionamento della funzione, scrivere un programma che, contati gli _n_ dati presenti sul file __data.dat__ in un vettore di _n_ __float__ creato dinamicamente. 

Fatto questo, scrivete una funzione

__float * contaCaricaDati(const char nomefile[], int *p_ndati)__

che:
1. Riceve in ingresso un nome di file (vettore di caratteri).
2. Conta il numero di valori presenti su file; per far questo potete usare la funzione __contaDati__ definita qui sopra.
3. Alloca dinamicamente un vettore di dimensione pari al numero di dati e carica i dati da file nel vettore.
4. Restituisce l'indirizzo del vettore creato dinamicamente e, per side effect, il numero di dati caricati tramite il puntatore __p_ndati__.

Se la funzione dovesse incontrare problemi con l'apertura dello stream e/o con l'allocazione del vettore, dovrà restituire il valore __NULL__ e il valore -1 per i dati caricati. 
Sarà eventualmente responsabilità del programma/funzione chiamante gestire la situazione di "errore"

NOTA: la funzione __contaCaricaDati__ dovrà leggere il file 2 volte! La prima per contare il numero di dati e quindi allocare l'array della dimensione giusta; la seconda per 
caricare effettivamente i dati nel vettore. Tra le due letture sarà necessario "riavvolgere" lo stream su file, in modo tale che la lettura inizi dal primo dato e che eventuali 
flags di stato vengano resettati. I file __resetStream1.C__ e __resetStream2.C__ esemplificano due modi alternativi, ma equivalenti, di fare questa operazione.*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int contaDati(const char nomefile[]){
    int cont = 0;
    ifstream file;
    file.open(nomefile);
    if(!file.is_open()){
        return -1;
    }
    while (!file.eof()){
        cont++;
    }
    return cont;
}

int main(){
    cout << contaDati("/home/studenti/niccolo.orabona/lab02/LabInfo_2024_25/Laboratorio08/data.dat");
    return 0;
}