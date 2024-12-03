#include <iostream>
#include <fstream>
using namespace std;

int max(int v[], int dim){
    int Max = v[0];
    int index;
    for(int i = 0; i < dim; i ++){
        if(v[i] > Max){
            Max = v[i];
            index = i;
        }
    }
    cout << endl << "Max: " << Max <<" indice; " << index;
    return 0;
}

int min(int v[], int dim){
    int Min = v[0];
    int index;
    for(int i = 0; i < dim; i ++){
        if(v[i] < Min){
            Min = v[i];
            index = i;
        }
    }
    cout << endl << "Min: " << Min <<" indice; " << index;
    return 0;
}

int sortArr(int v[], int dim){
    ofstream file_of;
    int j = 0;
    file_of.open("dati_int_ord.dat");
    for(int i = 0; i < dim; i ++){
        v[dim-i] = max(v,dim - i);
    }

    file_of.open("dati_int_ord.dat");

    for (int i = 0; i < dim; i ++){
        file_of << v[j];
    }   

    file_of.close();

    return 0;
}

int main(){
    ifstream file;
    int dim = -1;
    int v[10];
    int a;
    file.open("dati_int.dat");
    if (file.fail()){
        return -1;
    }
    else {
        while(!file.eof()){
            dim++;
            file >> v[dim];
            cout << dim;
            
        }
    }
    file.close();

    cout << endl;

    for (int i = 0; i < dim; i ++){
        cout << ' ' << v[i];
    }

    max(v,dim);
    min(v,dim);
    sortArr(v,dim);

    return 0;
}