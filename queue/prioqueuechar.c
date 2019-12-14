//Stephen Thajeb 13518150
//File : prioqueue.c
//3 Oktober 2019
#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

boolean IsEmpty (PrioQueueChar Q){
	return (Head(Q)==Nil && Tail(Q)==Nil);
}

/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
	return (NBElmt(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (PrioQueueChar Q){
	/*Algoritma*/
	if(IsEmpty(Q)){
		return 0;
	}
	else{
		if(Tail(Q)<Head(Q)){
			return (MaxEl(Q) - (Head(Q) - Tail(Q)) + 1);
		}
		else{
			return (Tail(Q)-Head(Q)+1);
		}
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max){
	(*Q).T = ( infotype* ) malloc ((Max + 1)* sizeof(infotype));
    if((*Q).T == NULL){
        MaxEl(*Q) = 0;
    }
    else{
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
	free((*Q).T);
    MaxEl(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    } else { //not isEmpty
        int j = Head(*Q);
        int temp = Tail(*Q) % MaxEl(*Q);
        while (j != temp + 1 && Prio(X)>=Prio(Elmt(*Q,j))){
            j = (j % MaxEl(*Q)) + 1;
        } // found index position to insert
        // printf("%d\n",j);
        if (j == temp +1){
            Tail (*Q) = temp + 1;
        } else if (j == Tail(*Q)){
                Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
                Elmt(*Q,Tail(*Q)) = Elmt(*Q,j);
        }else {
            int k = Tail (*Q);
            while (k != j){
                if (k != MaxEl(*Q)){
                    Elmt(*Q,(k%MaxEl(*Q))+1) = Elmt(*Q,k%MaxEl(*Q));
                } else { // k == MaxEl
                    Elmt(*Q,(k%MaxEl(*Q))+1) = Elmt(*Q,k);
                }
                k--;
                if (k < 1){ 
                    k = MaxEl(*Q);
                }
            }
            Tail (*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
        }
        Elmt(*Q,(j % MaxEl(*Q))+1)= Elmt(*Q,j);
        Elmt(*Q,j) = X;
    }
}

/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (PrioQueueChar * Q, infotype * X){
	InfoHead(*Q) = *X ;
    if (Tail(*Q)==Head(*Q)) { //Tail(*Q)=1 karena prekondisi tidak mungkin kosong
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) =(Head(*Q) % MaxEl(*Q)) +1;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
	int i = Head(Q);
	if(! IsEmpty(Q)){
		while (i != Tail(Q)){
			printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
            i = (i % MaxEl(Q))+1;
        }
        printf("%d %c\n",Prio(Elmt(Q,Tail(Q))),Info(Elmt(Q,Tail(Q))));
	}
	printf("#\n");
}

/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
