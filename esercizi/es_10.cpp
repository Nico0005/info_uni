#include <iostream>
#include <cmath>
using namespace std;

int findElArray(int v[], int used, int val){
    for (int i = 0; i < used; i ++){
        if(v[i] == val){
            return i;
        }
    }
    return -1;
}

int main(){
    int val, used;
    cout << "inserire il valore da trovare e lunghezza array"<< endl;
    cin >> val >> used;
    int v[used];

    for (int i = 0; i < used; i ++){
        cout << "inserire elemento "<< i << endl; 
        cin >> v[i];
    }

    cout << endl << findElArray(v, used, val);
}