#include<iostream>

using namespace std;


void Mnozenje(int Matrica[2][2], int M[2][2]);

void Snaga(int Matrica[2][2], int n);

int Fibonaci(int n){
    int Matrica[2][2] = {{1,1},{1,0}};
    if(n == 0) return 0;
    Snaga(Matrica, n-1);
    return Matrica[0][0];
  }

 void Snaga(int Matrica[2][2], int n)  {
    if( n == 0 || n == 1)
        return;
    int M[2][2] = {{1,1},{1,0}};

    Snaga(Matrica, n/2);
    Mnozenje(Matrica, Matrica);

    if( n%2 != 0 ) Mnozenje(Matrica, M);
  }

  void Mnozenje(int Matrica[2][2], int M[2][2])  {

    int x =  Matrica[0][0]*M[0][0] + Matrica[0][1]*M[1][0];
    int y =  Matrica[0][0]*M[0][1] + Matrica[0][1]*M[1][1];
    int z =  Matrica[1][0]*M[0][0] + Matrica[1][1]*M[1][0];
    int w =  Matrica[1][0]*M[0][1] + Matrica[1][1]*M[1][1];

    Matrica[0][0] = x;
    Matrica[0][1] = y;
    Matrica[1][0] = z;
    Matrica[1][1] = w;
  }


  int main(){
  cout<<Fibonaci(6)<<endl;

  return 0;
  }
