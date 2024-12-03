#include <iostream>
using namespace std;

int main()
{
    int a[5]={5,4,2,3,1};
    for(int i=0;i<4;i++)
    {
        int posizioneminimo=i;
        for(int j=i+1;j<5;j++)
        {
            if(a[posizioneminimo]>a[j])
            {
                posizioneminimo=j;
            }
        }
        int temp=a[i];
        a[i]=a[posizioneminimo];
        a[posizioneminimo]=temp;
        
        for(int j=0;j<5;j++)
        {cout<<a[j]<<" ";}
        cout<<endl;
    }
}rn 0; 
} 
