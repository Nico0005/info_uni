#include <iostream>
#include <cmath>
using namespace std;

int deleteElSwap(int v[], int used, int pos){
    if(pos > used || pos < 0){
        cout << "errore" << endl;
        return -1;
    }
    for (int i = 0; i < used; i ++){
        if (i == pos){
            v[pos] = v[used-1];
            used --;
        }
    }
    cout << endl;
    for(int i = 0; i < used; i ++){
        cout << ' ' << v[i];
    }

    if(used > 1){
        cout << "numero elementi rimanenti : ";
        return used;
    }
    else if(used == 1){
        return 0;
    }

    return -2;
}

int main(){
    int used, pos;
    cout << "inserire numero poszioni arrray e numero dell'elemento da eliminare: " << endl;
    cin >> used >> pos;
    int v[used];
    for (int i = 0; i < used; i ++){
        cout << "inserire elemento "<< i << endl; 
        cin >> v[i];
    }

    cout << endl << deleteElSwap(v, used, pos);

    return 0;
}