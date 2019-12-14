//Stephen Thajeb 13518150
//File : prioqueue.c
//3 Oktober 2019
#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

boolean IsEmpty (Queue Q){
	return (Head(Q)==Nil && Tail(Q)==Nil);
}

/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	return (NBElmt(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q){
	int x = Tail(Q)-Head(Q);
    if (x>0){
        return (x+1);
    } else {
        if (x==0){
            return 0;
        } else {
            return (x+MaxEl(Q)+1);
        }
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
	(*Q).T = (infotype*) malloc ((Max+1)*sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q)= Max;
        Head(*Q)=0;
        Tail(*Q)=0;
    } else {
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	free((*Q).T);
    MaxEl(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
    int j=Head(*Q);
    while ((j!=Tail(*Q) % MaxEl(*Q))+1) && (Prio(X)<=Prio(Elmt(*Q,j)))){
            j = (j % MaxEl(*Q))+1;
    }//j==Tail(*Q) or (Prior(X)>Prior(Elmt(*Q,i)))  peroleh indeks
    if (IsEmpty(*Q)){
        Head(*Q)     = 1;
        Tail(*Q)     = 1;
        InfoTail(*Q) = X;
    }else if (j==Tail(*Q)){
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) +1;
        InfoTail(*Q) = X;
    } else {//geser
        if (Tail(*Q) >= Head(*Q)){
            for (int k=Tail(*Q);k>=j;j--){
                Elmt(*Q,k+1) = Elmt(*Q,k); 
            }
            Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) +1;
        }
        else {//Tail(*Q) < Head(*Q)
            if (j == MaxEl(*Q)){
                for (int k=Tail(*Q);k>=1;k--){
                    Elmt(*Q,k+1) = Elmt(*Q,k);
                }
            } else if (j>=Head(*Q) && j<MaxEl(*Q)){
                for (int k=Tail(*Q);k>=1;k--){
                    Elmt(*Q,k+1) = Elmt(*Q,k);
                }
                for (int l=MaxEl(*Q);l>=j;l--){
                    Elmt(*Q,(l % MaxEl(*Q))+1) = Elmt(*Q,l);
                }
            } else { // j >=1 && j <= Tail(*Q)
                for (int m=Tail(*Q);m>=j;m++){
                    Elmt(*Q,m+1) = Elmt(*Q,m);   
                }
            }
        }
    }
    Elmt(*Q,j) = X;     //penyisipan element 
}

/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (Queue * Q, infotype * X){
	*X = InfoHead(*Q);
    if (Tail(*Q)==Head(*Q)) { //Tail(*Q)=1 karena prekondisi tidak mungkin kosong
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) =(Head(*Q)%MaxEl(*Q)+1);
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintQueue (Queue Q){
	int i = Head(Q);
	if(! IsEmpty(Q)){
		while (i != Tail(Q)){
			printf("%d %d\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
			if (i != MaxEl(Q)){
				i++;
			} else {
				i =1;
			}
		}
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
