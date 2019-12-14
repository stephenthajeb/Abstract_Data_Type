#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int maksel,Q,op,num,ukuran;
	TabInt T;
	
	scanf("%d",&maksel);
	
	MakeEmpty(&T,maksel);
	BacaIsi(&T);
	scanf("%d",&Q);
	
	for (int i=1;i<=Q;i++){
		scanf("%d",&op);
		if (op==1){
			if(Neff(T)==MaxEl(T)){
				printf("array sudah penuh\n");	
			} else {
				scanf("%d",&num);
				AddAsLastEl(&T,num);
				printf("%d",MaxEl(T));
				TulisIsiTab(T);
			}
		}else if (op==2){
			scanf("%d",&num);
			GrowTab(&T,num);
			printf("%d",MaxEl(T));
			TulisIsiTab(T);
		} else if (op==3){
			scanf("%d",&num);
			if(num > NbElmt(T)){
				printf("array terlalu kecil\n");
			} else {
				ShrinkTab(&T,num);
				printf("%d",MaxEl(T));
				TulisIsiTab(T);
			}
		} else { //op==4
			CompactTab(&T);
			TulisIsiTab(T);
		}
	
	}
	return 0;
}
