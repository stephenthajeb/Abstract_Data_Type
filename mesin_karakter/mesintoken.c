//Stephen Thajeb 13518150
/* File: mesintoken.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesintoken.h"
#include "mesinkar.h"
#include <stdio.h>

boolean EndToken;
Token CToken;

void IgnoreBlank(){
		while ((CC != MARK) && (CC == BLANK)){
        ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN(){
	START();
    IgnoreBlank();
    if (CC==MARK){
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN(){
    IgnoreBlank();
    if (CC==MARK){
        EndToken = true;
    } else {
        SalinToken();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken(){
    int i =2;
    //CC adalah karakter pertama maka langsung di cek
        if((CC == '*') || (CC=='+') || (CC=='-') || (CC=='/')||(CC=='^')){
			CToken.tkn = CC;
			CToken.val = -1;
            ADV();
		} else { //bukan character operator
            CToken.tkn = 'b';
            CToken.val = CC-'0'; // i=1
            ADV();
            while ((CC != BLANK) && (CC !=MARK) && (i <= NMax)){
                CToken.val = (CToken.val * 10) + (CC-'0');
                ADV();
                i++;
            }
    }
}

    
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
