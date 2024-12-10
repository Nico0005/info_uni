#include "libstatistica.h"

float media(float v[], int ndati){
    float somma = 0;
    for (int i = 0; i < ndati; i ++){
        somma = somma + v[i];
    }
    float med = somma/ndati;
    return med;
}

float devstd(float v[], int ndati){

    float dev = 0;

    for (int i = 0; i < ndati; i ++){
        dev = dev + sqrt(pow(v[i]-media(v, ndati), 2)/ndati);
    }
    return dev;
}

float max(const char file_name[], float n){
    ifstream file;
    file.open(file_name);
    int cont = 0;
    while (file >> cont){
        cont ++;
    }
    int v[cont];
    int i = 0;
    while (file >> v[i]){
        file >> v[i];
        i ++;
    }


    float maximum = v[0];

    for (int j = 0; j < cont; j ++){
        if (v[j] > maximum){
            maximum = v[i];
        }
    }
    return maximum;
}

float min(const char file_name[], float n){
    ifstream file;
    file.open(file_name);
    int cont = 0;
    while (file >> cont){
        cont ++;
    }
    int v[cont];
    int i = 0;
    while (file >> v[i]){
        file >> v[i];
        i ++;
    }


    float minimum = v[0];

    for (int j = 0; j < cont; j ++){
        if (v[j] < minimum){
            minimum = v[i];
        }
    }
    return minimum;
}