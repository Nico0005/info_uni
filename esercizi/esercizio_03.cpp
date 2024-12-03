#include <iostream>
using namespace std;

int main(){
    int dim = 10;
    int vett[10];
    int cont = 0;

    for (int i = 0; i < dim; i ++){
        cin >> vett[i];
    }

    for (int i = 0; i < dim; i ++){
        cout << ' '<< vett[i];
    }
    

    return 0;
}