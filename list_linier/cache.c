//Stephen Thajeb 13518150
//cache.c
//driver listlinier.c
//18 Oktober 2019

#include <stdio.h>
#include "listlinier.h"

boolean isExist (List L, infotype X){
    address P;
    P = First(L);
    
    while (P != Nil){
        if (Info(P) == X){
            return true;
        } else {
            P = Next(P);
        }
    }
    return false;
}

int main (){
	int N;
	List L;
	int nop;
	infotype op;
	infotype del;


	scanf("%d",&N);
	scanf("%d",&nop);

	CreateEmpty(&L);
	for (infotype i =1;i<=N;i++){
		InsVLast(&L,i);
	}

	for (int j = 1;j<=nop;j++){
		scanf("%d",&op);
		if (isExist(L,op)){
			DelP(&L,op);
			InsVFirst(&L,op);
			printf("hit ");
			PrintInfo(L);
		} else {
			DelVLast(&L,&del);
			InsVFirst(&L,op);
			printf("miss ");
			PrintInfo(L);
		}
		printf("\n");
	}
	return 0;
}

// 6 5 4 6 7 5 5 