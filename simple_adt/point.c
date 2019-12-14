/* File: point.h */
// Nama : Stephen Thajeb
// NIM : 13518150
/* Tanggal: 28 Agustus 2019 */
/* Deskripsi: Body*/
/* *** Definisi ABSTRACT DATA TYPE POINT *** */


/* *** Notasi Akses: Selektor POINT *** */
#include "point.h"
#include <stdio.h>
#include <math.h>

//Konstruktor
POINT MakePOINT (float X, float Y){
    //Kamus Lokal
    POINT P;
    //Algo
    Absis(P)   = X;
    Ordinat(P) = Y;
    return (P);
}

//Baca dan tulis
void BacaPOINT (POINT * P){
    //Kamus Lokal
    float X,Y;
    //Algo
    scanf("%f %f",&X,&Y);
    *P = MakePOINT(X,Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

//Operator Relational
boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2))&&(Ordinat(P1)== Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
    return (!((Absis(P1) == Absis(P2))&&(Ordinat(P1)== Ordinat(P2))));
}

boolean IsOrigin (POINT P){
    return ((Absis(P)==0)&&(Ordinat(P)==0));
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P)==0);
}
    

boolean IsOnSbY (POINT P){
    return (Absis(P)==0);
}

int Kuadran (POINT P){
    if(Absis(P)>0){
        if(Ordinat(P)>0){
            return 1;
        }
        else{ // Ordinat(P)<0
            return 4;
        }
    } else { //Absis(P) < 0
        if(Ordinat(P)>0){
            return 2;
        } else { //Ordinat(P) < 0
             return 3;
        }
    }
}
    

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    Absis(P) = Absis(P) + 1;
    return (P);
}

POINT NextY (POINT P){
    Ordinat(P) = Ordinat(P) + 1;
    return (P);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P)   = Absis(P) + deltaX; 
    Ordinat(P) = Ordinat(P) + deltaY;
    return (P);
}

POINT MirrorOf (POINT P, boolean SbX){
    if(SbX){
        Ordinat(P) = -1*Ordinat(P); 
    } else{ //SbX bernilai false
        Absis(P)   = -1*Absis(P);
    }
    return (P);
}

float Jarak0 (POINT P){
    //Kamus lokal
    float X_sqr,Y_sqr;
    //Algo
    X_sqr = Absis(P)*Absis(P);
    Y_sqr = Ordinat(P)*Ordinat(P);
    return sqrt(X_sqr + Y_sqr);
}

float Panjang (POINT P1, POINT P2){
//spek diketahui titik p1 dan p2 yang bertipe data POINT , akan dicari panjang garis yang dibentuk 2 titik tersebut, 
//atau dengan kata lain jarak antara 2 titik tersebut, sehingga secara spec tidak menyangkut ADT garis

    //Kamus
    float delta_X,delta_XSqr,delta_Y,delta_YSqr;
    //Algo 
    delta_X    = Absis(P1) - Absis(P2);
    delta_XSqr = delta_X * delta_X;
    delta_Y    = Ordinat(P1) - Ordinat(P2);
    delta_YSqr = delta_Y * delta_Y;
    return (sqrt(delta_XSqr + delta_YSqr));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0; 
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if(SbX){
        Ordinat(*P) = -1*Ordinat(*P); 
    } else{ //SbX bernilai false
        Absis(*P)   = -1*Absis(*P);
    }
}

void Putar (POINT *P, float Sudut){
       //Kamus lokal
        float rad;
        //Algo
        rad = -1*(Sudut * 3.14159265) / 180;
        rad = rad; //searah jarum jam
        *P = MakePOINT((Absis(*P)*cos(rad)) - (Ordinat(*P)*sin(rad)),(Absis(*P)*sin(rad)) + (Ordinat(*P)*cos(rad)));
}
