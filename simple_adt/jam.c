/* File: jam.c */
// Nama : Stephen Thajeb
// NIM : 13518150
/* Deskripsi: Body*/
/* Tanggal: 28 Agustus 2019 */
/* Definisi ADT JAM */

#include "jam.h"
#include <stdio.h>
#include <math.h>

//Validator
boolean IsJAMValid (int H, int M, int S){
    return ((H >=0 && H <=23) && (M >=0 && M<=59) && (S >=0 && S<=59));
}

//Konstruktor
JAM MakeJAM (int HH, int MM, int SS){
    //Kamus
    JAM J;
    //Algoritma
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS; 
    return (J);
}

//Baca dan Tulis
void BacaJAM (JAM * J){
    //Kamus lokal
    int HH,MM,SS;
    //Algoritma
    scanf("%d %d %d",&HH,&MM,&SS);
    while (! IsJAMValid(HH,MM,SS)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d",&HH,&MM,&SS);
    }
    *J = MakeJAM(HH,MM,SS);    
}

void TulisJAM (JAM J){
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}
    
//Konversi Type
long JAMToDetik (JAM J){
    //kamus lokal
    long detik;
    //Algoritma
    detik = 3600*Hour(J)+60*Minute(J)+Second(J);
    return detik;
}

JAM DetikToJAM (long N){
    //kamus lokal
    long N1;
    JAM J;
    //Algoritma
    N         = N % 86400; //karena maksimum 86400
    Hour(J)   = N /3600;
    N1    = N % 3600;
    Minute(J) = N1 / 60;
    Second(J) = N1 % 60;

    return (J);
}


//Operasi Relational Type
boolean JEQ (JAM J1, JAM J2){
    return ((Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)));
}

boolean JNEQ (JAM J1, JAM J2){
    return (!((Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2))));
}

boolean JLT (JAM J1, JAM J2){
    return (JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2){
    return (JAMToDetik(J1) > JAMToDetik(J2));
}
//Operasi Aritmatika Type
JAM NextDetik (JAM J){
    //Kamus Lokal
    long N;
    //Algoritma
    N = JAMToDetik(J) +1;
    return (DetikToJAM(N));
}

JAM NextNDetik (JAM J, int N){
    N = JAMToDetik(J) + N;
    return (DetikToJAM(N));
}
    
JAM PrevDetik (JAM J){
    //Kamus lokal
    long temp=JAMToDetik(J);
    //Algoritma
    temp -= 1;
    if(temp<0){
        temp +=86400;
    }
    return (DetikToJAM(temp));
}

JAM PrevNDetik (JAM J, int N){
    //Kamus
    long temp=JAMToDetik(J);
    //Algo
    temp -= N;
    if(temp<0){
        temp +=86400;
    }
    return (DetikToJAM(temp));
}

long Durasi (JAM JAw, JAM JAkh){
    //Kamus Lokal
    long temp=JAMToDetik(JAkh);
    //Algoritma
    if (JAMToDetik(JAw) > JAMToDetik(JAkh)){
        temp = JAMToDetik(JAkh) + 86400 - JAMToDetik(JAw);   
    } else {
        temp = JAMToDetik(JAkh) - JAMToDetik(JAw);
    }
    return (temp);
}
