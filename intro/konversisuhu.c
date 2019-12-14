//Nama:Stephen Thajeb
//Nim:13518150
//Tanggal:27 Agustus 2019
//Nama file :konversisuhu.c
//Deskripsi  :mengkonversi suhu dalam berbagai satuan
#include<stdio.h>

int main (){
    //Kamus
    float t;
    char  k;
    
    //Algoritma
    scanf("%f %c",&t,&k);
    if(k =='R'){
        t=4.0*t/5;
    } else if (k =='F'){
        t=(9.0/5*t)+32;
    } else {
        t=t+273.15;
    }
    printf("%.2f\n",t);
    return 0;
}