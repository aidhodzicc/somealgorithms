#include<iostream>

using namespace std;

int BinarnaPretraga(int niz[], int pocetak, int kraj, int broj){
    while(pocetak<=kraj){
        int indeks=pocetak+(kraj-1)/2;
        if(niz[indeks]==broj) return indeks;
        if(niz[indeks]<broj) pocetak=indeks+1;
        else kraj=indeks-1;
    }
    return -1;
}


int main(){
    int niz[]={1,3,4,5,10,31,100};
    int broj=4;
    cout<<"Indeks trazenog broja je "<<BinarnaPretraga(niz,0,6,broj)<<endl;

return 0;
}
