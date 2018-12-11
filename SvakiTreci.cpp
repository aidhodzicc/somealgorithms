#include<iostream>


using namespace std;

class KruznaLista{

public:

    struct Cvor{
        int element;
        Cvor *sljedeci;
        Cvor(int element){
            this->element = element;
        }
        Cvor(int element,Cvor *sljedeci){
            this->element = element;
            this->sljedeci = sljedeci;
        }
    };
    Cvor *glavaListe;
    KruznaLista(){glavaListe = 0;}
    void DodajIza(Cvor *c,int element);
    void IzbrisiIza(Cvor *c);


};

void KruznaLista::DodajIza(Cvor *c,int element){
    if(c == 0){
        Cvor *novi = new Cvor(element);
        novi->sljedeci = novi;
        glavaListe = novi;
        return;
    }
    Cvor *novi = new Cvor(element,c->sljedeci);
    c->sljedeci = novi;

}

void KruznaLista::IzbrisiIza(Cvor *c){
    if(glavaListe == glavaListe->sljedeci){
        delete glavaListe;
        glavaListe = 0;
    }
    if(c->sljedeci == glavaListe){
        glavaListe = glavaListe->sljedeci;
    }
    Cvor *zaBrisanje = c->sljedeci;
    c->sljedeci = c->sljedeci->sljedeci;
    delete zaBrisanje;

}


int Prezivljava(int a,int b){

    KruznaLista *kl = new KruznaLista();

    kl->DodajIza(0,a);

    for(int i = a-1; i >= 1; i--){
        kl->DodajIza(kl->glavaListe,i);
    }
    KruznaLista::Cvor *trenutni = kl->glavaListe;
    for(int i = 0; i < a-1; i++){
        for(int j = 0; j < b-1; j++){
            trenutni = trenutni->sljedeci;
        }
        kl->IzbrisiIza(trenutni);
    }
    return kl->glavaListe->element;
}

int main(){

    int a,b;
    cin>>a>>b;
    cout<<"Prezivljava "<<Prezivljava(a,b)<<endl;

    return 0;

}
