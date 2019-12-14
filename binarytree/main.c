#include "bintree.h"
#include "listrek.h"
#include "mesinkar.h"
#include <stdio.h>

//Ini mengkonvert infotype yg bintree jadi char
void BuildTree (BinTree *P){
    ADV();
    if (CC==')'){//karakter kedua
        *P = Nil;
    } else {
        *P = Tree(CC,Nil,Nil);
        ADV();
        while (CC==' '){
            ADV();
            BuildTree(&Left(*P));
        }
        while (CC==' '){
            ADV();
            BuildTree(&Right(*P));
            ADV();
        }
    }
}

int main(){
    BinTree P;
    infotype X;
    infotype temp;

    START();
    BuildTree(&P);
    scanf("%d",&X);
    printf("%d\n",NbElmt(P));
    PrintPreorder(P);

    return 0;
}