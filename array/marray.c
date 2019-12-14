//Nama : Stephen Thajeb
//NIM : 13518150
//Tanggal : 5 September 2019
//Nama File : marray.c
#include <stdio.h>
#include "array.h"

int main () {
	TabInt T;
	ElType X;
	int count=0;
	IdxType IdxMedian;

	BacaIsi (&T);
	scanf("%d",&X);
	TulisIsiTab (T);
	printf("\n");
	
	if(SearchB (T,X)){
		//cek jumlah kemunculan
		for (int i=1;i<=Neff(T);i++){
			if(Elmt(T,i) == X){
				count +=1;
			}
		}
		
		printf("%d\n",count);
		printf("%d\n",Search1 (T,X));
		
		InsSortAsc(&T); 
		//Kondisi sudah array sudah terurut membesar
		if(X==Elmt(T,Neff(T))){
			printf("maksimum\n");	
		}
		
		if (X==Elmt(T,IdxMin)){
			printf("minimum\n");
		}
		
		if (Neff(T) % 2 ==0){
			IdxMedian = (Neff(T))/2;
		} else {
			IdxMedian = (Neff(T)+1)/2;
		}
		if (X==Elmt(T,IdxMedian)){
			printf("median\n");
		}
		
	} else {
		printf("%d\n",count);
		printf("%d tidak ada\n",X);
		
	}
	return 0;
}
