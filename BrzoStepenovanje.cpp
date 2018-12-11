#include<iostream>


using namespace std;
int BrzoStepenovanje(int a, int n){
    if(n==0) return 1;
    if(n%2==0) return BrzoStepenovanje(a*a, n/2);
    else return a*BrzoStepenovanje(a*a,n/2);

}

int main(){
    cout<<BrzoStepenovanje(2,10);
return 0;
}
