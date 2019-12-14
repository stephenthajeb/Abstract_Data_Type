/* File : listsirkuler.h */
//Stephen Thajeb 13518150
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

// #ifndef listlinier_H
// #define listlinier_H

// #include "boolean.h"

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
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* Notasi Akses */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P;

    P = (address) malloc (sizeof (ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P;
  
    if (!IsEmpty(L)) {
        P = First(L);
        while (Next(P) != First(L) && Info(P) != X) {
            P = Next(P);
        }
        if (Info(P) == X) {
            return P;
        } else {
            return Nil;
        }
    } else {
        return Nil;
    }
}

/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address temp;
    temp = Alokasi(X);
    if (temp != Nil){
        InsertFirst(L,temp);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address temp;
    temp = Alokasi(X);
    if (temp != Nil){
        InsertLast(L,temp);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
    address P;
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    if (IsEmpty(*L)){
        Next(P) = P;
    } else {
        address Q = First(*L);
        while (Next(Q) != First(*L)){ 
            Q = Next(Q);
        } // Q address elemen terakhir
        Next(P) = First(*L);
        Next(Q) = P;
    }
     First(*L) = P;

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    address Q;
    
    if (IsEmpty(*L)){
        InsertFirst(L,P);
    } else {
        Q = First(*L);
        while (Next(Q) != First(*L)){
            Q = Next(Q);
        }//Q elemen terarkhir
        Next(Q) = P;
        Next(P) = First(*L);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    address Q;
    Q = First(*L);

    if (Next(Q) == First(*L)){ // hanya memiliki 1 elmene
        *P = First(*L);
        First(*L) = Nil;
    } else {
        while (Next(Q) != First(*L)){
            Q = Next(Q);
        }// Q adalah last elemen
        *P = First(*L);
        First(*L) = Next(First(*L));
        Next(Q) = First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    address Q;
    Q = First(*L);

    if (Next(Q) == First(*L)){
        DelFirst(L,P);
    } else {
        while (Next(Next(Q)) != First(*L)){
            Q = Next(Q);
        }// Q = 2 elmen terakhir
        *P = Next(Q);
        Next(Q) = First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
    address Q;
    address P;
    infotype temp;
    address adrtemp;

    Q = Search(*L,X);
    P = First(*L);

    if (Q != Nil){ //Q ada di L
        if (Next(P) == First(*L)){//hanya 1 Elemen
            if (Info(P) == X){
                First(*L) = Nil;
            }  
        } else {
            if (Info(P) == X){ // Untuk elemen pertama
                DelVFirst(L,&temp);
            } else {
                while (Next(P) != Q){
                    P = Next(P);
                }//  Next(P) == Q
                DelAfter(L,&adrtemp,P);
                Dealokasi(adrtemp); 
            }
        }      
    } 
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P;

    printf("[");
    if (! IsEmpty(L)){
        P = First(L);
        while(Next(P) != First(L)){
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
