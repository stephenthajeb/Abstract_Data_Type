//Nama:Stephen Thajeb
//Nim:13518150
//Tanggal:27 Agustus 2019
//Nama file :tigainteger.c
//Deskripsi  :menghitung jumlah deret
#include<stdio.h>

int main (){
    //Kamus
    int n,sum;

    //Algoritma
    scanf("%d",&n);
    sum = n*(2+(n-1))/2;
    printf("%d\n",sum);
    return 0;
}