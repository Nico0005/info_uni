#include <iostream>
using namespace std;

int main(){
    int v[10];
    int sent = 0;
    cin >> v[0];
    int cont = 0;
    for (int i = 1; i < 10 && v[i-1] != sent; i ++){
        cin >> v[i];
        cont ++;
    }

    for (int i = 0; i < cont; i ++){
        cout << " " << v[i];
    }
    cout << endl;

    for (int i = cont-1; i >= 0 ; i --){
        cout << " " << v[i];
    }
    cout << endl;

    return 0;
}