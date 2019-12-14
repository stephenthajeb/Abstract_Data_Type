//Nama:Stephen Thajeb
//Nim:13518150
//Tanggal:27 Agustus 2019
//Nama file :maksimum.c
//Deskripsi  :mencari maksimum dari 3 bilangan
#include<stdio.h>

int main (){
    //Kamus
    int a,b,c;

    //Algoritma
    scanf("%d %d %d",&a,&b,&c);
    if ((a>=b) && (a>=c)){
        printf("%d\n",a);
    } else if ((b>=a) && (b>=c)){
        printf("%d\n",b);
    } else {
        printf("%d\n",c);
    }
    return 0;
}