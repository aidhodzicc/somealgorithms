#include<iostream>

using namespace std;
int BrojInverzija(int niz[], int duzina);
int Spoji(int niz1[], int duzina1, int niz2[], int size2, int pomocni[]);

int BrojInverzija(int niz[],int duzina){
    if(duzina==1) return 0;
    else{
    int sredina = duzina/2;
    int brojac1 = BrojInverzija(niz,sredina);
    int brojac2=BrojInverzija(niz+sredina,duzina-sredina);
    int pomocni[duzina];
    int brojac3=Spoji(niz,sredina,niz+sredina,duzina-sredina,pomocni);
    for(int i=0;i<duzina;i++){
        niz[i]=pomocni[i];
    }
    return brojac1+brojac2+brojac3;
    }

}

int Spoji(int niz1[],int duzina1,int niz2[],int duzina2,int pomocni[])
{
    int brojac=0, a=0, b=0, c=0;
    while(a<duzina1 && b<duzina2)
    {
        if(niz1[a]<niz2[b]){
            pomocni[c]=niz1[a];
            c++;
            a++;
        }
        else{
            pomocni[c] = niz2[b];
            b++;
            c++;
            brojac=brojac+duzina1-a;
        }
    }

    while(a<duzina1){
        pomocni[c]=niz1[a];
        c++;
        a++;
    }
    while(b<duzina2) {
        pomocni[c]=niz2[b];
        c++;
        b++;
    }
    return brojac;
}
int main()
{
    int niz[]={1,4,100,3,5,0};
    cout<<BrojInverzija(niz,6)<<endl;
}
