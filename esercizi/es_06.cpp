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

    float num_min, num_max;
    cin >> num_min >> num_max;
    //leggivalido(num_min, num_max);
    cout << leggivalido(num_min, num_max);

    return 0;
}