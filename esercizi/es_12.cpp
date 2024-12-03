#include <iostream>
#include <cmath>
using namespace std;

int findElArray(int v[], int used);

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
    findElArray(v, used);
    cout << endl;
    for(int i = 0; i < used; i ++){
        cout << ' ' << v[i];
    }
    cout << endl;

    if(used > 1){
        cout << "numero elementi rimanenti : ";
        return used;
    }
    else if(used == 1){
        return 0;
    }

    return -2;
}

int findElArray(int v[], int used){
    cout<< endl<< used;
    for (int i = 0; i < used; i ++){
        if(v[i]%2 == 0){
            deleteElSwap(v, used, i);
        }
    }
    return -1;
}

int main(){
    int used = 10;
    int dati[used] = {0,1,2,3,4,5,6,7,8,9};
    cout << findElArray(dati, used);
}