#include <iostream>
#include <cmath>
using namespace std;

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

int main(){
    int dim = 10;
    float arr[dim];   
    cout << "inserimento " << dim << " dati" << endl;
    for (int i = 0; i < dim; i ++){
        cin >> arr[i];
    }
    cout << endl<< media(arr, dim) << endl;
    cout << endl<< devstd(arr, dim) << endl;

    return 0;
}