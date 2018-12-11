#include<iostream>
#include<cmath>
using namespace std;


template<typename tip>
class Lista{


    struct Cvor{

        Cvor *prethodni;
        Cvor *sljedeci;

        tip vrijednost;

        Cvor(tip vrijednost,Cvor *prethodni = nullptr,Cvor *sljedeci = nullptr){
            this->vrijednost = vrijednost;
            this->prethodni = prethodni;
            this->sljedeci = sljedeci;
        }

    };

    Cvor *prvi;

public:

    Lista(){prvi = nullptr;}

    Lista(tip element);

    void DodajElementNaPocetak(tip element);

    void DodajElementNaMjesto(int mjesto,tip element);

    void IzbrisiCvor(int mjesto);

    void Ispisi();

    void Objedini(Lista l);

    int Velicina();

    Lista<tip> Prepolovi();
};

template<typename tip>
Lista<tip>::Lista(tip element){
    prvi = new Cvor(element);
}

template<typename tip>
void Lista<tip>::DodajElementNaPocetak(tip element){

    Cvor *novi = new Cvor(element,nullptr,prvi);
    if(prvi != nullptr)
        prvi->prethodni = novi;
    prvi = novi;
}

template<typename tip>
void Lista<tip>::DodajElementNaMjesto(int mjesto,tip element){

    if(mjesto == 0){
        DodajElementNaPocetak(element);
    }

    Cvor *trenutni = prvi;

    for(int i = 0; i < mjesto; i++){
        trenutni = trenutni->sljedeci;
    }

    Cvor *novi = new Cvor(element,trenutni->prethodni,trenutni);
    trenutni->prethodni->sljedeci = novi;
    trenutni->prethodni = novi;
}

template<typename tip>
void Lista<tip>::IzbrisiCvor(int mjesto){

    Cvor *trenutni = prvi;

    for(int i = 0; i < mjesto; i++){
        trenutni=trenutni->sljedeci;
    }
    if(trenutni->prethodni!=nullptr)
        trenutni->prethodni->sljedeci=trenutni->sljedeci;

    if(trenutni->sljedeci != nullptr)
        trenutni->sljedeci->prethodni=trenutni->prethodni;

    if(trenutni->prethodni==nullptr){
        prvi = trenutni->sljedeci;
    }
    delete trenutni;

}

template<typename tip>
void Lista<tip>::Ispisi(){

    Cvor *trenutni = prvi;

    while(trenutni != nullptr){
        cout << trenutni->vrijednost << " ";
        trenutni = trenutni->sljedeci;
    }
    cout << endl;

}

template<typename tip>
void Lista<tip>::Objedini(Lista l){

    Cvor *trenutniL = l.prvi;

    Cvor *trenutni = prvi;


    while(trenutni->sljedeci!=nullptr){
        trenutni=trenutni->sljedeci;
    }
    if(l.prvi!=nullptr){
        trenutni->sljedeci=l.prvi;
        l.prvi->prethodni=trenutni;
    }
    l.prvi=nullptr;
}
template<typename tip>
int Lista<tip>::Velicina(){
    Cvor *trenutni = prvi;
    int velicina=0;
    while(trenutni != nullptr){
        velicina++;
        trenutni=trenutni->sljedeci;
    }
    return velicina;
}
template<typename tip>
Lista<tip> Lista<tip>::Prepolovi(){
        Cvor *trenutni=prvi;
        int n(Velicina());
        Lista<tip> nekalista;
        for(int i=0;i<n/2;i++){
            nekalista.DodajElementNaPocetak(trenutni->vrijednost);
            IzbrisiCvor(0);
        }
        Lista<tip> obrnuta;
        trenutni=nekalista.prvi;
        while(trenutni!=nullptr){
            obrnuta.DodajElementNaPocetak(trenutni->vrijednost);
            trenutni=trenutni->sljedeci;
        }
        return obrnuta;
}

template<typename tip>

class KvadratnaLista{

    struct Cvor{
        Cvor *prethodni;
        Cvor *sljedeci;
        Lista<tip> vrijednost;

        Cvor(Lista<tip> vrijednost, Cvor *prethodni=nullptr,Cvor *sljedeci=nullptr){
            this->vrijednost=vrijednost;
            this->prethodni=prethodni;
            this->sljedeci=sljedeci;
        }
    };
    Cvor *prvi;
    void SrediListu();

public:
    KvadratnaLista();
    KvadratnaLista(tip element);
    void DodajElementNaPocetak(tip element);
    void DodajElementNaMjesto(tip element, int broj);
    void IzbrisiCvor(int broj);
    void DodajListuNaPocetak(Lista<tip>);
    void DodajListuNaMjesto(Lista<tip>, int broj);
    void IzbrisiListu(int broj);
    void Ispisi();
    int BrojElemenata();

};
template<typename tip>
KvadratnaLista<tip>::KvadratnaLista(){
    prvi=nullptr;
}
template<typename tip>
KvadratnaLista<tip>::KvadratnaLista(tip element){
    Lista<tip> lista;
    lista.DodajElementNaPocetak(element);
    prvi=new Cvor(lista);
}

template<typename tip>
    void KvadratnaLista<tip>::Ispisi(){
        Cvor* trenutni=prvi;
        while(trenutni!=nullptr){
            trenutni->vrijednost.Ispisi();
            trenutni=trenutni->sljedeci;
        }
        cout<<endl;
    }
template<typename tip>
    int KvadratnaLista<tip>::BrojElemenata(){
        Cvor* trenutni=prvi;
        int n=0;
        while(trenutni!=nullptr){
            n+=trenutni->vrijednost.Velicina();
            trenutni=trenutni->sljedeci;
        }
    return n;
    }
template<typename tip>
    void KvadratnaLista<tip>::DodajElementNaPocetak(tip element){
            if(prvi!=nullptr){
                prvi->vrijednost.DodajElementNaPocetak(element);
            }
            else{
                Lista<tip> lista;
                lista.DodajElementNaPocetak(element);
                prvi=new Cvor(lista, nullptr, nullptr);
            }
            SrediListu();
    }
template<typename tip>
    void KvadratnaLista<tip>::DodajElementNaMjesto(tip element, int broj){
            Cvor *trenutni=prvi;
            int suma=0;
            while(trenutni->sljedeci!=nullptr){
                if(broj>suma && broj<suma+trenutni->vrijednost.Velicina())
                    trenutni->vrijednost.DodajElementNaMjesto(suma+trenutni->vrijednost.Velicina()-broj, element);
                suma=suma+trenutni->vrijednost.Velicina();
                trenutni=trenutni->sljedeci;
            }
            SrediListu();
    }
template<typename tip>
    void KvadratnaLista<tip>::IzbrisiCvor(int broj){
        int velicina = BrojElemenata();
        Cvor *trenutni = prvi;
        int suma = 0;
        while(trenutni->sljedeci!=nullptr){
            if( broj>=suma && broj<(suma+trenutni->sljedeci->vrijednost.Velicina())){
                trenutni->vrijednost.IzbrisiCvor(suma+broj);
                SrediListu();
                return;
        }
        suma+=trenutni->vrijednost.Velicina();
        trenutni=trenutni->sljedeci;
        }
        if(broj>=suma && broj<velicina){
            trenutni->vrijednost.IzbrisiCvor(velicina-broj);

        SrediListu();
        }
    }
template<typename tip>
    void KvadratnaLista<tip>::DodajListuNaMjesto(Lista<tip> lista, int broj){
        if(broj==0){
         Cvor *novi = new Cvor(lista, nullptr, prvi);

        if(prvi != nullptr){
            prvi->prethodni=novi;
        }
        prvi=novi;
        return;
        }
        Cvor *trenutni=prvi;

        for(int i(0);i<broj;i++){
            trenutni=trenutni->sljedeci;
        }

    Cvor *novi=new Cvor(lista, trenutni->prethodni, trenutni);
    trenutni->prethodni->sljedeci=novi;
    trenutni->prethodni=novi;

    SrediListu();
}
template<typename tip>
    void KvadratnaLista<tip>::DodajListuNaPocetak(Lista<tip> lista){
            Cvor *novi=new Cvor(lista, nullptr,prvi);
            if(prvi!=nullptr){
                prvi->prethodni=novi;
            }
            prvi=novi;
            SrediListu();
}
template<typename tip>
    void KvadratnaLista<tip>::IzbrisiListu(int broj){
        Cvor *trenutni=prvi;
        if(trenutni==nullptr) return;
        for(int i(0);i<broj;i++)
            trenutni=trenutni->sljedeci;

        if(trenutni->prethodni!=nullptr)
            trenutni->prethodni->sljedeci=trenutni->sljedeci;

        if(trenutni->sljedeci!=nullptr)
            trenutni->sljedeci->prethodni=trenutni->prethodni;
        if(trenutni->prethodni==nullptr)
            prvi = trenutni->sljedeci;

        delete trenutni;
        SrediListu();
    }
template<typename tip>
    void KvadratnaLista<tip>::SrediListu(){
        Cvor *trenutni=prvi;
        int n(BrojElemenata());
        int i(0);
        while(trenutni!=nullptr){
            if(trenutni->vrijednost.Velicina()>2*sqrt(n)){
                Lista<tip> novalista=trenutni->vrijednost.Prepolovi();
                DodajListuNaMjesto(novalista,i);
        }
        else{
            trenutni=trenutni->sljedeci;
            i++;
        }

        }
        i=0;
        trenutni=prvi;
        while(trenutni->sljedeci!=nullptr){
            if(trenutni->vrijednost.Velicina()<(sqrt(n)/2) && trenutni->sljedeci->vrijednost.Velicina()<(sqrt(n)/2)){
                trenutni->vrijednost.Objedini(trenutni->sljedeci->vrijednost);
                IzbrisiListu(i+1);
            }
            else{ trenutni=trenutni->sljedeci;
                i++;
            }

        }
    }


int main(){
    KvadratnaLista<int> kvadratna;
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.Ispisi();
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.Ispisi();
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.DodajElementNaPocetak(1);
    kvadratna.Ispisi();
    kvadratna.IzbrisiListu(1);
    kvadratna.Ispisi();

return 0;
}
