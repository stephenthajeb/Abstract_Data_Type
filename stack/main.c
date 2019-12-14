#include <stdio.h>
#include "stackt.h"
#include "mesintoken.h"

void Inverse(Stack *S){
    Stack S1,S2;
    infotype temp;
    
    CreateEmpty(&S1);
    CreateEmpty(&S2);

    while(! IsEmpty(*S)){
        // printf("%d\n",InfoTop(*S));
        Pop(S,&temp);
        Push(&S1,temp);
    }
    while(! IsEmpty(S1)){
        // printf("%d\n",InfoTop(S1));
        Pop(&S1,&temp);
        Push(&S2,temp);
    }
    while(! IsEmpty(S2)){
        // printf("%d\n",InfoTop(S2));
        Pop(&S2,&temp);
        Push(S,temp);
    }
}

void IsiStack(Stack *S){
    int n;
    infotype temp;
    printf("Masukkin jumlah elemen stack:");
    scanf("&d",n);
    for (int i=1;i<=n;i++){
        scanf("&d",temp);
        Push(S,temp);
    }
}

void InverseN(Stack *S,int N){
    infotype temp;
    Stack Stemp;
    CreateEmpty(&Stemp);
    for (int i=1;i<=N;i++){
        Pop(S,&temp);
        Push(&Stemp,temp);
    }
    Inverse(&Stemp);
    while(!IsEmpty(Stemp)){
        Pop(&Stemp,&temp);
        Push(S,temp);
    }
}

void TulisStack (Stack S){
    infotype temp;
    Stack S1;
    CreateEmpty(&S1);

    while (! IsEmpty(S)){
        Pop(&S,&temp);
        printf("%d ",temp);
        Push(&S1,temp);
    }
    while (!IsEmpty(S1)){
        Pop(&S1,&temp);
        Push(&S,temp);
    }
}

// void FilterStack (Stack *S){

// }

int main () {
    
    Stack S;
    infotype op1,op2;
    CreateEmpty(&S);
    IsiStack(&S);
    TulisStack(&S);
    InverseN(&S,3);

    // STARTTOKEN();
    //postfix
    // while (!EndToken){
    //     if(CToken.val > 0){ //operan
    //         Push(&S,CToken.val);
    //     }else{ //operator
    //         Pop(&S,&op2);
    //         Pop(&S,&op1);    
    //         printf("%d %c %d\n",op1,CToken.tkn,op2);
    //         if (CToken.tkn == '+'){
    //             op1 += op2;
    //         } else if (CToken.tkn == '*'){
    //             op1 *= op2;
    //         } else if (CToken.tkn =='-'){
    //             op1 -= op2;
    //         } else {
    //             op1 /=  op2;
    //         }
    //         Push(&S,op1);
    //     } 
    //     TulisStack(S);
    //     printf("\n");
    //     ADVTOKEN();
    // }
    // if (IsEmpty(S)){
    //     printf("Ekspresi kosong\n");
    // } else {
    //     printf("Hasil Ekspresi: %d\n",InfoTop(S));
    // }
    // return 0;

    //infix
    // char inst='#';

    // while (!EndToken){
    //     if (CToken.val >0){ //operan
    //         Push(&S,CToken.val);
    //         if (inst !='#'){
    //             Pop(&S,&op2);
    //             Pop(&S,&op1);
    //             printf("%d %c %d = ",op1,inst,op2);
    //             if (inst == '+'){
    //                 op1 +=op2;
    //             } else if (inst =='-'){
    //                 op1-=op2;
    //             } else if (inst =='*'){
    //                 op1*=op2;
    //             } else {
    //                 op1/=op2;
    //             }
    //             Push(&S,op1);
    //             inst = '#';
    //             TulisStack(S);
    //             printf("\n");
    //         }
    //     } else { //operator
    //         inst = CToken.tkn;    
    //     }
    //     ADVTOKEN();
    // }
}