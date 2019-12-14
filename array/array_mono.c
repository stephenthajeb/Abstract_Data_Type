//Nama : Stephen Thajeb
//NIM : 13518150
//Tanggal : 5 September 2019
//Nama File : array_mono.c

#include <stdio.h>
#include "array.h"

int main () {
	TabInt T1,T2;
	int membesar =0,mengecil=0;

	BacaIsi (&T1);
	CopyTab(T1,&T2);
	
	for (int i=1;i<=Neff(T1);i++){
		for(int j=i+1;j<=Neff(T1);j++){
		    if (Elmt(T1,i) < Elmt(T2,j)){
				membesar +=1 ;
			} else if (Elmt(T1,i) > Elmt(T2,j)){
				mengecil +=1;
			}
		}
	}

	// printf("%d %d",membesar,mengecil);

	if ((membesar==mengecil)&&(membesar==0)){
		printf("Array monotonik statik\n");
	} else {
		if ((membesar>mengecil) && (mengecil ==0)){
			printf("Array monotonik tidak mengecil\n");	
		}
		else if ((membesar<mengecil) && (membesar ==0)){
			printf("Array monotonik tidak membesar\n");
		}
		else {
			printf("Array tidak monotonik\n");
		}
	}
}





