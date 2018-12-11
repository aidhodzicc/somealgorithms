#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;


int main(){
    int niz[]={2,6,1,3,5,6};
    int duzina=sizeof(niz)/sizeof(niz[0]);
    for(int i(0);i<duzina;i++){
        if(niz[abs(niz[i])-1]>0){
                niz[abs(niz[i])-1]=-niz[abs(niz[i])-1];
        }
        else cout<<"Dupli "<<abs(niz[i])<<endl;
    }
    for(int i(0);i<duzina;i++){
        if(niz[i]>0) cout<<"Nedostajuci "<<i+1<<endl;
    }

    return 0;
}
