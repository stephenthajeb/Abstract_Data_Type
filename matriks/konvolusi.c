/*Nama : Stephen Thajeb
 *NIM  : 13518150
 *File : konvolusi.c
 * Tanggal : 19 September 2019 
 * */


#include <stdio.h>
#include "matriks.h"
#include <stdlib.h>



int main () {
       
    MATRIKS M1,M2,M3;
    int row,col,k;
	int iB,jB;
    
    scanf("%d",&row);
    scanf("%d",&col);
    BacaMATRIKS(&M1,row,col);
    scanf("%d",&k);
    BacaMATRIKS(&M2,k,k);
	MakeMATRIKS(row,col,&M3);
    
	int ci=(GetLastIdxBrs(M2)+1)/2; //center
	int cj=(GetLastIdxKol(M2)+1)/2; //center
	
	for(int iC=1;iC<=GetLastIdxBrs(M1);iC++){ // pergantian baris C
		for(int jC=1;jC<=GetLastIdxKol(M1);jC++){ // pergantian kolom C
			for (int iA=1;iA<=GetLastIdxBrs(M1);iA++){ //pergantian baris A
				for (int jA=1;jA<=GetLastIdxKol(M1);jA++){ // pergantian kolom A
					iB = iA+(ci-iC);
					jB = jA+(cj-jC);
					if (IsIdxEff(M2,iB,jB)){
						Elmt(M3,iC,jC) += Elmt(M1,iA,jA) * Elmt(M2,iB,jB);
					}
				}
			}	
		}
	}
	
	TulisMATRIKS(M3);

	return 0;
    
}
