/* File: vector. */
// Nama : Stephen Thajeb
// NIM : 13518150
/* Tanggal: 28 Agustus 2019 */
/* Deskripsi: Body*/
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include "vector.h"
#include <stdio.h>
#include <math.h>


//Realisasi ADT Vector

//#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
//#define AbsisComponent(V) Absis(V)
//#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y){
     VECTOR V;
     AbsisComponent(V) = x;
     OrdinatComponent(V) = y;
     return(V);
}
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>",Absis(v),Ordinat(v));
}
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
    return (sqrt(pow(Absis(v),2) + pow(Ordinat(v),2)));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
VECTOR Add(VECTOR a, VECTOR b){
    VECTOR res;
    Absis(res)   = Absis(a) + Absis(b);
    Ordinat(res) = Ordinat(a) + Ordinat(b);
    return (res);  
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR res;
    Absis(res)   = Absis(a) - Absis(b);
    Ordinat(res) = Ordinat(a) - Ordinat(b);
    return (res);
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
float Dot(VECTOR a, VECTOR b){
    return (Absis(a)*Absis(b)+Ordinat(a)*Ordinat(b));
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
VECTOR Multiply(VECTOR v, float s){
    Absis(v) *= s;
    Ordinat(v) *=s;
    return (v);
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
