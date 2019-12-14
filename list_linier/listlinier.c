//Stephen Thajeb 13518150
//listlinier.c
//Realisasi listlinier.c
//18 Oktober 2019

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

// #ifndef listlinier_H
// #define listlinier_H

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

// #define Nil NULL

// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist {
// 	infotype info;
// 	address next;
// } ElmtList;
// typedef struct {
// 	address First;
// } List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P;

    P = (address) malloc (sizeof (ElmtList));
    if (P == Nil){
        return P;
    } else {
        Info(P) = X;
        Next(P) = Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    /*Kamus Lokal*/
    address P;
    boolean found;

    /*Algoritma*/
    P = First(L);
    found = false;
    while(P != Nil && !found){
        
        if(Info(P)==X){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    return P;     
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P;

    P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P;
    if (IsEmpty(*L)){
        InsVFirst(L,X);
    } else {
        P = Alokasi (X);
        if (P != Nil){
            InsertLast(L,P);
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
   address P;

   DelFirst(L,&P);
   *X = Info(P);
   Dealokasi(&P);
}   
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P;

    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L)=P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address Last;

    Last = First(*L);
    if (Last == Nil){ //List kosong
        InsertFirst(L,P);
    } else { //List tidak kosong
        while (Next(Last)!=Nil){
            Last = Next(Last);
        }//Next(Last) == Nil
        InsertAfter(L,P,Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    address P;
    boolean cek;
    infotype temp;
    
    cek = false;
    P = First(*L);
    if (P != Nil){ //list tidak kosong
        if (Next(P) == Nil){ // Hanya ada 1 elemen
            if (Info(P) == X){
                
                (L,&temp); // Hapus elemen pertama
            }
        } else {// banyak elemen
            if (Info(First(*L)) == X){ //ditemukan di elemen pertama
                DelVFirst(L,&temp);
            } else {//tidak ditemukan di elemen pertama
                while (( Next(P) != Nil) && (!cek)){
                    if (Info(Next(P)) != X){
                        P = Next(P);
                    } else { // Info(Next(P)) == X
                        cek = true;
                    }
                }// Next(P) == Nil or cek== true
                if (cek){
                    Next(P) = Next(Next(P));
                }
            }
            
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, address *P){
    address last, prec;

    /*Algoritma*/
    last = First(*L);
    prec = Nil; //tak terdefinisi
    
    while(Next(last) != Nil){
        prec = last;
        last = Next(last); 
    }
    *P = last;
    if(last != First(*L)){
        Next(prec) = Nil;
    } else {
        CreateEmpty(L);
    }  
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P;

    printf("[");
    if (! IsEmpty(L)){
        P = First(L);
        while(Next(P) != Nil){
            printf("%d,",Info(P));
            P = Next(P);
        } // Next(P) == Nil
        printf("%d",Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    address P;
    int counter = 0;

    P = First(L);
    while ( P != Nil){
        P = Next(P);
        counter +=1;
    }
    return (counter);
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    address P;
    infotype temp;
    P = First(L);
    temp = Info(First(L));

    while (P != Nil){
        if(temp < Info(P)){
            temp = Info(P);
        }
        P = Next(P);
    }
    return temp;
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST *****************/
void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    address Last;

    Last = First(*L1);

    // Pengisian dr L1 lalu L2
    if (IsEmpty(*L1)){ //L1 kosong maka hanya diisi L2
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        while (Next(Last) != Nil){
            Last = Next(Last);
        } //Last == Nil
        Next(Last) = First(*L2);
    }
    CreateEmpty(L2);
    CreateEmpty(L1);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

// #endif