/* File : listdp.h */
//Stephen Thajeb 13518150
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */



#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

// #ifndef listdp_H
// #define listdp_H

// #include "boolean.h"

// #define Nil NULL

// /* Definisi Type Data */
// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist {
// 	infotype info;
// 	address next;
// 	address prev;
// } ElmtList;
// typedef struct {
// 	address First;
// 	address Last;
// } List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define Prev(P) (P)->prev
// #define First(L) ((L).First)
// #define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return ((First(L) == Nil) && (Last(L) == Nil));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address temp = (address) malloc (sizeof(ElmtList));
    if (temp != Nil){
        Info(temp) = X;
        Next(temp) = Nil;
        Prev(temp) = Nil;
    }
    return temp;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P;
    P = First(L);
    boolean found;

    found = false;

    if (IsEmpty(L)){
        return Nil;
    } else {
        while (P != Nil && !found){ 
            if (Info(P) == X){
                found = true;
            } else {
                P = Next(P);
            }// P == Nil atau found == ture
        }
        return P;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
void DelVFirst (List *L, infotype *X){
    address P;
    /* ALGORITMA */
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
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
        Last(*L)  = P;
        First(*L) = P;
    } else {
        Prev(First(*L)) = P;
        Next(P) = First(*L);
        Prev(P) = Nil;
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Next(P) = Nil;
        Last(*L) = P; 
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    if (Prec == Last(*L)){
        InsertLast(L,P);
    } else {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Prev(P) = Prec;
        Next(Prec) = P;
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    
    if (Succ == First(*L)){
        InsertFirst(L,P);
    } else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Next(P) = Succ;
        Prev(Succ) = P;
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    // *P = First(*L);
	// if (First(*L) == Last(*L)) { //hanya 1 elemen
    //     Last(*L) = Nil;
	// } else {
    //     First(*L) = Next(First(*L));
    //     Prev(First(*L)) = Nil;
    //     Next(*P) = Nil;
	// }
        /* ALGORITMA */
    *P = First(*L);
    if (First(*L) == Last(*L)) {
        Last(*L) = Nil;
    } else {
        Prev(Next(First(*L))) = Nil;
    }
    First(*L) = Next(First(*L));
    Prev(*P) = Nil;
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    // *P = Last(*L);
	// if (First(*L) == Last(*L)) {//hanya 1 elemen
	// 	DelFirst(L,P);
	// } else {
	// 	Last(*L) = Prev(Last(*L));
    //     Next(Last(*L)) = Nil;
    //     Prev(*P) = Nil;
	// }
    *P = Last(*L);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
    } else {
        Next(Prev(Last(*L))) = Nil;
    }
    Last(*L) = Prev(Last(*L));
    Next(*P) = Nil;
    Prev(*P) = Nil;
}   
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
    address Q;
    address P;
    infotype temp;

    Q = Search(*L,X);
    P = First(*L);

    if (Q != Nil){ //Q ada di L
        if (P == Q){ 
            DelVFirst(L,&temp);
        } else {
            while (Next(P) != Q){
                P = Next(P);
            }//  Next(P) == Q
            Next(P) = Next(Q);
            if (Next(Q) == Nil){//Q elemen terakhir
                DelVLast(L,&temp);
            } else {
                // Prev(Next(Q)) = P;
                Prev(Next(Q)) = Prev(Q);
                Dealokasi(Q);
            }
        }               
    } 
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    // *Pdel = Next(Prec);
    // if (Next(Next(Prec)) != Nil) {
    //     Next(Prec) = Next(Next(Prec));
    //     Prev(Next(Next(Prec))) = Prec;
    // } else { // Prec adalah 2 elemen terakhir, setetelah didelete menjadi elemen terakhir
    //     Last(*L) = Prec;
    //     Next(Prec) = Nil;
    // }
    if (Next(Prec) == Last(*L)){
        DelLast(L,Pdel);
    } else {    
        *Pdel = Next(Prec); 
        Next(Prec) = Next(Next(Prec));
        Prev(Next(Prec)) = Prec;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    // *Pdel = Prev(Succ);
    // if (Prev(Prev(Succ)) != Nil) {
    //     Prev(Succ) = Prev(Prev(Succ));
    //     Next(Prev((Prev(Succ)))) = Succ;
    // } else { // Prec adalah 2 elemen terawal, setelah didelete Prec menjadi First
    //     First(*L) = Succ;
    //     Prev(Succ) = Nil;
    // }
    if (Prev(Succ) == First(*L)){
        DelFirst(L,Pdel);
    } else {    
        *Pdel = Prev(Succ);
        Prev(Succ) = Prev(Prev(Succ)) ;
        Next(Prev(Succ)) = Succ;
    }
    
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    address P;
    printf("[");
    if (! IsEmpty(L)){
        P = First(L);
        while(Next(P) != Nil){
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
    address P;
    printf("[");
    if (! IsEmpty(L)){
        P = Last(L);
        while(Prev(P) != Nil){
            printf("%d,",Info(P));
            P = Prev(P);
        }
        printf("%d",Info(P));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
