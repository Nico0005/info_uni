
/*Programma MergeSort*/

#include <iostream>

#include <cstring>

#include <cmath>

#include <fstream>

using namespace std;

void merge(float a[],int low,int mid,int high){


    int h,i,j,k;
    float *b; 
    h=low; 
    i=0; 
    j=mid+1; 

    b = new float[high-low+1];


    while((h<=mid)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++; 
        }
        i++; //
    }

    if(h>mid){ 
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){ 
            b[i]=a[k];
            i++;
        }
    }

    i=0;
    memcpy ( (void *)  (a + low), (const void *) b, (high-low+1)*sizeof(int));


    delete [] b;
    b= NULL;
}

int pos_min(float v[],int low, int high){
    float min = v[low];
    float pmin = low;

    for(int i = low+1; i<=high; i++){
        if(v[i]< min){
            min = v[i];
            pmin = i;
        }
    }

    return pmin;   

}



void scambia(float *pa, float *pb){
    float appo;
    appo = *pa;
    *pa = *pb;
    *pb = appo;
}

void merge_sort(float a[],int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2; 
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


void sel_sort(float v[], int dim ){

    int pos;
    
    for(int i=0; i<dim-1; i++){
        pos = pos_min(v,i,dim-1);
        scambia(v+i,v+pos);
    }

}


int main()
{
    int num ,i;

    
    float a[num];

    cout<<"********************************************************************************"<<endl;
    cout<<"                             MERGE SORT PROGRAM "<<endl;

    cout<<"******************************************************************* *************"<<endl;
    cout<<endl<<endl;
    cout<<"Please Enter THE NUMBER OF ELEMENTS you want to sort:"<<endl;
    cin>>num;
    cout<<endl;
    cout<<"Now, Please Enter the ( "<< num <<" ) numbers (ELEMENTS):"<<endl;
    for(i=0;i<num;i++){
        cin>>a[i] ;
    }
    
    merge_sort(a,0,num-1); 
    cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;

    cout<<endl;

    
    cout<<endl<<endl;

    for(i=0;i<num;i++)
        cout<<a[i]<< endl;

    cout<<endl<<endl<<endl<<endl;

    int cont2;
    cout << "numero di punti: "<<endl;
    cin >> cont2;
    float x[cont2], y[cont2], d[cont2];

    for (int i = 0; i < cont2; i ++){
        cout << "coordinata x del punto "<< i << endl;
        cin >> x[i];
        cout << "coordinata y del punto "<< i << endl;
        cin >> y[i];

        d[i] = sqrt(x[i]+y[i]);
    }

    merge_sort(d, 0, cont2-1);
    for(i=0;i<cont2;i++){
        cout<<d[i]<< endl;
    }

    ifstream file;
    file.open("/home/studenti/niccolo.orabona/lab02/LabInfo_2024_25/Laboratorio09/sfere.dat");
    if (file.fail()){
        return -1;
    }

    char c;
    int cont = 0;

    while(file >> c){
        cont ++;
    }

    char colore[cont];
    float v[cont];

    for (int i = 0; i < cont; i ++){
        file >> colore[i];
        v[i] = colore[i];
    }

    merge_sort(v, 0, cont-1);

    for(i=0;i<cont;i++){
        cout<<colore[i]<< endl;
    }

    for(i=0;i<cont;i++){
        cout<<v[i]<< endl;
    }

    return 0;

}
