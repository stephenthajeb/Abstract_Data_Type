// Stephen Thajeb 13518150
//delNFromEnd.c

#include "listrek.h"
#include<stdio.h>
#include<stdlib.h>

List Hasil = Nil;
int sum = 0;
List Elmt(List L,int n,int k){
	if(IsEmpty(L)){
		return 1;
	}
	sum +=1;
	k += 1;
	Elmt(Tail(L),n,k);
	if ((sum+2-k)==n){
		Hasil = L;
	}
	if ((sum + 1-k)==n){
		Dealokasi(L);
		if (sum == n){
			L = Hasil;
			return 0;
		}
	}
	if ((sum-k)==n){
		SetNext(L,Hasil);
	}
}

List delNFromEnd(List L, int n){
	if(!Elmt(L,n,0)){
		return Hasil;
	} else {
		return L;
	}
}
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */