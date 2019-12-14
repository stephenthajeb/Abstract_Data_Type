#include <stdio.h>
#include "listsirkuler.h"

void DeleteRR (List *L, infotype TQ){
	address Last;
	if (! IsEmpty(*L)){
		DelLast(L,&Last);
		if (Info(Last) > TQ){
			Info(Last) -= TQ;
			InsertFirst(L,Last);
			printf("%d\n",TQ);	
		}else {
			printf("%d\n",Info(Last));
		}
	} else {
		printf("List kosong\n");
	}
}
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */

// int NbElmt(List L){
//     address P = First(L);
//     int counter = 0;

//     if (IsEmpty(L)){
//         return counter;
//     } else {
//         counter +=1; 
//     }

//     while (Next(P) != First(L)){
//         P = Next(P);
//         counter +=1;
//     }
// }

float Average (List L){
    float avg= 0;
    address P;
	float ctr = 0;

    P = First(L);

    if (IsEmpty (L)){
        return avg;
    } else {
        while (Next(P) != First(L)){
            avg += Info(P);
            P = Next(P);
			ctr +=1;
        }
        avg += Info(P);
		ctr +=1;
        return (avg/ctr);
    }
}
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */

int main (){
	int tq;
	char op;
	infotype t;
	List L;

	CreateEmpty(&L);
	scanf("%d",&tq);
	while (tq <= 0){
		scanf("%d",&tq);
	}
	scanf(" %c",&op);
	
	while (op != 'F'){
		if (op == 'A'){
			scanf("%d",&t);
			if (t > 0){
				InsVFirst(&L,t);
			}
		}else if (op =='D'){
			DeleteRR(&L,tq);
		}else {
			printf("Kode salah\n");
		}	
		scanf(" %c",&op);
	}
	if (IsEmpty(L)){
		printf("Proses selesai\n");
	} else {
		printf("%.2f\n",Average(L));
	}

	return 0;
}