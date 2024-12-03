#include <iostream>

using namespace std;

void scambia (int *p1, int *p2){
   int appo;
   appo = *p1;
   *p1=*p2;
   *p2=appo;
   cout << *p1<<  " " << *p2;
}  

void scambia_float (float *p1, float *p2){
   int appo;
   appo = *p1;
   *p1=*p2;
   *p2=appo;
   cout << *p1<<  " " << *p2;
} 

int min(int v[], int dim){
   int minimum = v[0], index, appo;

   for (int i = 0; i < dim; i ++){
      if(v[i] < minimum){
         minimum = v[i];
         index = i;
      }
   }
   return minimum;
}

void selection_sort(int v[], int dim){
   int n;
   for (int i = 0; i < dim; i ++){
      for (int j = i; j < dim; j ++){
         if (v[j] < v[i]){
            scambia(&v[j], &v[i]);
         }
      }
   }
   cout << endl;
}


int main(){

   int a, b;
   cin >>a >> b;

   scambia(&a,&b);
   int n, pMin;
   cin >> n;
   int *w = new int[n];
   cout << endl << "inserisci array " <<endl;
   for (int i = 0; i < n; i ++){
      cout << endl;
      cin >> w[i];
   }


   cout << endl << "ordino" << endl;

   selection_sort(w, n);

   for (int i = 0; i < n; i ++){
      cout << w[i] << endl;
   }

   delete []w;
   w = NULL;

   return 0;
}