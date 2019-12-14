#include "listrek.h"
#include<stdio.h>
#include<stdlib.h>

// void MinMax(List L,infotype *Min,infotype *Max){
//     infotype tempMin,tempMax;

//     if(IsOneElmt(L)){
//         *Min = FirstElmt(L);
//         *Max = FirstElmt(L);
//     } else {
//         MinMax(Tail(L),&tempMin,&tempMax);
//         if (FirstElmt(L) > tempMin){
//             *Min = tempMin;
//         } else {
//             *Min = FirstElmt(L);
//         }
//         if (FirstElmt(L) < tempMax){
//             *Max = tempMax;
//         } else {
//             *Max = FirstElmt(L);
//         }
//     }
// }

// int ListCompare (List L1,List L2){
//     if (IsEmpty(L1) && IsEmpty(L2)){
//         return 0;
//     } else if (IsEmpty(L1) && (IsEmpty(L2)==0)){
//         return -1;
//     } else if ((IsEmpty(L1)==0) && IsEmpty(L2)){
//         return 1;
//     } else if (FirstElmt(L1) > FirstElmt(L2)){
//         return 1;
//     } else if (FirstElmt(L1) < FirstElmt(L2)){
//         return -1;
//     } else{
//         return 0+ListCompare(Tail(L1),Tail(L2));
//     }
// }

// void SplitOnX (List L,infotype X, List *L1, List *L2) {
// 	List La, Lb;
	
// 	if (IsEmpty(L)) {
// 		*L1= Nil;
// 		*L2= Nil;
// 	} else if (IsOneElmt(L)) {
// 		if (FirstElmt(L) < X) {
// 			*L1= Konso(FirstElmt(L), La);
// 			*L2= Nil;
// 		} else {
// 			*L2= Konso(FirstElmt(L), Lb);
// 			*L1= Nil;
// 		}
// 	} else {
// 		if (FirstElmt(L) < X) {
// 			*L1= Konso(FirstElmt(L), La);
// 		} else {
// 			*L2= Konso(FirstElmt(L), Lb);
// 		}
// 		SplitOnX(Tail(L), X, &La, &Lb);
// 	}
// }

// List CopyReverse (List L) {
// 	List L1;
	
// 	if (IsListEmpty(L)) {
// 		return Nil;
// 	} else {
// 		L1= Konsdot(CopyReverse(Tail(L)), FirstElmt(L));
// 		return L1;
// 	}
// } 

int main(){
    List L,L2,temp1,temp2;
    int compare;
    infotype min,max;
    infotype a,b,c,d,e;
    a= 4,b= 3,c= 1,d=5,e=4;
    
    L = Konso(a,L);
    L = Konso(b,L);
    L = Konso(c,L);
    L = Konso(d,L);
    L = Konso(e,L);
    MCopy(L,&L2);
    // L2 = KonsB(L2,a);
    PrintList(L);
    printf("====================\n");
    // PrintList(L2);
    // compare = ListCompare(L,L2);
    // printf("%d",compare);
    SplitOnX(L,a,&temp1,&temp2);
    printf("Hasil split");
    printf("\n");
    PrintList(temp1);
    printf("\n");
    PrintList(temp2);
    // PrintList(temp1);
    // PrintList(temp2);

    // MinMax(L,&min,&max);
    // printf("%d\n",max);
    // printf("%d\n",min);
    

    return 0;
}