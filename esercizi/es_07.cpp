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

int main(){

    float num_min = -5, num_max = 5;
    float v[10];
    int cont = 0;
    char scelta;
    do{
        v[cont] = leggivalido(num_min, num_max);
        cont ++;
        cout << endl << "scrivere y per continuare" << endl;
        cin >> scelta;
    }
    while (scelta == 'y' && cont < 10);

    for (int i = 0; i < cont; i ++){
        cout << ' ' << v[i];
    }

    return 0;
}