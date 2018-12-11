#include<iostream>
#include<algorithm>

using namespace std;

int trojkanula(int niz[], int duzina){
    int indeks1, indeks2;
    int brojac(0);
    sort(niz, niz+duzina);
    for (int i=0; i<duzina-2; i++) {
        indeks1=i+1;
        indeks2=duzina-1;
        while(indeks1<indeks2){
            if(niz[i]+niz[indeks1]+niz[indeks2]==0){
                brojac++;
                indeks1++;
                indeks2--;
            }
            else if (niz[i]+niz[indeks1]+niz[indeks2]<0) indeks1++;
            else indeks2--;
        }
    }
    return brojac;
}
int main(){
    int niz[] = {0,3,1,-2,-3,2,-1};
    int duzina= sizeof(niz)/sizeof(niz[0]);
    cout<<"Broj trojki je "<<trojkanula(niz, duzina)<<endl;
    return 0;
}
