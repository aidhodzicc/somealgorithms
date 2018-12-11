#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdlib.h>
using namespace std;

class Tacka{
public:
    int x;
    int y;
    Tacka(int a, int b){
        x=a;
        y=b;
    }
    Tacka(){
    x=0;
    y=0;
    }
    friend bool operator == (const Tacka &T1, const Tacka &T2){
        return (T1.x==T2.x && T1.y==T2.y);
    }
    friend bool operator !=(const Tacka &T1, const Tacka &T2){
        return (!(T1.x==T2.x && T1.y==T2.y));
    }
    friend ostream& operator<<(ostream& izlaz, const Tacka &T){
        izlaz<<"("<<T.x<<","<<T.y<<")";
        return izlaz;
    }
};
Tacka T0;
int orijentacija(Tacka t1, Tacka t2, Tacka t3){
    if((t2.y - t1.y)*(t3.x - t2.x)-(t2.x - t1.x)*(t3.y - t2.y)>0) return -1; //U smjeru kazaljke
    else if((t2.y-t1.y)*(t3.x-t2.x)-(t2.x-t1.x)*(t3.y-t2.y)<0) return 1; //suprotno
    else return 0; //kolinearne
}
void zamijeni(Tacka &a, Tacka &b){
    Tacka temp=a;
    a=b;
    b=temp;
}
Tacka Pocetna(vector<Tacka> T){
    int najmanja=T[0].y;
    int najmanji=0;
    for(int i(1);i<T.size();i++){
    if(T[i].y<najmanja || (T[i].y==najmanja && T[i].x<T[najmanji].x)){
       najmanja=T[i].y;
       najmanji=i;
       zamijeni(T[i],T[0]);
       }
    }
    return T[0];
}
Tacka Predzadnja(stack<Tacka> &T){
    Tacka T2=T.top();
    T.pop();
    Tacka predzadnja=T.top();
    T.push(T2);
    return predzadnja;
}
int udaljenost(Tacka t1, Tacka t2){
    return (t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y);
}
int usporedba(const void *vT1, const void *vT2){
    Tacka *T1= (Tacka*)vT1;
    Tacka *T2=(Tacka*)vT2;
    int o=orijentacija(T0,*T1,*T2);
    if(o==0){
        if (udaljenost(T0,*T1)>=udaljenost(T0,*T2)) return 1;
        else return -1;
    }
    if(o==-1) return 1;
    else return -1;

}
vector<Tacka> GrahamScan(vector<Tacka> tacke){
        T0=Pocetna(tacke);
        for(int i(0);i<tacke.size();i++){
            if(T0==tacke[i]) zamijeni(tacke[0],tacke[i]);
        }
        qsort(&tacke[1],tacke.size()-1, sizeof(Tacka),usporedba);
        int a(1);
        for(int i(1);i<tacke.size();i++){
            while(i<tacke.size()-1 && orijentacija(T0,tacke[i],tacke[i+1])==0) i++;
            tacke[a]=tacke[i];
            a++;
        }
    if(a<3){
        cout<<"Nedovoljno tacaka"<<endl;
        vector<Tacka> nesto;
        nesto.push_back({0,0});
        return nesto;
    }
    stack<Tacka> T;
    T.push(tacke[0]);
    T.push(tacke[1]);
    T.push(tacke[2]);
    for(int i(3);i<a;i++){
        while(orijentacija(Predzadnja(T),T.top(),tacke[i])!=1)
            T.pop();
            T.push(tacke[i]);

    }
    vector<Tacka> vraca;
    while(!T.empty()){
        Tacka neka=T.top();
        vraca.push_back(neka);
        T.pop();
    }
    reverse(vraca.begin(),vraca.end());
    return vraca;
}
int orijentacija1(const Tacka& a, const Tacka& b, const Tacka& c){
		double prod = (a.x * (b.y-c.y) + b.x * (c.y-a.y) + c.x * (a.y-b.y));

		if(prod>0)
			return -1;
		else if(prod<0)
			return 1;
		else
			return 0;
	}
Tacka BinarnaPretraga(const vector<Tacka> &konacno,const Tacka &a){
    int n=konacno.size();
    int prvo=0;
    int prvo_prije=orijentacija1(a,konacno[prvo],konacno[n-1]);
    int prvo_poslije=orijentacija1(a,konacno[prvo],konacno[(prvo+1)%n]);
    int r=konacno.size();
    while(prvo<r){
        int varijabla=(prvo+r)/2;
        int varijabla_prije=orijentacija1(a,konacno[varijabla],konacno[(varijabla-1)%n]);
        int varijabla_poslije=orijentacija1(a,konacno[varijabla],konacno[(varijabla+1)%n]);
        int varijabla1=orijentacija1(a,konacno[prvo],konacno[varijabla]);
        if(varijabla_prije==0 && varijabla_poslije==0) return konacno[(varijabla+1)%n];
        else if(varijabla_prije!=1 && varijabla_poslije!=1) return konacno[varijabla];
        else if((varijabla1==-1 && prvo_prije==1)
            ||(varijabla1==1 && varijabla_poslije==1)
             ||(varijabla1==0 && varijabla_poslije==1)) prvo=varijabla+1;
        else
            r=varijabla;
        prvo_prije=orijentacija1(a,konacno[prvo],konacno[(prvo+n-1)%n]);
        prvo_poslije=orijentacija1(a,konacno[prvo],konacno[(prvo+1)%n]);


    }
    return konacno[prvo];
}
void Chan(vector<Tacka> T, int m){
    vector<Tacka> a;
    int granica=T.size()/m;
    int brojac(0);
    for(int i(0);i<granica;i++){
        vector<Tacka> b;
        for(int j(brojac);j<brojac+T.size()/granica;j++){
            b.push_back(T[j]);
        }
        vector<Tacka> c=GrahamScan(b);
        for(int i(0);i<c.size();i++){
            a.push_back(c[i]);
        }
        brojac+=T.size()/granica;
    }
    vector<Tacka>rjesenje;
    T0=Pocetna(a);
        for(int i(0);i<a.size();i++){
            if(T0==a[i]) zamijeni(a[0],a[i]);
        }
    qsort(&a[1],a.size()-1, sizeof(Tacka),usporedba);
    rjesenje.push_back(T0);
    for (int i(1);i<a.size();i++){
        if(BinarnaPretraga(a,rjesenje[i-1])!=T0){
            rjesenje.push_back(BinarnaPretraga(a,rjesenje[i-1]));
        }
        else break;
    }
    for(int i(0);i<rjesenje.size();i++){
        cout<<rjesenje[i]<<endl;
    }
}


int main(){
vector<Tacka> nesto= {{12, 1}, {11, 2}, {10, 9}, {7, 2},
                      {1, 5}, {3, 3}, {5, 1}, {5, 9},{11,13},{7,5},{2,2},{5,12}};
    vector<Tacka> Graham=GrahamScan(nesto);
    for(int i(0);i<Graham.size();i++){
        cout<<Graham[i]<<" ";
    }
    cout<<endl;
    Chan(nesto,4);
    /*T0=Pocetna(tacke);
        for(int i(0);i<tacke.size();i++){
            if(T0==tacke[i]) zamijeni(tacke[0],tacke[i]);
        }
    qsort(&tacke[1],tacke.size()-1, sizeof(Tacka),usporedba);
    for(int i(0);i<tacke.size();i++) cout<<tacke[i]<<" ";
    cout<<BinarnaPretraga(tacke,{5,1});
*/
return 0;
}
