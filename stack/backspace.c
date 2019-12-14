//Stephen Thajeb 13518150
//File : backspace.c
//17 Oktober 2019

#include <stdio.h>
#include "stackt.h"
#include <math.h>

int main () {
	int n,m;	
	infotype temp,temp2;
	boolean cek;
	Stack A,B;
	int ctra=0;
	int ctrb=0;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	CreateEmpty(&A);
	for (int i=1;i<=n;i++){
		scanf("%d",&temp);
		if (temp != 0){
			Push(&A,temp);
			ctra +=1;
		} else {
			if (!IsEmpty(A)){
					Pop(&A,&temp);
					ctra -=1;
			}
		}
	}
	//~ printf("\n");
	
	CreateEmpty(&B);
	for (int i=1;i<=m;i++){
		scanf("%d",&temp);
		if (temp != 0){
			Push(&B,temp);
			ctrb += 1;
		} else {
			if (!IsEmpty(B)){
				Pop(&B,&temp);
				ctrb -=1;
			}
		}
	}
	//~ printf("\n");
	
	
	if (ctra != ctrb){
		cek = false;
	} else {
		cek = true;
		while (!IsEmpty(A) && cek){
			Pop(&A,&temp);
			Pop(&B,&temp2);
			if (temp != temp2){
				cek = false;
			} 
		}
	}
	if (cek){
		printf("Sama\n");
	} else {
		printf("Tidak sama\n");
	}
	
	
	return 0;
}
