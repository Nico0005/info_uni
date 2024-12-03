#include <iostream>
using namespace std;

float leggivalido(float min, float max){
    float num;

    do{
        cin >> num;
    }
    while(num<min || num>max);

    return num;
}

int CaricaArrayRange(float arr[], int size, float min, float max){
    char scelta;
    int cont = 0;
    do{
        arr[cont] = leggivalido(min, max);
        cont ++;
        cout << endl << "scrivere y per continuare" << endl;
        cin >> scelta;
    }
    while (scelta == 'y' && cont < size);

    cout << endl;

    for (int i = 0; i < cont; i ++){
        cout << ' ' << arr[i];
    }

    cout << endl;

    return cont;
}

int main(){
    int dim = 10;
    float v[10];
    int cont = CaricaArrayRange(v,dim,-5,5);
    cout << cont;
    return 0;
}