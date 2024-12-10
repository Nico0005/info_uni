#include "libstatistica.h"

int main(){
    int dim = 0;
    float *v = new float [dim];
    ifstream file;
    file.open("/home/studenti/niccolo.orabona/lab02/LabInfo_2024_25/Laboratorio11/dati_int.dat");
    while (file >> v[dim]){
        dim ++;
    }    
    cout << dim << endl;
    for (int i = 0; i < dim; i ++){
        cout << v[i] << endl;
    }
    cout << media(v, dim) << endl << devstd(v, dim) << endl;
    delete []v;
    v = NULL;
    return 0;
}