#include <iostream>

using namespace std;

class Stablo{

    struct Cvor{

        int vrijednost;

        Cvor *lijevo_dijete;
        Cvor *desno_dijete;

        Cvor(int vr,Cvor *ld = nullptr,Cvor *dd = nullptr){
            vrijednost = vr;
            lijevo_dijete = ld;
            desno_dijete = dd;
        }

    };

    Cvor *korijen;

    void Dodaj(int element,Cvor *korijen);

    void Preorder(Cvor *korijen);

    void Inorder(Cvor *korijen);

    bool Trazi(int element,Cvor *korijen);

    Cvor* Izbrisi(int element,Cvor *korijen);

    int BrojElemenata(Cvor *korijen);

    int Visina(Cvor *korijen);

    bool Ispravno(Cvor *korijen);

public:

    Stablo(){korijen = nullptr;}

    void Dodaj(int element);

    void Preorder();

    void Inorder();

    bool Trazi(int element);

    void Izbrisi(int element);

    int BrojElemenata();

    int Visina();

    bool Ispravno();

};

void Stablo::Dodaj(int element){

    if(korijen != nullptr)
        Dodaj(element,korijen);
    else
        korijen = new Cvor(element);

}

void Stablo::Dodaj(int element,Cvor *korijen){

    if(element < korijen->vrijednost){
        if(korijen->lijevo_dijete != nullptr)
            Dodaj(element,korijen->lijevo_dijete);
        else{
            korijen->lijevo_dijete = new Cvor(element);
        }
    }else if(element > korijen->vrijednost){
        if(korijen->desno_dijete != nullptr)
            Dodaj(element,korijen->desno_dijete);
        else{
            korijen->desno_dijete = new Cvor(element);
        }
    }

}

void Stablo::Preorder(){

    Preorder(korijen);

}

void Stablo::Inorder(){

    Inorder(korijen);

}

void Stablo::Preorder(Cvor *korijen){

    if(korijen == nullptr){
        return;
    }

    cout << korijen->vrijednost << " ";

    Preorder(korijen->lijevo_dijete);

    Preorder(korijen->desno_dijete);

}

void Stablo::Inorder(Cvor *korijen){

    if(korijen == nullptr){
        return;
    }

    Inorder(korijen->lijevo_dijete);

    cout << korijen->vrijednost << " ";

    Inorder(korijen->desno_dijete);

}

bool Stablo::Trazi(int element){

    return Trazi(element,korijen);

}

bool Stablo::Trazi(int element,Cvor *korijen){

    if(korijen == nullptr){
        return false;
    }

    if(element == korijen->vrijednost){
        return true;
    }

    if(element < korijen->vrijednost){
        return Trazi(element,korijen->lijevo_dijete);
    }else{
        return Trazi(element,korijen->desno_dijete);
    }

}

void Stablo::Izbrisi(int element){

    korijen = Izbrisi(element,korijen);

}

Stablo::Cvor* Stablo::Izbrisi(int element,Cvor *korijen){

    if(korijen == nullptr){
        return korijen;
    }

    if(korijen->vrijednost == element){
        if(korijen->desno_dijete == nullptr && korijen->lijevo_dijete == nullptr){
            delete korijen;
            return nullptr;
        }
        if(korijen->desno_dijete != nullptr && korijen->lijevo_dijete == nullptr){
            Cvor *zaVracanje = korijen->desno_dijete;
            delete korijen;
            return zaVracanje;
        }
        if(korijen->desno_dijete == nullptr && korijen->lijevo_dijete != nullptr){
            Cvor *zaVracanje = korijen->lijevo_dijete;
            delete korijen;
            return zaVracanje;
        }
        if(korijen->desno_dijete != nullptr && korijen->lijevo_dijete != nullptr){
            Cvor *najmanjiDesno = korijen->desno_dijete;
            Cvor *roditeljNajmanjiDesno = korijen;
            while(najmanjiDesno->lijevo_dijete != nullptr){
                roditeljNajmanjiDesno = najmanjiDesno;
                najmanjiDesno = najmanjiDesno->lijevo_dijete;
            }
            int zamjena = korijen->vrijednost;
            korijen->vrijednost = najmanjiDesno->vrijednost;
            najmanjiDesno->vrijednost = zamjena;
            delete najmanjiDesno;
            if(roditeljNajmanjiDesno == korijen){
                roditeljNajmanjiDesno->desno_dijete = nullptr;
            }else{
                roditeljNajmanjiDesno->lijevo_dijete = nullptr;
            }
            return korijen;
        }
    }

    if(element < korijen->vrijednost){
        korijen->lijevo_dijete = Izbrisi(element,korijen->lijevo_dijete);
        return korijen;
    }else if(element > korijen->vrijednost){
        korijen->desno_dijete = Izbrisi(element,korijen->desno_dijete);
        return korijen;
    }

}

int Stablo::BrojElemenata(){

    return BrojElemenata(korijen);

}

int Stablo::BrojElemenata(Cvor *korijen){

    if(korijen == nullptr){
        return 0;
    }

    return BrojElemenata(korijen->lijevo_dijete) + BrojElemenata(korijen->desno_dijete) + 1;

}

int Stablo::Visina(){

    return Visina(korijen);

}

int Stablo::Visina(Cvor *korijen){

    if(korijen == nullptr){
        return -1;
    }

    return max(Visina(korijen->desno_dijete),Visina(korijen->lijevo_dijete)) + 1;

}

bool Stablo::Ispravno(){

    return Ispravno(korijen);

}

bool Stablo::Ispravno(Cvor *korijen){

    if(korijen == nullptr){
        return true;
    }

    if(!Ispravno(korijen->lijevo_dijete) || !Ispravno(korijen->desno_dijete)){
        return false;
    }

    Cvor *najmanjiDesno = korijen->desno_dijete;
    while(najmanjiDesno != nullptr && najmanjiDesno->lijevo_dijete != nullptr){
        najmanjiDesno = najmanjiDesno->lijevo_dijete;
    }

    Cvor *najveciLijevo = korijen->lijevo_dijete;
    while(najveciLijevo != nullptr && najveciLijevo->desno_dijete != nullptr){
        najveciLijevo = najveciLijevo->desno_dijete;
    }

    if((najmanjiDesno == nullptr || najmanjiDesno->vrijednost > korijen->vrijednost)
       && (najveciLijevo == nullptr || najveciLijevo->vrijednost < korijen->vrijednost))
        return true;

    return false;

}

int main(){

    Stablo s;

    s.Dodaj(31);
    s.Dodaj(18);
    s.Dodaj(55);
    s.Dodaj(16);
    s.Dodaj(22);
    s.Dodaj(44);
    s.Dodaj(7);
    s.Dodaj(19);


    s.Inorder();

    cout << endl;

    s.Dodaj(25);

    s.Inorder();

    cout << endl;

    cout << s.BrojElemenata() << endl;

    cout << "Visina: " << s.Visina() << endl;

    s.Izbrisi(31);

    s.Inorder();

    cout << endl;

    s.Izbrisi(16);

    s.Inorder();

    cout << endl;

    cout << s.BrojElemenata() << endl;

    s.Izbrisi(44);

    s.Inorder();

    cout << endl;


    s.Izbrisi(7);

    s.Inorder();

    cout << endl;

    s.Izbrisi(19);

    s.Inorder();

    cout << endl;

    s.Izbrisi(18);

    s.Inorder();

    cout << endl;

    s.Izbrisi(55);

    s.Inorder();

    cout << endl;

    if(s.Ispravno()){
        cout << "Ispravno" << endl;
    }else{
        cout << "Neispravno" << endl;
    }

}
