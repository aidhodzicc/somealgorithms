#include <iostream>

using namespace std;
void InsertionSort(int niz [], int duzina){
    int pomocna;
    for(int i=1; i<duzina;i++){
        int j=i;
        while(j>0 && niz[j]<niz[j-1]){
            pomocna=niz[j];
            niz[j]=niz[j-1];
            niz[j-1]=pomocna;
            j--;
            cout<<niz[j]<<j<<endl;
        }

    }
}


int main(){
    int niz[]={2,3,4,5,6,0,-2};
    InsertionSort(niz,7);
    for(int i=0;i<7;i++){
        cout<<niz[i]<<" ";
    }
return 0;}
