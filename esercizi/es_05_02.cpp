#include <iostream>
using namespace std;

int main(){
    int v[10];
    int sent = 0;
    cin >> v[0];
    int cont = 1;
    int cont2 = 0;
    while (cont<10 && v[cont-1] != 0){
        cin >> v[cont];
        cont ++;
        cont2 ++;
    }
    cout << endl;
    cont = 0;
    while (cont<cont2+1){
        cout << v[cont];
        cont ++;
    }
    cout << endl;
    cont = cont2;
    while (cont>=0){
        cout << v[cont];
        cont --;
    }
    cout << endl;

    return 0;

}