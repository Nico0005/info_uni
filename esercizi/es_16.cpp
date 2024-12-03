/*Il file __dati_header.dat__, già usato in laboratori precedenti, è così formato:

- Il primo valore è un intero che indica il numero __N__ di dati (razionali, in singola precisione) che seguono. 
- __N__ dati (__float__).

Scrivere un programma che:

1. Una volta letto il numero __N__ di dati _allochi dinamicamente_ un vettore di __N__ elementi __float__. 

1. Carichi i dati presenti sul file in un array di __float__. 
2. Ordini l'array usando l'algoritmo __selectionSort__, ovvero quello che sposta prima in testa all'array l'elemento più piccolo, in seconda posizione il secondo elemento più piccolo ecc....
3. Determini il minimo, il massimo, la mediana, la media e la deviazione standard dei dati. Il calcolo di queste statistiche deve essere effettuato da una funzione __void calcolaStats
(float v[], int ndata, float *pmin, float *pmax, float *pmediana, float *pmedia, float *pstddev)__ che "restituisce" il valore delle statistiche richieste per _side-effect_.

I primi 3 e gli ultimi 3 valori dell'array ordinato, insieme a tutte le statistiche determinate al punto 3, devono essere stampati a video e REGISTRATI sul file __risultati.dat__.

ATTENZIONE: ricordatevi di rimuovere l'array allocato dinamicamente quando questo non serve più.
NOTA: potete (dovete) ricilare il codice scritto nei laboratori scorsi per il calcolo del massimo, minimo, media, deviazione standard orinamento e mediana di un vettore di dati __float__.*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void scambia_float (float *p1, float *p2){
   float appo;
   appo = *p1;
   *p1=*p2;
   *p2=appo;
} 

float min(float v[], int dim){
   float minimum = v[0], index, appo;

   for (int i = 0; i < dim; i ++){
      if(v[i] < minimum){
         minimum = v[i];
         index = i;
      }
   }
   return minimum;
}

float max(float v[], int dim){
   float maximum = v[0], index, appo;

   for (int i = 0; i < dim; i ++){
      if(v[i] > maximum){
        maximum = v[i];
        index = i;
      }
   }
   return maximum;
}

float media(float v[], int dim){
    float somma = 0;

    for (int i = 0; i < dim; i ++){
        somma += v[i];
    }
    return (somma/dim);
}

float mediana (float v[], int index){
    return v[index];
}

float devstd(float v[], int ndati){

    float dev = 0;

    for (int i = 0; i < ndati; i ++){
        dev = dev + sqrt(pow(v[i]-media(v, ndati), 2)/ndati);
    }
    return dev;
}

void selection_sort(float v[], int dim){
   for (int i = 0; i < dim; i ++){
      for (int j = i; j < dim; j ++){
         if (v[j] < v[i]){
            scambia_float(&v[j], &v[i]);
         }
      }
   }
   cout << endl;
}

void calcolaStats (float v[], int ndata, float *pmin, float *pmax, float *pmedia, float *pstddev, float *pmediana){
    cout << endl << *pmax << endl << *pmin << endl << *pmedia << endl << *pstddev << endl << *pmediana << endl;
}

int main(){
    ifstream file;
    file.open("/home/studenti/niccolo.orabona/lab02/LabInfo_2024_25/Laboratorio08/dati_header.dat");
    int n;
    file >> n;

    float *v, inizial[3], final[3]; 
    v = new float[n];

    for (int i = 0; i < n; i ++){
        file >> v[i];
    }

    cout << endl;

    for (int i = 0; i < n; i ++){
        cout << v[i] << endl;
    }    

    cout << endl << "ordino" << endl;

    selection_sort(v, n);

    for (int i = 0; i < n; i ++){
        cout << v[i] << endl;
    } 

    final[0] = v[n-2];
    final[1] = v[n-1];
    final[2] = v[n]; 

    float mins = min(v, 3), maxs = max(v, 3), medias = media(v, 3), dev = devstd(v, 3), medianas = mediana(v, 2);

    calcolaStats(v, 3, &mins, &maxs, &medias, &dev, &medianas);

    mins = min(final, 3), maxs = max(final, 3), medias = media(final, 3), dev = devstd(final, 3), medianas = mediana(final, 2);

    calcolaStats(v, 3, &mins, &maxs, &medias, &dev, &medianas);
    delete []v;
    v = NULL;
}