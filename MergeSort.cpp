#include<iostream>

using namespace std;
void Merge(int a[], int pocetak, int sredina, int kraj){
    int n1=sredina-pocetak+1;
    int n2=kraj-sredina;
    int niz1[n1+1];
    int niz2[n2+1];
    for(int i=0;i<n1;i++){
            niz1[i]=a[pocetak+i];

    }
    for(int j=0;j<n2;j++){
        niz2[j]=a[sredina+j+1];
    }
    niz1[n1+1]=1000000;
    niz2[n2+1]=1000000;
    int i=0;
    int j=0;
    for(int k=pocetak;k<=kraj;k++){
        if(niz1[i]<=niz2[j]){
            a[k]=niz1[i];
            i++;
        }
        else{
            a[k]=niz2[j];
            j++;
        }

    }

}

void MergeSort(int a[], int pocetak, int kraj){
    if(pocetak<kraj){
        int sredina=(pocetak+kraj)/2;
        MergeSort(a,pocetak, sredina);
        MergeSort(a, sredina+1,kraj);
        Merge(a, pocetak, sredina, kraj);
    }


}


int main(){
    int a[]={4,5,1,2,3};
    MergeSort(a,0,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

return 0;
}
