#include<iostream>

using namespace std;
struct cvor{
    int broj;
    cvor *sljedeci;
};
class lista{
    cvor *pocetak;
    cvor *kraj;

public:
    lista(){
        pocetak=NULL;
        kraj=NULL;
    }
    ~lista(){
        delete pocetak;
        delete kraj;
    }

    void napravicvor(int n){
      cvor *temp=new cvor;
      temp->broj=n;
      temp->sljedeci=NULL;
      if(pocetak==NULL){
        pocetak=temp;
        kraj=temp;
        temp=NULL;
      }
      else{
        kraj->sljedeci=temp;
        kraj=temp;
      }
    }
    void ispisi(){
    cvor *temp=new cvor;
    temp=pocetak;
    while(temp!=NULL){
      cout<<temp->broj<<"\t";
      temp=temp->sljedeci;
    }
    }
    void ubacinapocetak(int n){
        cvor *temp=new cvor;
        temp->broj=n;
        temp->sljedeci=pocetak;
        pocetak=temp;
    }
    void ubaci(int pozicija, int n){
    cvor *prethodni=new cvor;
    cvor *trenutni=new cvor;
    cvor *temp=new cvor;
    trenutni=pocetak;
    for(int i(1);i<pozicija;i++){
      prethodni=trenutni;
      trenutni=trenutni->sljedeci;
    }
    temp->broj=n;
    prethodni->sljedeci=temp;
    temp->sljedeci=trenutni;
    }
    void obrisiprvi(){
    cvor *temp=new cvor;
    temp=pocetak;
    pocetak=pocetak->sljedeci;
    delete temp;
    }
    void obrisi(int pozicija){
    cvor *trenutni=new cvor;
    cvor *prethodni=new cvor;
    trenutni=pocetak;
    for(int i(1);i<pozicija;i++)
    {
      prethodni=trenutni;
      trenutni=trenutni->sljedeci;
    }
    prethodni->sljedeci=trenutni->sljedeci;
  }

};
int main(){
    lista brojevi;
    for(int i(0);i<10;i++){
        brojevi.napravicvor(i+1);
    }
    brojevi.ispisi();
    brojevi.ubacinapocetak(100);
    cout<<endl;
    brojevi.ispisi();
    brojevi.obrisiprvi();
    cout<<endl;
    brojevi.ispisi();
    brojevi.obrisi(3);
    cout<<endl;
    brojevi.ispisi();
return 0;
}
